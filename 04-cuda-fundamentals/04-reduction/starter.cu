#include <cuda_runtime.h>
#include <cstddef>

__global__ void reduce_sum(const float *input, float *partial,
                           std::size_t count) {
    // TODO: produce one partial result per block without invalid synchronization.
}

int main() {
    // TODO: reference-check edge sizes and record repeatable timings.
}
