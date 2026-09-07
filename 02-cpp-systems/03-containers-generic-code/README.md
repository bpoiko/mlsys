# Lab 03 — Containers, Iterators, Templates, and Lambdas

## Objective

Use standard containers and generic algorithms while retaining awareness of
allocation, invalidation, and data layout.

## Why this matters for GPU/ML systems

Host-side scheduling and preprocessing code needs safe abstractions whose memory
and iteration costs remain understandable.

## Prerequisites and reading

RAII lab. Read cppreference on `vector`, iterator invalidation, algorithms,
templates, and lambdas.

## Coding task

Complete generic transform/reduce utilities in `starter.cpp`, then apply them to
`std::vector`. Test empty and large inputs and deliberately observe one documented
iterator-invalidation case without invoking undefined behavior.

## Correctness criteria

Match a simple reference, support const iteration, constrain assumptions in
comments, and compile under strict warnings/sanitizers.

## Performance task

Compare reserved versus repeated-growth construction using a valid repeated-sample
benchmark and allocation counts.

## Exit criteria

Do not move on until you can state container ownership, iterator category needs,
capture semantics, and invalidation rules used by your code.
