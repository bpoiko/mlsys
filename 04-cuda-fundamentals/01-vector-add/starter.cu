#include <cuda_runtime.h>
#include <cstddef>

__global__ void vector_add(const float *a, const float *b, float *c,
                           std::size_t count) {
    // TODO: compute a global index, guard it, and write one result.
}

int main() {
    // TODO: allocate/init host data; allocate/copy/launch/copy/free device data;
    // verify awkward and non-divisible sizes against a CPU reference.
}
