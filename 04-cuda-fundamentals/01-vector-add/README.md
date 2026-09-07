# 01 — Vector Add

**Goal:** The "hello world" of CUDA. Learn the full host workflow: allocate on GPU, copy in, launch, copy out, free. `C[i] = A[i] + B[i]`.

## Concepts
- [ ] `cudaMalloc` / `cudaFree` (device memory) vs. `malloc`/`free` (host)
- [ ] `cudaMemcpy` with `HostToDevice` and `DeviceToHost`
- [ ] Mapping one thread to one element: `int i = blockIdx.x * blockDim.x + threadIdx.x`
- [ ] The bounds guard: `if (i < n)` (array size rarely divides evenly)
- [ ] Choosing grid size: `blocks = (n + threads - 1) / threads`
- [ ] Verifying GPU result against a CPU reference loop
- [ ] Error checking after `cudaMemcpy` and kernel launch

## Exercises
- [ ] Implement vector add end-to-end for `n = 1<<20`
- [ ] Verify against a CPU loop (max abs error should be 0)
- [ ] Try thread counts 128/256/512 and note if timing changes
- [ ] Deliberately remove the `if (i < n)` guard with a non-divisible `n` and observe the bug
- [ ] Stretch: SAXPY (`y = a*x + y`)

## Resources
- NVIDIA "An Even Easier Introduction to CUDA": https://developer.nvidia.com/blog/even-easier-introduction-cuda/
- CUDA C++ Programming Guide — Programming Model + Memory
- PMPP (Kirk & Hwu) ch. 2–3

## Done when
- [ ] GPU output matches CPU reference exactly
- [ ] I can explain the global-index formula and the bounds guard
