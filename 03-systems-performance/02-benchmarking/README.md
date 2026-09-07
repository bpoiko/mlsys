# Lab 02 — Valid Benchmarking

## Objective

Build a CPU harness that prevents common timing mistakes and reports distributions.

## Why this matters for GPU/ML systems

Performance engineering decisions are only as sound as the measurement protocol.
Async devices add more ways to time the wrong interval.

## Prerequisites and reading

Memory-hierarchy lab. Read Google Benchmark's user guide sections on methodology
and your standard library's steady clock documentation.

## Coding task

Implement `benchmark` in `starter.cpp`: setup outside timing, configurable warmups,
repeated samples, result consumption, and CSV output. Compute median and a variance
or percentile summary yourself.

## Correctness criteria

Test statistics on known samples. Verify the measured work is not optimized away
and setup is excluded.

## Performance task

Measure one kernel under `-O0`, `-O2`, and `-O3`; repeat in randomized order and
report distributions, not a single best number.

## Exit criteria

Do not move on until another person can reproduce the result and you can list at
least five threats to benchmark validity present in your experiment.
