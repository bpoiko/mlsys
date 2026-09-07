#include <cstddef>
#include <string_view>

struct ModelConfig {
    std::size_t layers;
    std::size_t hidden;
    std::size_t intermediate;
    std::size_t query_heads;
    std::size_t kv_heads;
    std::size_t head_dimension;
    std::size_t bytes_per_element;
};

struct Cost {
    double operations;
    double bytes;
};

Cost linear_cost(std::size_t tokens, std::size_t input_features,
                 std::size_t output_features, std::size_t bytes_per_element) {
    // TODO: state and implement an explicit traffic model.
}

int main() {
    // TODO: account for one layer and full-model prefill/decode workloads.
}
