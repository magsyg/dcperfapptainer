#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import logging
import os
import sys
import threading
import time

from benchpress.lib.hook import Hook

logger = logging.getLogger(__name__)


class TaoInstructionHook(Hook):
    """
    Prints the client side instructions generated by tao_bench_autoscale
    """

    def __init__(self):
        # Path to directory of benchpress_cli.py
        self.basepath = os.path.dirname(os.path.abspath(sys.argv[0]))

    def print_instructions(self):
        instruction_path = (
            self.basepath + "/benchmarks/tao_bench/client_instructions.txt"
        )
        while self.run_thread:
            time.sleep(1)
            if os.path.exists(instruction_path):
                break
        time.sleep(1)
        with open(instruction_path, "r") as f:
            instruction_text = f.read()
        logger.warning(instruction_text)
        os.remove(instruction_path)

    def before_job(self, opts, job):
        self.run_thread = True
        self.thread = threading.Thread(
            target=self.print_instructions, name="tao-instrux", args=()
        )
        self.thread.start()

    def after_job(self, opts, job):
        self.run_thread = False
        self.thread.join()