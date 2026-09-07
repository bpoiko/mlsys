# Questions — Dynamic Allocation

1. What is the lifetime of an allocated object versus its pointer variables?
2. Why does setting an owner to `NULL` not repair dangling aliases?
3. What is the portable allocation-size idiom when the pointee type changes?
4. What are the success and failure postconditions of `realloc`?
5. How can integer overflow make a bounds-checked loop unsafe?
6. Who frees memory returned by a factory function?
