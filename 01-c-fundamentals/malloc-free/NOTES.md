# Notes — Dynamic Allocation

- Contract for `make_array` (inputs, output, ownership, failure):
- Owner and aliases after each statement:
- `calloc` guarantee and what it does not guarantee:
- Safe `realloc` state transition:
- Evidence from warnings/sanitizers/leak checker:


## Allocation and ownership (line 13)
- n is just the number 10, no memory owned
- malloc creates a seperate **heap** allocation large enough for 10 int objects
- a stores the starting address of that allocation
- We can say a is the owner, as the program gives it responsiblity for eventually freeing the allocation; Ownership is more so a programming convetion not C's exclusive tracking

## Freeing and pointer values (lines 19–20)
- `free(a)` ends the heap allocation's lifetime; the pointer variable `a` still exists
- The old bytes might physically remain, but the allocation is no longer valid to access
- a = NULL simply changes the pointer value, doesn't free anything else 

## Pointer copies (line 26)
- b copies the current value in a
- A is already null, b is now null
- b does not refer to a itself, both are independent

## Separate allocation (line 27)
- c = malloc(...) creates another seperate allocation
- c contains the starting address
- c's independent storage comes from the separate allocation, not from a difference in types

## Key notation

- a stored address, type int *
- *a the actual value located at that address, if valid
- &a the address of the pointer variable itself, type int **

Dereferncing does not ask for an address, follows an address to access the object there. You can store an address in a pointer variable. Deref is invalid here because a == NULL, so theres no int object for *a to access

## Correct prediction for the p and q example

- allocate enough memory for one int
- now say follow the address and change the value to 7
- make a int pointer value copy the address from p
- actual varible doesn't point to anything anymore
- q still holds the previously stored address in p
- no nothing had ended we haven't freed a single thing

## Memcpy parameter order
- memcpy(c,a,n * sizeof(int))
- c is the destination: where the bytes go
- a is the source: where the bytes come from
- n * sizeof(int) is the number of bytes to copy-enough for n integers

- Read this as: “Copy n integers' worth of bytes from a into c.” Neither pointer is an end marker.
- In the current file, a has already been freed and set to NULL, so memcpy has no valid source to read from.

## Correct answers from this session

### Shared allocation versus copied contents

Assuming both allocations succeeded and the original `a[0]` is 0:

```c
int *b = a;
memcpy(c, a, n * sizeof *a);
a[0] = 999;
```

**My correct prediction: `b[0]` is 999 and `c[0]` is 0.**

- `b` holds the same heap address as `a`, so both access the changed integer.
- `c` has a separate allocation containing the copied values. Changing `a[0]` does not change `c[0]`.

### Access after freeing

**My correct answer: accessing `b[0]` after `free(a)` is invalid.**

- More precise wording: `b` accesses the same allocation as `a`; it does not access data through the pointer variable `a`.
- `free(a)` ends that shared allocation's lifetime, making `b` a dangling pointer.
- Setting `a = NULL` does not change `b` or make it safe to use.
- `c[0]` remains valid because its separate allocation is still alive. That allocation needs its own cleanup too.

## Clarifications reinforced during this session

- `int *b = a` copies the value of `a` at that moment. If `a` is NULL, `b` receives NULL. Assigning a new allocation to `a` later does not update `b`.
- I correctly recognized that `a[0] = 999` is invalid after `free(a); a = NULL;`.
- The follow-up clarification: delaying only `a = NULL` does not fix that access. **`free(a)` itself ends the allocation's lifetime.**
- Place `free(a)` after the last use of the allocation through `a` or any alias, including `b`.
- Setting a pointer to NULL does not free memory. Discarding the last pointer to a live allocation causes a memory leak.

## Next practice

- Repair `mallote.c` incrementally using these lifetime rules.
- Complete the ownership, allocation failure, `calloc`, and `realloc` notes listed at the top.
- Strict C17 compilation passed on 2026-09-07; sanitizer completion is still pending.

## Session wrap-up — 2026-09-07

- `calloc(count, size)` allocates storage and zeros every byte; the integers in this exercise start at 0.
- `realloc` with a positive size preserves the original allocation on failure. My correct prediction: assigning its NULL result directly to `a` loses the original address and leaks the allocation.
- The repaired code uses `tmp`, frees the original allocation and exits on failure, and assigns `a = tmp` only on success. It frees the resized allocation afterward.
- Newly added space from growing with `realloc` is uninitialized, even if the original allocation came from `calloc`.
- `make_array` returns an `int *`, so its failure result is `NULL`; `main` returns an integer exit status such as 1.
- `free(NULL)` is harmless but unnecessary. After `p = NULL`, `q` still reaches the allocation and can free it.

### Manual build and run (from the repository root)

```sh
clang -std=c17 -Wall -Wextra -Wpedantic -Werror -g 01-c-fundamentals/malloc-free/mallote.c -o /tmp/mlsys-mallote-plain
/tmp/mlsys-mallote-plain
```

- Strict compilation and the ordinary run passed (exit status 0).
- Observed the shared/copy values 999 and 0, then ten zeros from `calloc`.
- The initial `7` and first array value `0` print together as `70`; add a newline to the `q` print for readability.
- An ASan/UBSan build succeeded, but its run did not promptly return; no sanitizer pass or leak-check pass is claimed.
- `make_array` is not called by `main`, so this run does not test its input contract or edge cases.
