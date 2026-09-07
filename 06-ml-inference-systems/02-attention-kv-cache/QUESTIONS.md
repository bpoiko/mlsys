# Questions — Attention and KV Cache

1. Why can query-head count differ from KV-head count?
2. Which dimensions grow with context length during decode?
3. Why is KV capacity proportional to layers and batch?
4. What bandwidth is consumed for one new token under your model?
5. What quality/parallelism tradeoff can KV-head sharing introduce?
6. What intermediate traffic does FlashAttention avoid materializing?
