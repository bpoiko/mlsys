# Lab 02 — RAII and Smart-Pointer Ownership

## Objective

Tie resource lifetime to object lifetime and distinguish unique, shared, and
borrowed access.

## Why this matters for GPU/ML systems

Device allocations, streams, events, files, and mapped buffers all need cleanup
on normal returns and failures.

## Prerequisites and reading

Lab 01. Read cppreference on RAII, `std::unique_ptr`, and `std::shared_ptr`; focus
on ownership semantics, not API memorization.

## Coding task

Implement `OwnedBuffer` in `starter.cpp` using RAII. First use a unique owner;
write a separate diagram showing when shared ownership would and would not be
justified. Do not use `shared_ptr` merely to avoid designing lifetime.

## Correctness criteria

No manual cleanup in callers, no leaks on early exit, safe empty state, and clear
borrowed access. Pass warnings and sanitizers.

## Performance task

Count allocations and ownership operations; explain possible reference-count and
cache costs of shared ownership.

## Exit criteria

Do not move on until each handle can be labeled owner, shared owner, or borrower
and cleanup is automatic on every control-flow path.
