# 04 — ML Capstone

**Goal:** Put the whole path together — C + CUDA kernels + benchmarking — into a real ML workload. Aim for something you can point at and say "I built the compute for this from scratch."

## Pick a target (choose one)
- [ ] **A single neural-net layer forward pass** in CUDA (linear → ReLU), verified vs. a NumPy/PyTorch reference
- [ ] **A full MLP** (2–3 layers) doing inference on a small dataset (e.g. MNIST)
- [ ] **Reproduce/study karpathy/llm.c** — GPT-2 forward pass in C/CUDA (most ambitious)

## Concepts to pull together
- [ ] Matmul is the workhorse — reuse your tiled kernel
- [ ] Fused elementwise kernels (bias add, activation) to avoid extra passes
- [ ] Reductions (sum/max) for softmax, loss, normalization
- [ ] Numerical stability (softmax max-subtraction; float vs. double)
- [ ] Memory management across many buffers (weights, activations)
- [ ] Verify EVERY kernel against a trusted CPU/NumPy reference
- [ ] Benchmark end-to-end with your `03-benchmark-harness`

## Milestones
- [ ] Load weights + input into device memory
- [ ] Forward pass producing correct outputs (match reference within tolerance)
- [ ] Profile it; find the bottleneck kernel
- [ ] Optimize the bottleneck; record before/after GFLOP/s
- [ ] (Stretch) backward pass / training loop

## Resources
- karpathy/llm.c: https://github.com/karpathy/llm.c
- Karpathy "Neural Networks: Zero to Hero": https://karpathy.ai/zero-to-hero.html
- PMPP later chapters (convolution, reductions, primitives)
- NVIDIA CUTLASS (aspirational production matmul): https://github.com/NVIDIA/cutlass
- FlashAttention (stretch; read the paper first): https://github.com/Dao-AILab/flash-attention

## Done when
- [ ] My kernels produce correct ML outputs vs. a reference implementation
- [ ] I've profiled, optimized one bottleneck, and can explain the speedup
