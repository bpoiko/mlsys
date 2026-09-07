# History and Preservation Notes

The original curriculum state remains available in Git at commit `f66f18d`.
Useful inspection commands:

```sh
git show f66f18d:README.md
git show f66f18d:01-c-fundamentals/pointers/pointers.c
git show f66f18d:01-c-fundamentals/malloc-free/mallote.c
```

During the curriculum restructuring:

- The learner-written `pointers.c` and `mallote.c` were not edited.
- Existing unit READMEs were kept byte-for-byte and moved with their stages.
- `02-cuda-fundamentals` became `04-cuda-fundamentals`.
- `03-benchmark-harness` became `05-gpu-performance/00-benchmark-harness`.
- `04-ml-capstone` became `07-ml-capstone`.
- The root README was replaced with the new entry point; its prior version remains
  directly recoverable with the command above.
- Ignored learner-local build artifacts were neither deleted nor treated as proof
  of completion.
