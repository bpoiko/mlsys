# Lab 04 — Copy, Move, and Lifetime

## Objective

Implement and test value semantics for a resource-owning type, including moved-from
states and exception-safe assignment.

## Why this matters for GPU/ML systems

Silent deep copies of large tensors are expensive; shallow copies can double-free;
ownership transfer must be both correct and visible.

## Prerequisites and reading

RAII and containers labs. Read cppreference on copy/move constructors, assignment,
special member functions, and `std::move`.

## Coding task

Finish `TraceBuffer`. Record which operations each test triggers. Choose whether
the type should be copyable, move-only, or both, and justify that API.

## Correctness criteria

No leaks/double frees, self-assignment is safe if supported, moved-from objects are
valid, and vector reallocation behavior is observed.

## Performance task

Measure a deliberately large copy versus move without timing allocation setup.

## Exit criteria

Do not proceed until you can explain why `std::move` moves nothing by itself and
predict which special member function each expression selects.
