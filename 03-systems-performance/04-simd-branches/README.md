# Lab 04 — SIMD and Branch Behavior

## Objective

Connect vectorization and branch predictability to compiler reports, assembly,
counters, and fair timings.

## Why this matters for GPU/ML systems

Vector CPU kernels are references and fallbacks; branch divergence has a related
but distinct cost on GPUs.

## Prerequisites and reading

Benchmark/perf labs. Read your compiler's vectorization-report documentation and
your CPU vendor's SIMD optimization guidance.

## Coding task

Implement correctness-equivalent scalar/auto-vectorizable and predictable/unpredictable
variants in `starter.cpp`. Do not use intrinsics until auto-vectorization evidence
is understood.

## Correctness criteria

Compare outputs with appropriate integer or floating-point tolerances and inspect
behavior on tail lengths not divisible by vector width.

## Performance task

Save vectorizer reports, selected assembly, branch counters, and sample distributions.

## Exit criteria

Do not move on until you can explain why a loop did or did not vectorize and avoid
equating CPU branch misprediction directly with GPU warp divergence.
