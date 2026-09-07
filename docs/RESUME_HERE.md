# Resume here: C memory lifetime

Session bookmark (mentor summary, not a completed implementation gate).

You correctly predicted that copying p into q copies the address, and that
setting p to NULL leaves q pointing to the still-live allocation. You also
distinguished freeing an allocation from setting a pointer variable to NULL.

Reinforce next time:
- malloc(sizeof *p) allocates space for one int when p has type int *.
- free ends the allocated object's lifetime; it does not guarantee erased bytes.
- The address stored in p is different from the address of p itself (&p).
- A separate malloc call explains c's separate allocation.

Next task: open 01-c-fundamentals/malloc-free/mallote.c and explain in your own
notes why memcpy(c, a, ...) cannot safely read its source after the earlier
free(a) and a = NULL. Predict before editing.

The allocation exercise is still in progress. Strict compilation and sanitizer
gates have not been passed. Preserve the learner implementation and repair it
incrementally; do not replace it with a completed solution.
