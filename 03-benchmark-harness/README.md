# 03 — Benchmark Harness

**Goal:** Build a small, reusable way to measure how fast your kernels actually are — correctly. Naive timing lies; this teaches you to measure like an engineer.

## Concepts
- [ ] Why host clocks alone are wrong for GPU work (async launches)
- [ ] `cudaEvent_t` timing: record start → work → record stop → `cudaEventElapsedTime`
- [ ] **Warmup runs** — the first launch pays one-time costs; discard it
- [ ] Run N iterations and report median/min, not a single sample
- [ ] Deriving throughput:
  - [ ] GFLOP/s for matmul: `2 * N^3 / seconds`
  - [ ] GB/s for memory-bound kernels: `bytes_moved / seconds`
- [ ] Compare achieved vs. theoretical peak (from `deviceQuery` specs)
- [ ] The Roofline mental model: am I compute-bound or memory-bound?
- [ ] Pitfalls: dead-code elimination (compiler deletes unused results), cold cache

## Deliverables
- [ ] A reusable timing helper (macro or function) using cudaEvents
- [ ] Wrap vector-add, naive matmul, and tiled matmul with it
- [ ] A small table: kernel | time | GFLOP/s | % of peak
- [ ] (Stretch) auto-run across sizes and print a CSV I can plot

## Resources
- NVIDIA "How to Implement Performance Metrics in CUDA": https://developer.nvidia.com/blog/how-implement-performance-metrics-cuda-cc/
- Nsight Compute / Nsight Systems (profilers)
- Roofline model intro (NERSC): https://docs.nersc.gov/tools/performance/roofline/
- Google Benchmark (CPU-side reference design): https://github.com/google/benchmark

## Done when
- [ ] I can report GFLOP/s for each kernel with warmup + multiple iterations
- [ ] I know whether each kernel is compute- or memory-bound and why
