# Lab 01 — References, Const, and Classes

## Objective

Express mutation, borrowing, and invariants using references, const correctness,
constructors, destructors, and class boundaries.

## Why this matters for GPU/ML systems

Runtime and driver code passes large buffers through many layers; interfaces must
state what can change and keep objects valid.

## Prerequisites and reading

C ownership gate. Read cppreference pages for references, cv qualifiers, classes,
constructors, and destructors.

## Coding task

Complete `starter.cpp`: implement a small `BufferView` with const and mutable
access, invariants, and no ownership. Add a separate scoped object whose constructor
and destructor make lifetime observable.

## Correctness criteria

Reject invalid construction, compile const call sites correctly, and pass warning
and sanitizer checks. Do not add owning allocation to `BufferView`.

## Performance task

Inspect optimized assembly for pass-by-value versus const-reference of a larger
record; do not claim a difference without measurement.

## Exit criteria

Do not move on until you can explain reference binding, const on the object versus
the handle, class invariants, and destruction order.
