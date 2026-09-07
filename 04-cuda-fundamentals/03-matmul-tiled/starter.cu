#include <cuda_runtime.h>
#include <cstddef>

template <int Tile>
__global__ void matmul_tiled(const float *a, const float *b, float *c,
                             std::size_t m, std::size_t n, std::size_t k) {
    // TODO: cooperatively load guarded tiles, synchronize, accumulate, and store.
}

int main() {
    // TODO: compare against CPU and naive GPU references for awkward shapes.
}
