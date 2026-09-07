# Lab 02 — Attention, MHA/GQA/MQA, and KV Cache

## Objective

Derive attention tensor shapes and quantify KV-cache capacity and per-token traffic
for multi-head, grouped-query, and multi-query attention.

## Why this matters for GPU/ML systems

KV-cache storage and reads dominate long-context decode capacity and bandwidth;
head-sharing choices are hardware/software co-design decisions.

## Prerequisites and reading

Transformer accounting. Read the original Attention Is All You Need attention
definition, a GQA paper overview, and the FlashAttention paper's IO motivation.

## Coding task

Complete `starter.cpp` to calculate cache size and a stated decode-traffic lower
bound. Print shapes for Q, K, V, scores, and output under MHA/GQA/MQA. Validate a
tiny attention computation separately before optimizing anything.

## Correctness criteria

Head divisibility and units are checked; batch, layers, current context length,
precision, and K-plus-V factor are explicit.

## Performance task

Sweep context, batch, and KV-head count. Compare capacity and bandwidth ceilings;
explain conceptually how FlashAttention reduces materialized intermediate traffic.

## Exit criteria

Do not move on until you can derive the KV-cache formula and distinguish capacity,
decode traffic, and FlashAttention's training/prefill IO argument.
