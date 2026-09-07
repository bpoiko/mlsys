#include <cuda_runtime.h>
#include <cstddef>

// TODO: declare separate bias/activation/scale kernels.

__global__ void fused_transform(const float *input, const float *bias,
                                float *output, std::size_t count) {
    // TODO: implement the identical composed operation in one kernel.
}

int main() {
    // TODO: verify both paths before measuring traffic and time.
}
