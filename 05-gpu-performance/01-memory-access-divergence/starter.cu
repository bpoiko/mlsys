#include <cuda_runtime.h>
#include <cstddef>

__global__ void access_experiment(const float *input, float *output,
                                  std::size_t count, int mode) {
    // TODO: implement isolated, correctness-equivalent experiment modes.
}

int main() {
    // TODO: validate modes, benchmark, and emit dimensions/mode with results.
}
