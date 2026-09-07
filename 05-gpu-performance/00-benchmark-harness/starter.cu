#include <cuda_runtime.h>
#include <cstddef>
#include <vector>

struct GpuTimingSummary {
    float median_ms;
    float minimum_ms;
    float variance_ms_squared;
};

GpuTimingSummary benchmark_gpu(void (*launch)(cudaStream_t),
                               std::size_t warmups,
                               std::size_t samples,
                               cudaStream_t stream) {
    // TODO: time completed GPU work with events and summarize samples.
}

int main() {
    // TODO: validate the harness on a reference-checked kernel.
}
