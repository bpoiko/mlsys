# Questions — RAII and Smart Pointers

1. Why is RAII about invariants, not only memory cleanup?
2. What operations transfer `unique_ptr` ownership?
3. What can still dangle when all owning pointers are smart pointers?
4. Why can reference counting contend across threads?
5. What problem do `weak_ptr` and control blocks address?
6. How would RAII wrap a CUDA allocation whose release function is `cudaFree`?
