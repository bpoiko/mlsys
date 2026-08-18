# malloc / free (Dynamic Memory)

**Goal:** Allocate memory on the heap at runtime, use it, and free it — without leaks or use-after-free bugs. This is the single most important C skill for the CUDA work later.

## Concepts
- [x] Stack vs. heap — lifetime and who cleans up
- [x] `malloc(n)` returns a `void*` to `n` uninitialized bytes (or `NULL`)
- [x] Always check the return value for `NULL`
- [x] `sizeof` when sizing allocations: `malloc(n * sizeof(int))`
- [x] `free` exactly once; then set the pointer to `NULL`
- [x] `calloc` (zeroed) and `realloc` (grow/shrink)
- [x] Memory leaks — allocating without freeing
- [x] Dangling pointers / use-after-free / double-free
- [x] Returning heap memory from a function (ownership)

## Exercises
- [x] Allocate an `int` array of size `n` read from the user, fill and print it -<> alter done
- [x] Write `int* make_range(int n)` that returns a heap array `0..n-1` alternate done here too
- [x] Grow an array with `realloc` as you read unknown-length input
- [x] Deliberately create a leak, then find it with a tool (below)

## Tooling (do this early!)
- [x] Run every exercise under a memory checker:
  - Linux/WSL: `valgrind --leak-check=full ./a.out`
  - Or compile with sanitizers: `gcc -fsanitize=address,undefined -g file.c`
- [x] On Windows: easiest path is WSL, or clang with `-fsanitize=address` so useful..

## Resources
- Beej's Guide — ch. 12 (Manual Memory Allocation)
- Valgrind quick start: https://valgrind.org/docs/manual/quick-start.html

## Done when
- [x] A program allocates, uses, and frees memory with a **clean** Valgrind/ASan report
- [x] I can explain leak vs. dangling pointer vs. double-free
