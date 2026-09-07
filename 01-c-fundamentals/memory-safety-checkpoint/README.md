# Memory Safety Checkpoint — Repair Your Allocation Exercise

## Objective

Turn the existing `../malloc-free/mallote.c` into reproducible evidence of safe C
ownership. This lab intentionally has no replacement starter: your current source
is the exercise.

## Why this matters for GPU/ML systems

CUDA host code manages several allocations and failure paths at once. A lost host
pointer or invalid copy can make a kernel look broken when the real defect is
lifetime management.

## Prerequisites and reading

- Read the allocation section of Beej's Guide to C: https://beej.us/guide/bgc/
- Read `docs/CURRENT_SKILL_AUDIT.md`, especially the `mallote.c` findings.
- Be able to distinguish an allocation, an owning pointer, and a non-owning alias.

## Coding task

Repair `../malloc-free/mallote.c` incrementally. Before each edit, write the
expected compiler or sanitizer finding in `NOTES.md`. Keep the intended examples:
heap array, alias versus copy, flat matrix, `calloc`, and safe growth with
`realloc`. Do not paste in a replacement program.

## Correctness criteria

- The file compiles as C17 with strict warnings promoted to errors.
- Every allocation failure path is defined.
- No read/write occurs through null, freed, or otherwise invalid storage.
- Every successfully allocated block is freed exactly once.
- The `realloc` failure path retains a reachable original allocation.

## Debugging task

Build and run with ASan/UBSan. After it is clean, deliberately reintroduce one
bug at a time locally, predict the report, observe it, then restore the safe code.

## Exit criteria

Do not proceed until strict compilation and sanitizers are clean and you can draw
the ownership/alias state after each allocation, `free`, and `realloc` call.

## Commands

The installed MSYS2 GCC can perform the strict compile, but this installation does
not currently provide the ASan/UBSan link runtimes. Use it first for diagnostics:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror mallote.c -o mallote.exe
./mallote.exe
```

Run the sanitizer gate in WSL/Linux from the repository root:

```sh
wsl bash -lc 'cd /mnt/m/mlsys/01-c-fundamentals/malloc-free && gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -g3 -fsanitize=address,undefined -fno-omit-frame-pointer mallote.c -o mallote_san && ./mallote_san'
```
