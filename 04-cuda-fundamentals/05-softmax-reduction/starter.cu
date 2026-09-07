#include <cuda_runtime.h>
#include <cstddef>

__global__ void row_softmax(const float *input, float *output,
                            std::size_t rows, std::size_t columns) {
    // TODO: compute stable row-wise softmax for arbitrary column counts.
}

int main() {
    // TODO: implement adversarial CPU-reference tests before benchmarking.
}
