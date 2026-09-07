# Ordered Learning Plan

Use one milestone at a time. Each lab README narrows the task; `NOTES.md` is where
you explain results in your own words. For performance labs, save the full loop:
observation, hypothesis, metric/tool, controlled change, before/after data, and
causal explanation.

## Milestone 1 — Repair the current C memory evidence

1. **Read:** the audit; Beej's Guide sections on pointers and manual allocation;
   the checkpoint README.
2. **Implement:** repair your existing `malloc-free/mallote.c`; do not replace it.
3. **Measure/debug:** strict warnings, ASan, UBSan, then leak checking where available.
4. **Explain:** allocation ownership, alias validity, `realloc` failure behavior,
   and why clearing one pointer does not clear aliases.
5. **Next:** `01-c-fundamentals/arrays-strings`.

Do not move on until the current source compiles warning-free, runs sanitizer-clean,
and every allocation has an explicit owner and cleanup path.

## Milestone 2 — Complete the C data/layout foundation

1. **Read:** each existing C README plus `memory-layout/README.md`.
2. **Implement:** arrays/strings, structs/layout, flat matrices, then linked list.
3. **Measure/debug:** boundary cases, `sizeof`/`offsetof`, row/column traversal,
   warnings, ASan/UBSan, and leak checks.
4. **Explain:** decay, terminators, padding, row-major addressing, and safe deletion.
5. **Next:** `02-cpp-systems/01-language-foundations`.

Do not move on until all C milestones in `PROGRESS.md` are backed by code and tool
output, including a fully freed linked list.

## Milestone 3 — Build modern C++ ownership skill

1. **Read:** labs 01–04 under `02-cpp-systems` and their linked reference sections.
2. **Implement:** const-correct classes, RAII, smart-pointer ownership, STL/generic
   code, and explicit copy/move behavior.
3. **Measure/debug:** compiler warnings, sanitizers, destructor/copy/move traces,
   and tests of moved-from and exceptional paths.
4. **Explain:** lifetime versus scope, ownership transfer, deep versus shallow copy,
   why `std::move` is a cast, and when shared ownership is justified.
5. **Next:** `02-cpp-systems/05-concurrency-cache`.

Do not move on until resource lifetime remains correct without manual cleanup in
callers and you can defend each owning pointer type.

## Milestone 4 — Reason about concurrency and locality

1. **Read:** the C++ concurrency/cache lab and systems memory-hierarchy lab.
2. **Implement:** synchronized counters/queues and alternative data layouts.
3. **Measure/debug:** ThreadSanitizer where supported; scaling, cache misses, and
   layout timings with correctness held constant.
4. **Explain:** data race versus race condition, mutex versus atomic, false sharing,
   cache lines, locality, virtual memory, and TLB pressure.
5. **Next:** `03-systems-performance/02-benchmarking`.

Do not move on until you can identify shared state, justify synchronization, and
connect a repeatable locality result to the memory hierarchy.

## Milestone 5 — Make performance analysis a controlled experiment

1. **Read:** systems labs 02–05.
2. **Implement:** a CPU benchmark harness, perf experiment, SIMD/branch variants,
   and arithmetic-intensity/Amdahl/Roofline calculations.
3. **Measure/debug:** multiple optimization levels, warmups, distributions,
   hardware counters, disassembly, and one-variable comparisons.
4. **Explain:** latency versus bandwidth, invalid benchmark failure modes, counter
   limitations, vectorization, branch effects, and model-versus-measurement gaps.
5. **Next:** `04-cuda-fundamentals/00-smoke-test`.

Do not move on until another engineer could reproduce one of your performance
claims from the recorded command, environment, raw samples, and correctness check.

## Milestone 6 — Establish correct CUDA programming

1. **Read:** CUDA labs 00–03 and the specified Programming Guide sections.
2. **Implement:** smoke test, vector add, general naive matmul, and tiled matmul.
3. **Measure/debug:** CUDA error checks, Compute Sanitizer, CPU-reference comparison,
   CUDA events, and block-size experiments.
4. **Explain:** host/device lifetimes, asynchronous launches, grids/blocks/threads,
   warps/SIMT, bounds, coalescing, synchronization, and shared-memory reuse.
5. **Next:** `04-cuda-fundamentals/04-reduction`.

Do not move on until non-divisible sizes are correct and the tiled-versus-naive
result is supported by both a traffic hypothesis and measurements.

## Milestone 7 — Learn GPU primitives and asynchronous execution

1. **Read:** CUDA labs 04–06.
2. **Implement:** reduction, softmax-style reduction, and a streams/events pipeline.
3. **Measure/debug:** adversarial inputs, synchronization failures, CUDA-event timing,
   and overlap timelines.
4. **Explain:** reduction associativity, divergence, register/shared/global memory,
   synchronization scope, stream ordering, and when overlap is possible.
5. **Next:** `05-gpu-performance/00-benchmark-harness`.

Do not move on until each primitive is reference-correct and its timing excludes
unintended host/device synchronization.

## Milestone 8 — Diagnose GPU bottlenecks

1. **Read:** all labs under `05-gpu-performance`.
2. **Implement:** reusable measurements and isolated coalescing, divergence,
   occupancy/register, and fusion experiments.
3. **Measure/debug:** Nsight Systems for timelines; Nsight Compute for kernel metrics;
   achieved bandwidth, throughput, occupancy, and traffic.
4. **Explain:** why occupancy is not a goal by itself, how access patterns form
   transactions, and why fewer kernels/bytes may or may not improve latency.
5. **Next:** `06-ml-inference-systems/01-transformer-execution`.

Do not move on until one optimization report connects source, profiler evidence,
hardware behavior, and before/after distributions without changing correctness.

## Milestone 9 — Model ML inference as a systems workload

1. **Read:** ML inference labs 01–04.
2. **Implement:** operation/shape accounting, KV-cache traffic models, metric harness,
   and a small precision/quantization comparison.
3. **Measure/debug:** bytes and FLOPs by phase, TTFT versus decode latency, batch-size
   sweeps, accuracy error, and memory footprint.
4. **Explain:** matmul/attention flow, MHA/GQA/MQA, prefill/decode, model-weight and
   KV traffic, arithmetic intensity, precision formats, and continuous batching.
5. **Next:** `06-ml-inference-systems/05-pytorch-profile`.

Do not move on until you can predict which phase is compute- or memory-limited and
then compare that prediction with measurement.

## Milestone 10 — Profile a framework workload and complete the capstone

1. **Read:** the PyTorch profiling lab and `07-ml-capstone/README.md`.
2. **Implement:** a profiled reference workload, then one scoped capstone with a
   frozen correctness test and baseline.
3. **Measure/debug:** CPU/GPU trace, memory use, TTFT/latency/throughput, and one
   isolated optimization such as fusion, layout, batching, or precision.
4. **Explain:** the chosen bottleneck, rejected hypotheses, tradeoffs, portability,
   and the hardware/software co-design implication.
5. **Next:** only after review, choose deeper CUDA, distributed inference, or the
   optional compiler path.

Do not finish until the capstone report makes a reproducible, falsifiable performance
claim and includes correctness evidence plus raw before/after samples.
