# Lab 04 — Kernel Fusion

## Objective

Compare an unfused operation chain with a fused kernel while accounting for global
traffic, launches, register pressure, occupancy, and numerical behavior.

## Why this matters for GPU/ML systems

Inference graphs contain many bandwidth-bound elementwise operations; fusion is a
central compiler and kernel optimization, but larger kernels have costs.

## Prerequisites and reading

Softmax and Nsight investigation. Review CUDA memory hierarchy and Roofline notes.

## Coding task

Implement separate bias, activation, and scaling kernels plus one fused equivalent
in `starter.cu`. Freeze the mathematical contract before optimization.

## Correctness criteria

Both paths match a CPU reference and each other within justified tolerance over
adversarial values and awkward sizes.

## Performance task

Count predicted reads/writes and launches; measure kernel and end-to-end intervals;
profile resource/traffic changes across sizes.

## Exit criteria

Do not move on until you can explain both the observed benefit and the point where
fusion could reduce flexibility, occupancy, or maintainability.
