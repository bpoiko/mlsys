# Questions — Tiled Matmul

1. Which values are reused by which threads?
2. Why are barriers required before consuming and overwriting a tile?
3. Why must all threads reach a block barrier consistently?
4. How do guarded loads handle partial tiles?
5. What limits tile size besides thread count?
6. Why can a correct tiled kernel still be slower?
