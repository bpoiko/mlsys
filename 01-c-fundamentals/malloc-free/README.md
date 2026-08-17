# malloc / free (Dynamic Memory)

**Goal:** Allocate memory on the heap at runtime, use it, and free it — without leaks or use-after-free bugs. This is the single most important C skill for the CUDA work later.

## Concepts
- [ ] Stack vs. heap — lifetime and who cleans up
- [ ] `malloc(n)` returns a `void*` to `n` uninitialized bytes (or `NULL`)
- [ ] Always check the return value for `NULL`
- [ ] `sizeof` when sizing allocations: `malloc(n * sizeof(int))`
- [ ] `free` exactly once; then set the pointer to `NULL`
- [ ] `calloc` (zeroed) and `realloc` (grow/shrink)
- [ ] Memory leaks — allocating without freeing
- [ ] Dangling pointers / use-after-free / double-free
- [ ] Returning heap memory from a function (ownership)

## Exercises
- [ ] Allocate an `int` array of size `n` read from the user, fill and print it
- [ ] Write `int* make_range(int n)` that returns a heap array `0..n-1`
- [ ] Grow an array with `realloc` as you read unknown-length input
- [ ] Deliberately create a leak, then find it with a tool (below)

## Tooling (do this early!)
- [ ] Run every exercise under a memory checker:
  - Linux/WSL: `valgrind --leak-check=full ./a.out`
  - Or compile with sanitizers: `gcc -fsanitize=address,undefined -g file.c`
- [ ] On Windows: easiest path is WSL, or clang with `-fsanitize=address`

## Resources
- Beej's Guide — ch. 12 (Manual Memory Allocation)
- Valgrind quick start: https://valgrind.org/docs/manual/quick-start.html

## Done when
- [ ] A program allocates, uses, and frees memory with a **clean** Valgrind/ASan report
- [ ] I can explain leak vs. dangling pointer vs. double-free
