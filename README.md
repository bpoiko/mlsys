# mlsys — GPU / ML Systems Performance Curriculum

This repository is a lab course, not a checklist of topics. Progress is based on
code, measurements, profiler evidence, and explanations written by the learner.
A checked box in an older README is historical context, not proof of mastery.

## Start here

1. Read [`docs/CURRENT_SKILL_AUDIT.md`](docs/CURRENT_SKILL_AUDIT.md).
2. Follow the single ordered path in [`LEARNING_PLAN.md`](LEARNING_PLAN.md).
3. Record only implementation evidence in [`PROGRESS.md`](PROGRESS.md).
4. Begin with [`01-c-fundamentals/memory-safety-checkpoint`](01-c-fundamentals/memory-safety-checkpoint/README.md).

## Curriculum

- `01-c-fundamentals/` — pointers, arrays, allocation, ownership, layout, sanitizers
- `02-cpp-systems/` — RAII, containers, copy/move, generic code, concurrency
- `03-systems-performance/` — caches, VM/TLBs, benchmarking, perf, SIMD, models
- `04-cuda-fundamentals/` — kernels, indexing, memory, tiling, reductions, streams
- `05-gpu-performance/` — measurement, coalescing, divergence, occupancy, Nsight, fusion
- `06-ml-inference-systems/` — transformer execution, KV cache, batching, precision, profiling
- `07-ml-capstone/` — one measured, explained, end-to-end inference optimization

Compiler work such as LLVM/MLIR is intentionally deferred until the core path is
complete.

## The performance loop

Every performance lab uses the same engineering record:

> Observe → hypothesize → choose a metric/tool → isolate one variable → measure
> → explain the bottleneck → optimize → remeasure → explain the change

Keep raw results and environment details. Do not claim a speedup from a single
sample or from runs whose correctness has not been checked.

## Evidence policy

Existing learner source remains learner-owned. Curriculum scaffolding may point
out a defect, ask a question, or provide a test contract, but it must not replace
the implementation with a solution. There is deliberately no solutions folder.
