# Resume here: finish memory safety, then pointers

Session bookmark — 2026-09-07.

Today you repaired mallote.c incrementally: live source before memcpy, one free
per allocation, allocation failure checks, calloc, and safe realloc cleanup.
You correctly predicted b[0] == 999 and c[0] == 0, explained why b becomes
invalid after free(a), and recognized the leak caused by losing the original
pointer when realloc fails.

Strict C17 compilation and an ordinary run passed. The ASan/UBSan build
succeeded, but its run did not promptly return; the sanitizer gate remains
pending. Commands and observed output are in malloc-free/NOTES.md.

Start next session:
1. Add a newline to the printf for *q so 7 and the next 0 print separately.
2. Finish the sanitizer investigation and ownership/failure-path notes in
   01-c-fundamentals/memory-safety-checkpoint/NOTES.md. Do not mark the checkpoint
   complete yet. Define and exercise make_array's input contract too; main does
   not currently call it.
3. After the checkpoint, resume 01-c-fundamentals/pointers/pointers.c. Start by
   predicting age and *ptr before and after *ptr = 44, then call the existing
   swap function on two integers and print their values before and after.
   Compile with strict warnings and repair diagnostics incrementally.

Preserve the learner implementation; do not replace it with a completed solution.
