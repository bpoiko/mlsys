# Lab 01 — Transformer Execution Accounting

## Objective

Trace a decoder-only transformer forward pass at systems level: tensor shapes,
matrix multiplies, elementwise operations, reductions, FLOPs, and byte traffic.

## Why this matters for GPU/ML systems

Optimization begins with knowing which tensors and kernels exist, how often they
run, and what hardware resources they demand.

## Prerequisites and reading

GPU performance stage. Read the architecture/forward-pass section of a decoder-only
transformer reference and PyTorch documentation for linear algebra shapes.

## Coding task

Complete `starter.cpp` as an accounting tool for a small model configuration. Print
operation names, input/output shapes, estimated FLOPs, parameter bytes, and activation
bytes for one layer and the full model. Validate small cases by hand.

## Correctness criteria

Every symbol has a defined unit and shape convention; tied embeddings, bias choices,
batch, sequence length, and precision are explicit.

## Performance task

Calculate arithmetic intensity for major operations and predict which change between
prefill and one-token decode.

## Exit criteria

Do not move on until you can narrate the forward pass without framework names and
derive the dimensions of each major matrix multiplication.
