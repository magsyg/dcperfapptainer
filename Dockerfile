FROM ubuntu:22.04

RUN chmod 1777 /tmp
RUN apt-get update
RUN apt install -y python3-pip git wget lshw dmidecode sudo bc libavif-dev
RUN ulimit -n 65536

RUN mkdir /benchmarks
WORKDIR /benchmarks
COPY ./benchmarks /benchmarks
COPY ./benchpress /benchmarks
COPY ./packages /benchmarks
COPY ./perfutils /benchmarks
COPY ./benchpress_cli.py /benchmarks
COPY ./benchpress.log /benchmarks

RUN pip3 install click pyyaml tabulate pandas
RUN python3 benchpress_cli.py install video_transcode_bench_svt