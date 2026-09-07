# Lab 03 — Prefill, Decode, Metrics, and Batching

## Objective

Measure TTFT, inter-token latency, tokens/second, and memory use separately while
varying prompt length, output length, and batch policy.

## Why this matters for GPU/ML systems

Interactive latency and serving throughput reward different schedules; batching
raises utilization while queueing and KV growth can hurt latency/capacity.

## Prerequisites and reading

Transformer and KV-cache labs. Read the chosen inference runtime's official metric
definitions and continuous-batching design documentation.

## Coding task

Complete `starter.cpp` as a trace analyzer for request timestamps. Define events for
arrival, prefill completion/first token, and subsequent tokens. Add synthetic traces
that test overlapping requests and variable sequence lengths.

## Correctness criteria

Metrics have explicit start/end events and units; warmup requests and failures are
reported; aggregate throughput is not mislabeled per-request latency.

## Performance task

Sweep static batch size in a real or simulated workload, then model continuous
batch admission conceptually. Report distribution percentiles and queueing separately.

## Exit criteria

Do not move on until you can explain how a scheduling change can improve tokens/s
while worsening TTFT or inter-token latency.
