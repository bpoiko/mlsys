# Memory Layout and Alignment

## Objective

Connect C object layout, alignment, flat matrices, and access order to the memory
transactions later observed on CPUs and GPUs.

## Why this matters for GPU/ML systems

Tensor layout, vector loads, cache lines, memory coalescing, and ABI boundaries all
depend on address calculation and alignment.

## Prerequisites and reading

- Complete arrays/strings and structs.
- Read Beej's arrays/structs sections and the C reference for `offsetof`.

## Coding task

Predict then print sizes, alignments, and member offsets for several field orders.
Allocate one flat matrix, verify `row * cols + col`, and traverse it in row-major
and column-major order without changing the computed checksum.

## Correctness and performance task

Check all size products before allocation. Compile with strict warnings and
sanitizers. Once correct, measure repeated traversals with warmups and equal work;
record raw samples but do not optimize yet.

## Exit criteria

Do not proceed until layout predictions match measurements and you can explain why
identical values/access counts may produce different traversal times.
