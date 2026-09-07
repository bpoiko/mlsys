#include <cstddef>

std::size_t kv_cache_bytes(std::size_t batch, std::size_t layers,
                           std::size_t context, std::size_t kv_heads,
                           std::size_t head_dimension,
                           std::size_t bytes_per_element) {
    // TODO: derive the K-and-V cache capacity with overflow checks.
}

int main() {
    // TODO: compare MHA/GQA/MQA configurations and context-length sweeps.
}
