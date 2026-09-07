#include <cuda_runtime.h>
#include <cstddef>

__global__ void matmul_naive(const float *a, const float *b, float *c,
                             std::size_t m, std::size_t n, std::size_t k) {
    // TODO: compute one C(row,col) for general MxK and KxN shapes.
}

int main() {
    // TODO: test small hand cases and non-divisible rectangular dimensions,
    // compare against a CPU reference, then measure larger cases.
}
