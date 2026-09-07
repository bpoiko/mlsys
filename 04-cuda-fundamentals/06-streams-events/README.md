# Lab 06 — Asynchrony, Streams, and CUDA Events

## Objective

Build and correctly time a copy/compute pipeline, then determine whether transfer
and kernel execution overlap on your system.

## Why this matters for GPU/ML systems

Inference latency and throughput depend on queues, synchronization, and overlap as
much as isolated kernel speed.

## Prerequisites and reading

Vector add and valid CPU benchmarking. Read CUDA Programming Guide sections on
asynchronous execution, streams, events, and page-locked host memory.

## Coding task

Complete `starter.cu`: baseline serialized execution, then chunked execution in
multiple non-default streams with explicit dependencies and RAII cleanup.

## Correctness criteria

Every chunk matches a CPU reference; lifetime extends through async use; errors are
checked at the synchronization point that can report them.

## Performance task

Use CUDA events for device intervals and Nsight Systems for the timeline. Report
end-to-end latency separately from steady-state throughput.

## Exit criteria

Do not move on until you can identify exactly what overlapped, why overlap was
possible or absent, and which timing method supports the claim.
