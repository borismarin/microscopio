# This file runs the benchmarks
# and plots a nice graph.

# Requires matplotlib

# turns out Python is actually nice xD

import matplotlib.pyplot as plt
import numpy as np
import math
import subprocess

def call_test(binary, buf_size):
    proc = subprocess.Popen([binary, str(buf_size), '1'],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT)
    stdout,_ = proc.communicate()
    return float(stdout)

def run_pass(binary, buf_size, tries=5):
    print("Running pass with buf_size =", buf_size)
    samples = map(lambda _: call_test(binary, buf_size), range(1, tries + 1))
    samples = list(samples)
    average = np.average(samples)
    error = np.std(samples)/math.sqrt(tries)
    plt.scatter(buf_size, average)
    plt.errorbar(buf_size, average, yerr=error)

def run_benchmark(binary, xs=range(1,11), title=''):
    list(map(lambda n: run_pass(binary, n), xs))
    plt.xlabel("Buffer Size (pixels)")
    plt.ylabel("Latency per pixel (ns/pixel)")
    plt.title(title)
    plt.show()

print("Running C pipes benchmark...")
run_benchmark('./pc-c-pipes/main', title='C + pthreads + pipe', xs=range(5,21))
