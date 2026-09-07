# 02 — Matmul (Naive)

**Goal:** Write a correct 2D-indexed matrix multiply where each thread computes one output element `C[row][col]`. Correctness first; speed comes in `03-matmul-tiled`.

## Concepts
- [ ] 2D thread indexing with `dim3 block(16,16)` and a 2D grid
- [ ] Row/col from `blockIdx`/`threadIdx` in x and y
- [ ] Row-major flattening: `M[row * width + col]`
- [ ] The inner dot-product loop over `k`
- [ ] Bounds guard for non-square / non-divisible sizes
- [ ] Why this is *memory-bound*: every thread re-reads whole rows/cols from global memory
- [ ] Global memory is slow — this sets up the motivation for tiling

## Exercises
- [ ] Implement `C = A * B` for square N×N (start N=1024)
- [ ] Verify against a CPU triple-loop reference (tolerance for float)
- [ ] Measure GFLOP/s: `2*N^3 / seconds` (feeds into `03-benchmark-harness`)
- [ ] Try block sizes 8×8, 16×16, 32×32 and compare
- [ ] Note the achieved GB/s vs. your GPU's peak — see how far off you are

## Resources
- Simon Boehm, "How to Optimize a CUDA Matmul Kernel" (naive section): https://siboehm.com/articles/22/CUDA-MMM
- PMPP ch. 3–4 (matrix multiply)
- CUDA C++ Programming Guide — Memory Hierarchy

## Done when
- [ ] GPU matmul matches CPU reference within float tolerance
- [ ] I have a GFLOP/s number to beat with the tiled version
