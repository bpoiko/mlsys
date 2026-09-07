# Current Skill Audit

Audit basis: every repository file and README, the directory tree, compiler
diagnostics, and all six commits through `f66f18d` were inspected. Generated
`.exe`/`.o` files were inventoried but are not evidence of source-level mastery.
Unchecked future scaffolds added after this audit are also not evidence.

## Demonstrated

- **Basic pointer use:** `pointers.c` takes an address, stores it in `int *`,
  dereferences it for reading and writing, and prints addresses using `%p` with a
  `void *` cast.
- **Mutation through pointer parameters:** `swap(int *, int *)` now swaps values
  correctly. Git history is useful evidence here: commit `f66f18d` replaces an
  incorrect pointer-typed temporary with a value temporary.
- **Basic array/pointer relationship:** arrays are assigned to element pointers,
  and the code forms pointers to later elements with addition and `&array[i]`.
- **Basic heap workflow:** `mallote.c` allocates an integer array, checks that one
  allocation, indexes/fills it, frees it, and clears that local pointer.
- **Flat row-major indexing:** the matrix write `m[i * cols + j]` and its learner
  comment correctly express how complete rows are skipped.
- **Initial ownership insight:** the comment on returning heap storage from
  `make_array` correctly notes that the allocation outlives the function call.

These are narrow demonstrations. They do not imply that the entire corresponding
README checklist is complete.

## Developing

- **Pointer arithmetic:** correct expressions appear, but the results are mostly
  unused and unverified. The code does not yet demonstrate pointer subtraction,
  a full pointer-only traversal, or portable reasoning in units of elements.
- **Null checking:** one allocation and one pointer are checked, but checks are
  inconsistent and sometimes occur after the program has already assumed the
  pointer is valid.
- **Ownership and aliases:** comments recognize that two pointers can name one
  allocation, but the executable sequence does not actually establish that alias
  after `a` is set to `NULL`.
- **Dynamic allocation APIs:** `malloc`, `calloc`, `realloc`, and `free` are all
  mentioned or called. Safe failure handling, retained ownership, cleanup on every
  path, and post-`realloc` initialization are not yet demonstrated.
- **C debugging discipline:** the README reports sanitizer success, but the
  checked-in allocation source does not compile under the requested warning set,
  so a clean current sanitizer run is not reproducible. The available MSYS2 GCC
  also lacks its ASan/UBSan link runtimes; use WSL/Linux for the sanitizer gate.

## Not Yet Demonstrated

Mentioned in existing READMEs but lacking checked-in implementation evidence:

- C strings and string functions, array decay/`sizeof`, 2D traversal comparisons,
  structs, padding/alignment experiments, linked lists, deletion, and whole-list
  cleanup.
- Double pointers and output parameters. The pointers README says these were done
  elsewhere, but no implementation exists in this repository.
- CUDA toolchain use, kernels, indexing, host/device allocation and copies, bounds
  checks, error handling, naive/tiled matrix multiplication, or CUDA-event timing.
- Benchmark sampling, variance, GFLOP/s or GB/s calculations, Roofline reasoning,
  profiling evidence, and before/after performance explanations.
- Any ML workload or verified reference comparison.

Completely absent before this restructuring:

- Modern C++ implementation: references, const correctness, classes, RAII, smart
  pointers, STL, templates/lambdas, copy/move semantics, threads, mutexes, atomics,
  and cache-conscious C++ structures.
- CPU architecture/performance implementation: cache/TLB experiments, virtual
  memory observation, compiler-level comparisons, Linux `perf`, SIMD, branches,
  Amdahl's Law, and quantitative arithmetic-intensity/Roofline work.
- GPU-performance implementation: warps/SIMT experiments, coalescing, divergence,
  occupancy/register analysis, reductions, softmax, fusion, streams, and Nsight.
- ML-inference-systems implementation: transformer execution accounting, attention
  variants, KV-cache traffic, prefill/decode metrics, batching, precision and
  quantization tradeoffs, PyTorch profiling, and continuous batching.

## Bugs/Misconceptions Worth Revisiting

Do not treat this list as a patch. Predict each diagnostic or failure before
changing the learner source.

### `01-c-fundamentals/pointers/pointers.c`

- A trailing `\` on the pointer-size comment splices the following source line,
  producing `-Wcomment` and hiding the next comment during preprocessing.
- The comment that `ptr2++` still points to the first element is inconsistent with
  the operation; the subsequent decrement masks the reasoning error.
- Comments state fixed byte sizes for `int` and `double`. Those sizes are common,
  not guaranteed by C; pointer arithmetic should be explained in elements and
  `sizeof(*ptr)`.
- Several variables are never used, so the examples do not prove their claims and
  fail a warning-clean gate.
- `swap` is correct but never called. Pointer subtraction, double pointers, and the
  claimed output-parameter exercises are not demonstrated.
- `char lmfao[4]` contains four characters but no null terminator. That is a valid
  byte array, but it must not be treated as a C string.

### `01-c-fundamentals/malloc-free/mallote.c`

- `memcpy` is used without its declaring header. Strict compilation diagnoses an
  implicit declaration.
- `a` is declared twice in the same scope, which is a compilation error.
- `make_array` dereferences `p` without handling allocation failure. It is never
  called, so its ownership contract and cleanup are not exercised.
- After `free(a); a = NULL;`, assigning `b = a` makes `b` null—it does not create
  the alias described by the comment. `memcpy(c, a, ...)` then reads from a null
  source, and `a[0] = 999` dereferences null: undefined behavior.
- Allocation of `c`, `m`, and the `calloc` result is not checked. `c` is never
  freed; the final allocation is also not freed on success.
- The `realloc` temporary is the right starting pattern, but failure handling then
  assigns `a = tmp` anyway, losing the original allocation and leaking it. The
  message `"valid"` does not establish which pointer remains valid.
- Size products are not guarded against invalid/negative counts or overflow. The
  constants happen to be small, but the reusable reasoning is missing.
- Successful `realloc` growth does not initialize the newly added elements.

### Repository evidence hygiene

- `mallote.exe`, `mallote.o`, and `pointers.exe` are present locally despite being
  ignored. They are not tracked and do not provide reproducible test evidence.
- Historical README checkboxes assert more than the checked-in code proves. Future
  progress is therefore tracked separately in `PROGRESS.md` using implementation
  and measurement evidence.

## Recommended Next Exercise

Complete `01-c-fundamentals/memory-safety-checkpoint` by repairing your existing
`malloc-free/mallote.c` yourself. First capture strict compiler output; then make
one ownership/lifetime correction at a time; finally run AddressSanitizer and
UndefinedBehaviorSanitizer. Do not add new features yet. The gate is warning-clean
compilation, sanitizer-clean execution, no leaks, and a written explanation of
who owns every allocation on every success/failure path.
