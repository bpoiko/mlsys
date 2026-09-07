# Lab 04 — Parallel Reduction

## Objective

Implement a correct sum reduction, then remove avoidable divergence and memory
traffic one controlled step at a time.

## Why this matters for GPU/ML systems

Reductions underpin norms, losses, statistics, attention, and softmax.

## Prerequisites and reading

Tiled matmul. Read the CUDA Programming Guide sections on SIMT, shared memory, and
synchronization; read NVIDIA's reduction sample as concepts, not copyable code.

## Coding task

Complete `starter.cu` for arbitrary counts. Use a CPU reference and test zero,
one, non-power-of-two, and large inputs. Implement variants incrementally.

## Correctness criteria

Document floating-point tolerance/order effects; pass Compute Sanitizer and awkward
sizes; no thread reads out of bounds or exits across a required block barrier.

## Performance task

Use CUDA events and repeated samples. Estimate bytes, compare variants, and explain
changes using branch, synchronization, and memory behavior.

## Exit criteria

Do not move on until correctness is independent of convenient sizes and one speedup
has an evidence-backed mechanism.
