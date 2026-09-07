# Lab 01 — Memory Hierarchy, Caches, Virtual Memory, and TLBs

## Objective

Reveal cache-line, locality, bandwidth, page, and TLB effects through controlled
access-pattern experiments.

## Why this matters for GPU/ML systems

Accelerators are fed by host memory and execute workloads whose speed often depends
more on data movement than arithmetic.

## Prerequisites and reading

C++ cache lab. Read your CPU vendor's optimization manual sections on cache and
TLBs, plus `man getconf`/`lscpu` documentation.

## Coding task

Complete `starter.cpp`: sequential/strided traversal and a page-stride experiment.
Use the same allocation and work count where the comparison requires it.

## Correctness criteria

All variants return the same independently checked result; index arithmetic cannot
overflow or leave the allocation.

## Performance task

Sweep working-set size and stride with warmups/repeats. Record CPU, frequency policy,
page size, compiler, flags, and raw samples.

## Exit criteria

Do not move on until you can separate latency from bandwidth and identify plausible
cache-capacity, cache-line, and TLB transitions without overclaiming exact causes.
