# mlsys — C → CUDA → ML Systems Learning Path

A hands-on path from C fundamentals to writing and benchmarking GPU kernels for machine learning. Each folder has its own `README.md` with a checkbox plan, exercises, and resources.

## Roadmap

### 01 — C Fundamentals
The memory-management foundation everything else builds on.
- [ ] [pointers](01-c-fundamentals/pointers/README.md)
- [ ] [arrays-strings](01-c-fundamentals/arrays-strings/README.md)
- [ ] [structs](01-c-fundamentals/structs/README.md)
- [ ] [malloc-free](01-c-fundamentals/malloc-free/README.md)
- [ ] [linked-list](01-c-fundamentals/linked-list/README.md) *(combines the four above)*

### 02 — CUDA Fundamentals
Learn the GPU programming model, then build up to a fast matmul.
- [ ] [00-smoke-test](02-cuda-fundamentals/00-smoke-test/README.md)
- [ ] [01-vector-add](02-cuda-fundamentals/01-vector-add/README.md)
- [ ] [02-matmul-naive](02-cuda-fundamentals/02-matmul-naive/README.md)
- [ ] [03-matmul-tiled](02-cuda-fundamentals/03-matmul-tiled/README.md)

### 03 — [Benchmark Harness](03-benchmark-harness/README.md)
Measure kernel performance correctly (GFLOP/s, GB/s, roofline).

### 04 — [ML Capstone](04-ml-capstone/README.md)
Combine everything into a real ML workload (toward llm.c).

## Order
Work top to bottom. Within `01`, do pointers/structs/malloc before linked-list.
Within `02`, do them in numeric order. Build `03` once you have a kernel worth
timing (after `02-matmul-naive`), then reuse it throughout `02` and `04`.

## Core references
- **Beej's Guide to C** — https://beej.us/guide/bgc/
- **NVIDIA "Even Easier Introduction to CUDA"** — https://developer.nvidia.com/blog/even-easier-introduction-cuda/
- **Simon Boehm, "How to Optimize a CUDA Matmul Kernel"** — https://siboehm.com/articles/22/CUDA-MMM
- **Programming Massively Parallel Processors (PMPP)**, Kirk & Hwu
- **karpathy/llm.c** — https://github.com/karpathy/llm.c
