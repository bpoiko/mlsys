# Lab 05 — PyTorch Profiling and Optimization Tradeoffs

## Objective

Profile a small inference graph, choose one bottleneck from evidence, make one
controlled change, and report end-to-end consequences.

## Why this matters for GPU/ML systems

Framework-level overhead, tensor layout, synchronization, kernel selection, fusion,
precision, and batching interact above individual CUDA kernels.

## Prerequisites and reading

All prior inference labs. Read the official PyTorch profiler recipe and CUDA
semantics documentation for asynchronous timing.

## Coding task

Complete `starter.py` with a deterministic reference workload and correctness
check. Add profiler schedule/activities only after a warmup baseline works. Select
one change: layout, fusion/compile path, batching, or precision.

## Correctness criteria

Inference/eval mode is explicit, outputs are compared, synchronization is correct
for the metric, and profiling does not silently change inputs.

## Performance task

Report TTFT or operation latency separately from steady-state throughput and memory.
Use profiler evidence to justify the change; include any accuracy or flexibility cost.

## Exit criteria

Do not proceed to capstone until the report includes a rejected hypothesis and an
explanation of why a local kernel improvement may not move end-to-end performance.
