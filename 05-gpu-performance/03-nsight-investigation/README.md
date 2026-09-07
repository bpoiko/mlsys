# Lab 03 — Nsight Systems and Nsight Compute Investigation

## Objective

Use timeline and kernel profilers for complementary questions and write one
evidence-backed bottleneck diagnosis.

## Why this matters for GPU/ML systems

Real inference slowdowns may be launch gaps, transfers, synchronization, or a
specific kernel limit; no single profiler view answers all of them.

## Prerequisites and reading

Previous GPU labs. Read NVIDIA's official Nsight Systems and Nsight Compute getting
started/workflow documentation.

## Coding task

Use `starter.cu` to assemble multiple copies and kernels with NVTX-labeled phases.
Keep a serialized baseline and one hypothesized improvement.

## Correctness criteria

Outputs match, annotations cover the intended phases, and profiling mode does not
silently change the problem dimensions.

## Performance task

Use Systems to choose the dominant interval; then use Compute only on the selected
kernel. Save commands/reports and map each cited metric to the hypothesis.

## Exit criteria

Do not move on until you can say which tool answered which question and identify
at least one tempting metric that would not prove your claim.
