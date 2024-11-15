#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# set -e

TEMPLATES_DIR="$(dirname "$(readlink -f "$0")")"
HHVM="/usr/local/hphpi/legacy/bin/hhvm"
MARIADB_PWD="password"

# 1. Install prerequisite packages
yum install -y libevent-devel zlib-devel
yum install -y php-common php-cli php-devel

# 3. Install nginx
cp packages/mediawiki/nginx.repo /etc/yum.repos.d/
yum-config-manager --enable nginx-mainline
yum install -y nginx
systemctl stop nginx

# 4. Install mariadb
yum install -y mariadb-server
systemctl start mariadb
if ! [ -x "$(command -v mysql)" ]; then
  echo >&2 "Could not install mariadb!"
  exit 1
fi

mysql -u root --password="$MARIADB_PWD" -e ";"
mysql_success=$?
if [ $mysql_success -ne 0 ]; then
  mysql -u root --password="" < "${TEMPLATES_DIR}/update_mariadb_pwd.sql"
fi

mysql -u root --password=$MARIADB_PWD < "${TEMPLATES_DIR}/grant_privileges.sql"

# 5. Install Siege
if ! [ -x "$(command -v siege)" ]; then
  git clone https://github.com/JoeDog/siege.git
  cd siege || { exit 1; }
  git checkout tags/v4.0.3rc3
  ./utils/bootstrap
  automake --add-missing
  ./configure
  make -j8
  make uninstall
  make install
  cd ..
fi

# Copy siege.conf
mkdir -p "$HOME/.siege"
cp "${TEMPLATES_DIR}/siege.conf" "$HOME/.siege/siege.conf"
chmod 644 "$HOME/.siege/siege.conf"

# 6. Install memcache
if ! [ -f memcached-1.5.12.tar.gz ]; then
  curl -O http://www.memcached.org/files/memcached-1.5.12.tar.gz
  tar -xzf memcached-1.5.12.tar.gz
  cd memcached-1.5.12 || { exit 1; }
  ./configure --prefix=/usr/local/memcached
  make -j8
  make install
  cd ..
fi

# 7. Installing OSS-performance
git clone https://github.com/hhvm/oss-performance.git
cd oss-performance || { exit 1; }

curl -O https://getcomposer.org/installer
mv installer composer-setup.php

php composer-setup.php
yes | $HHVM composer.phar install

# 8. Basic tuning
echo 1 | tee /proc/sys/net/ipv4/tcp_tw_reuse

# 9. MariaDB tuning
cp "${TEMPLATES_DIR}/my.cnf" "/etc/my.cnf"
systemctl restart mariadb
