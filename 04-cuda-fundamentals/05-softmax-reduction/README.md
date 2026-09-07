# Lab 05 — Stable Softmax-Style Reductions

## Objective

Compose maximum, exponentiation, sum, and normalization while preserving numerical
stability and correct synchronization.

## Why this matters for GPU/ML systems

Softmax is on the attention path and illustrates reductions, precision, traffic,
and fusion tradeoffs.

## Prerequisites and reading

Reduction lab. Read a numerical-stability explanation of max subtraction and the
CUDA guide's floating-point behavior section.

## Coding task

Implement a row-wise softmax in `starter.cu`; begin with clear multi-pass kernels,
then consider a fused row kernel only after the baseline is correct.

## Correctness criteria

Compare with a double-precision CPU reference on large positive/negative values,
constant rows, odd widths, and multiple rows. Check finite outputs and row sums.

## Performance task

Count full-row reads/writes per design and measure across row widths. Separate kernel
time from transfers.

## Exit criteria

Do not move on until you can explain stability, reduction scope, and the resource
tradeoff of processing a row within one block.
