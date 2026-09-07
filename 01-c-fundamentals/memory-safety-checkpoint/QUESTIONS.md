# Questions — Memory Safety Checkpoint

1. Does assigning `NULL` to one pointer modify another pointer that aliases the same block?
2. Which expressions remain valid immediately after `free(p)`?
3. Why can direct assignment of `realloc`'s return value lose an allocation?
4. On failed `realloc`, who still owns the original block?
5. What must be checked before multiplying an element count by an element size?
6. Why is `free(NULL)` valid but dereferencing `NULL` undefined?
7. What contract should a function returning heap memory document?
8. Why is a clean compile necessary but insufficient evidence of memory safety?
