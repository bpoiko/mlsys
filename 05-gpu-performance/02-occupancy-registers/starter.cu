#include <cuda_runtime.h>
#include <cstddef>

template <int WorkPerThread>
__global__ void resource_experiment(const float *input, float *output,
                                    std::size_t count) {
    // TODO: perform fixed documented work while varying controlled resources.
}

int main() {
    // TODO: validate variants and print launch/resource configuration.
}
