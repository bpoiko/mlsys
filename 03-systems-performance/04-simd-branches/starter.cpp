#include <cstddef>
#include <span>

void transform_scalar(std::span<const float> input, std::span<float> output) {
    // TODO: implement the baseline without disabling normal compiler optimization.
}

void transform_candidate(std::span<const float> input, std::span<float> output) {
    // TODO: implement a correctness-equivalent vectorization candidate.
}

int main() {
    // TODO: validate tails and run controlled data-distribution experiments.
}
