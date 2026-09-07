# Notes — Memory Safety Checkpoint

Write before editing:

- My predicted compiler diagnostics:
- Allocation/owner/alias state at each relevant line:
- What becomes invalid after `free`:
- What remains valid if `realloc` fails:
- Cleanup required on each early-return path:

Evidence after editing:

- Exact compile command and result:
- Exact run command and sanitizer result:
- One deliberately reintroduced bug and the report it produced:
- Why the final version is safe:
