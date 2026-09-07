# Lab 05 — Threads, Synchronization, and Cache-Friendly Data

## Objective

Reason about shared state with threads, mutexes, and atomics, then connect data
layout and false sharing to measured scaling.

## Why this matters for GPU/ML systems

Inference runtimes coordinate CPU workers and GPU submission; contention and poor
layout can starve accelerators.

## Prerequisites and reading

Complete C++ lifetime labs. Read cppreference on `thread`, `mutex`, `atomic`, and
the C++ memory model overview.

## Coding task

Implement counter variants and a partitioned array transform in `starter.cpp`.
Design tests that make synchronization requirements explicit. Add an AoS-versus-SoA
layout experiment.

## Correctness criteria

Deterministic expected results across repeated runs; no unsynchronized conflicting
access; documented ownership of worker data and thread lifetime.

## Performance task

Measure 1..N threads, mutex versus suitable atomic operation, padded versus adjacent
counters, and AoS versus SoA. Change one variable per comparison.

## Exit criteria

Do not proceed until you can distinguish a race condition from a data race and
explain one scaling limit using contention, bandwidth, or cache coherence.
