# Lab 01 — Coalescing and Divergence

## Objective

Isolate global-memory access pattern and branch divergence, then connect source
changes to warp-level behavior and memory transactions.

## Why this matters for GPU/ML systems

Tensor layouts and irregular control flow often determine whether useful bandwidth
and lane throughput are achieved.

## Prerequisites and reading

CUDA primitives and GPU benchmark harness. Read CUDA Best Practices sections on
coalesced access and branch divergence.

## Coding task

Implement correctness-equivalent contiguous, strided, and remapped accesses plus
uniform and lane-varying branch cases in `starter.cu`.

## Correctness criteria

All variants operate on logically identical elements and pass reference/Compute
Sanitizer checks. Avoid changing both access and instruction count together.

## Performance task

Measure achieved bandwidth and collect relevant Nsight Compute memory/warp metrics.
Use at least two sizes and explain cache effects.

## Exit criteria

Do not move on until the transaction and active-lane evidence supports or rejects
your initial source-level prediction.
