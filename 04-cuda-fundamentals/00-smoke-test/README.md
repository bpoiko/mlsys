# 00 — Smoke Test

**Goal:** Prove the toolchain works: compiler installed, GPU visible, a kernel can launch. Do this before anything else so later bugs are *your* bugs, not setup bugs.

## Checklist
- [ ] `nvidia-smi` runs and shows my GPU + driver version
- [ ] `nvcc --version` runs (CUDA Toolkit installed)
- [ ] Compile and run `deviceQuery` (from CUDA Samples) — note down:
  - [ ] GPU name + compute capability (e.g. `sm_86`)
  - [ ] Number of SMs
  - [ ] Max threads per block (usually 1024)
  - [ ] Shared memory per block
- [ ] Write and run a "hello from GPU" kernel that `printf`s from each thread
- [ ] Confirm I understand `<<<blocks, threads>>>` launch syntax
- [ ] Learn to compile: `nvcc file.cu -o file` and run it

## Concepts
- [ ] Host (CPU) vs. device (GPU) code; `__global__` marks a kernel
- [ ] `cudaDeviceSynchronize()` — GPU work is async
- [ ] `threadIdx`, `blockIdx`, `blockDim` and how they form a global index
- [ ] Always check errors: wrap calls, check `cudaGetLastError()`

## Resources
- NVIDIA "An Even Easier Introduction to CUDA": https://developer.nvidia.com/blog/even-easier-introduction-cuda/
- CUDA Samples (deviceQuery): https://github.com/NVIDIA/cuda-samples
- CUDA C++ Programming Guide (Programming Model section)

## Done when
- [ ] A GPU kernel prints its thread index and the program exits cleanly
- [ ] I've recorded my GPU's key specs for later occupancy math
