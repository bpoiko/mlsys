# Lab 02 — Registers, Shared Memory, and Occupancy

## Objective

Measure how per-thread/per-block resources constrain resident warps and how that
interacts with instruction-level parallelism and latency hiding.

## Why this matters for GPU/ML systems

High-performance kernels balance tile size, register reuse, spills, and active work;
maximal occupancy is not automatically optimal.

## Prerequisites and reading

Coalescing lab. Read CUDA Best Practices occupancy material and Nsight Compute's
occupancy and register-spill metric descriptions.

## Coding task

Create kernel variants in `starter.cu` with controlled block size, shared-memory
footprint, and per-thread accumulation. Preserve operations/results.

## Correctness criteria

All variants match the same reference and process identical work.

## Performance task

Record compiler register usage, theoretical/achieved occupancy, spill traffic, and
timings. Explain a case where occupancy rises without a speedup or vice versa.

## Exit criteria

Do not move on until you can calculate the active-block constraint and distinguish
resource limits from the actual performance bottleneck.
