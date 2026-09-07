# Lab 03 — Linux perf and Compiler Evidence

## Objective

Use hardware counters and disassembly to test a bottleneck hypothesis rather than
guess from elapsed time alone.

## Why this matters for GPU/ML systems

CPU submission, preprocessing, and framework overhead can dominate short GPU work;
systems engineers need evidence across both processors.

## Prerequisites and reading

Valid benchmark harness. Read `man perf-stat`, `man perf-record`, and `man perf-report`.

## Coding task

Use `starter.cpp` as a selectable access/compute workload. Make outputs identical
across modes and preserve symbols for profiling.

## Correctness criteria

Modes produce the same checksum; commands, compiler flags, and input sizes are saved.

## Performance task

Collect cycles, instructions, branches/misses, and cache-related events available
on your machine. Inspect a hot function's generated assembly at two optimization
levels. Treat multiplexed/unsupported events explicitly.

## Exit criteria

Do not move on until one counter-derived observation changes, supports, or rejects
your initial hypothesis and you can state the counter's limitations.
