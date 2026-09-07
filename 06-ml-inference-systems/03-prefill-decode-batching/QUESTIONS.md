# Questions — Prefill, Decode, and Batching

1. How do TTFT and inter-token latency delimit different work?
2. Why is prefill typically more parallel than one-token decode?
3. What does tokens/second hide about individual requests?
4. How does batch size affect weight reuse and KV traffic?
5. What problem does continuous batching address?
6. Which queueing time belongs in user-visible latency?
