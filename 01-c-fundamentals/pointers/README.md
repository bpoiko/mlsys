# Pointers

**Goal:** Understand what a pointer is, how memory addresses work, and how to read/write through pointers without crashing.

## Concepts
- [x] Variables live at memory addresses (`&x` gives the address)
- [x] A pointer is a variable that stores an address (`int *p = &x;`)
- [x] Dereferencing: `*p` reads/writes the value at that address
- [x] `NULL` pointers and why you must check them
- [x] Pointer types matter (`int*` vs `char*`) — the type sets the step size
- [x] Pointer arithmetic (`p + 1` moves by `sizeof(*p)` bytes)
- [ ] Passing by pointer to let a function modify the caller's variable
- [ ] Correct format specifiers: `%d` for `int`, `%p` for a pointer
- [ ] Double pointers (`int **`) — a pointer to a pointer

## Exercises
- [x] Fix `pointers.c`: `printf("%p", age)` should print `&age`, not `age`
- [x] Write `swap(int *a, int *b)` that swaps two ints via pointers
- [ ] Write a function that returns min AND max via output pointers
- [ ] Walk an array using only a pointer (no `[]` indexing)
- [ ] Print each element's address to see `sizeof` stride in action

## Resources
- Beej's Guide to C — ch. 6 (Pointers): https://beej.us/guide/bgc/html/split/pointers.html
- Stanford "Pointers and Memory" (Nick Parlante): http://cslibrary.stanford.edu/102/
- K&R ch. 5

## Done when
- [ ] I can explain the difference between `p`, `*p`, and `&p` out loud
- [ ] `swap` works and I understand *why* passing by value wouldn't
