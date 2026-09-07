# Lab 05 — Arithmetic Intensity, Roofline, and Amdahl's Law

## Objective

Build simple quantitative models that bound performance and optimization payoff.

## Why this matters for GPU/ML systems

Hardware/software co-design starts by asking whether bytes, operations, or an
unoptimized fraction impose the current limit.

## Prerequisites and reading

Completed benchmark evidence. Read the original Roofline paper overview or NERSC
Roofline documentation and a standard derivation of Amdahl's Law.

## Coding task

Finish `starter.cpp` to calculate arithmetic intensity, bandwidth/compute ceilings,
and Amdahl speedup from explicit inputs. Validate with hand-computed cases.

## Correctness criteria

Units are printed and internally consistent; all assumptions (bytes counted,
precision, peak versus sustained rates) are recorded.

## Performance task

Place at least two measured kernels on a simple Roofline and compare predicted
ceilings with achieved performance. Use Amdahl to bound one proposed optimization.

## Exit criteria

Do not move on until you can show how changing data reuse moves a point horizontally
and explain why a model is a bound rather than a profiler diagnosis.
