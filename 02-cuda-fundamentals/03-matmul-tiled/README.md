# 03 — Matmul (Tiled / Shared Memory)

**Goal:** Speed up matmul by loading tiles into shared memory so each value is read from slow global memory once and reused by the whole block. This is the payoff of the CUDA track.

> Requires a working, verified naive matmul (`02`) to compare against.

## Concepts
- [ ] The memory hierarchy: registers > shared > L2 > global
- [ ] `__shared__` memory is per-block, fast, and small
- [ ] Tiling: split A and B into TILE×TILE blocks
- [ ] The two-phase loop: **load tile → `__syncthreads()` → compute → `__syncthreads()`**
- [ ] Why BOTH `__syncthreads()` calls are required (race conditions otherwise)
- [ ] Arithmetic intensity: tiling raises compute-per-byte
- [ ] Handling matrix sizes not divisible by TILE (guarded loads → 0)
- [ ] (Stretch) register blocking / thread-coarsening for more speed

## Exercises
- [ ] Implement 16×16 tiled matmul
- [ ] Verify it matches the naive/CPU result exactly-ish (float tolerance)
- [ ] Benchmark vs. naive — expect a large speedup; record GFLOP/s
- [ ] Profile with Nsight Compute; look at memory throughput + occupancy
- [ ] Compare against cuBLAS `sgemm` to see how far off "good" is
- [ ] Stretch: follow Boehm's article to a register-tiled kernel

## Resources
- Simon Boehm, "How to Optimize a CUDA Matmul Kernel" (the whole thing): https://siboehm.com/articles/22/CUDA-MMM
- PMPP ch. 5 (shared memory + tiling)
- CUDA Samples `matrixMul` (tiled reference): https://github.com/NVIDIA/cuda-samples
- CUDA C++ Best Practices Guide

## Done when
- [ ] Tiled version is correct AND meaningfully faster than naive
- [ ] I can explain why shared-memory reuse cuts global memory traffic
