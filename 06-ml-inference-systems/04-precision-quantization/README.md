# Lab 04 — Precision and Quantization Tradeoffs

## Objective

Compare FP32, FP16, BF16, FP8, INT8, and INT4 at the level of representation,
memory traffic, hardware support, accumulation, and accuracy risk.

## Why this matters for GPU/ML systems

Precision changes capacity, bandwidth, and accelerator throughput, but conversion,
scales, outliers, and unsupported fast paths can erase theoretical gains.

## Prerequisites and reading

Inference metrics lab. Read vendor documentation for formats supported by your
actual GPU and a framework's official quantization overview.

## Coding task

Implement a small symmetric INT8 quantize/dequantize experiment in `starter.cpp`
with learner-chosen scale policy. Treat FP8 and INT4 conceptually unless hardware
and a trustworthy library path are available.

## Correctness criteria

Test zeros, extremes, outliers, clipping, and non-finite policy. Report max/mean
error and task-relevant output error, not only compressed byte count.

## Performance task

Measure footprint and end-to-end operation time including required conversions.
Compare theoretical format throughput only with explicit hardware support.

## Exit criteria

Do not move on until you can distinguish storage, compute, and accumulator precision
and explain when quantization is bandwidth-, capacity-, or compute-motivated.
