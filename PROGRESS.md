# Implementation Progress

Check an item only when the named artifact exists and its correctness/tool gate
passes. Reading alone does not count.

## 01 — C memory foundation

- [x] `mallote.c` compiles with `-Wall -Wextra -Wpedantic -Werror`.
- [ ] `mallote.c` passes AddressSanitizer and UndefinedBehaviorSanitizer.
- [ ] Allocation ownership/failure paths are explained in checkpoint `NOTES.md`.
- [ ] Array/string functions pass edge-case tests without sanitizer findings.
- [ ] Struct layout predictions match measured `sizeof`/`offsetof` results.
- [ ] Linked-list insert/delete/free tests pass without leaks or invalid access.

## 02 — Modern C++ systems

- [ ] A const-correct class manages a resource with deterministic lifetime.
- [ ] A raw owning allocation is replaced by RAII and `std::unique_ptr`.
- [ ] STL/iterator/template/lambda exercises pass where raw loops are prohibited.
- [ ] Copy and move operations satisfy documented ownership invariants.
- [ ] Threaded code passes correctness tests and explains its synchronization.
- [ ] Two data layouts are benchmarked with repeatable cache-locality evidence.

## 03 — Systems performance

- [ ] Cache-stride and TLB experiments produce saved raw measurements.
- [ ] Benchmark harness reports warmups, repeated samples, median, and variance.
- [ ] `perf stat` evidence supports a stated bottleneck hypothesis.
- [ ] SIMD/branch variants are correctness-equivalent and measured fairly.
- [ ] Arithmetic intensity, Amdahl limit, and Roofline placement are calculated.

## 04 — CUDA fundamentals

- [ ] Toolchain/device facts and a checked kernel launch are recorded.
- [ ] Vector add handles arbitrary sizes and matches a CPU reference.
- [ ] Naive matmul handles non-divisible dimensions and passes tolerance checks.
- [ ] Tiled matmul is correct, measured against naive, and explained.
- [ ] Reduction and softmax-style reduction pass adversarial correctness cases.
- [ ] Streams/events experiment demonstrates and correctly measures asynchrony.

## 05 — GPU performance

- [ ] Reusable CUDA benchmark records warmups and sample distributions.
- [ ] Coalescing/divergence experiment connects code shape to profiler metrics.
- [ ] Register/occupancy tradeoff is measured without claiming occupancy equals speed.
- [ ] Nsight Systems and Compute reports support one bottleneck diagnosis.
- [ ] A fusion experiment reports traffic saved and end-to-end impact.

## 06 — ML inference systems

- [ ] Transformer operation/shape/byte accounting is validated on a small model.
- [ ] MHA/GQA/MQA KV-cache sizes and decode traffic are computed and explained.
- [ ] TTFT, inter-token latency, throughput, and batching are measured separately.
- [ ] Precision/quantization experiment reports accuracy, memory, and speed tradeoffs.
- [ ] PyTorch profiler trace identifies an evidence-backed bottleneck.

## 07 — Capstone

- [ ] Correctness contract and baseline are frozen before optimization.
- [ ] A profile identifies the selected bottleneck and metric.
- [ ] One isolated optimization is implemented and remeasured.
- [ ] Final report explains the hardware/software tradeoff and failed hypotheses.
