#include <cstddef>
#include <cstdint>
#include <span>

struct QuantizedBuffer {
    // TODO: store quantized values plus metadata required for dequantization.
};

QuantizedBuffer quantize_int8(std::span<const float> input) {
    // TODO: define and implement a scale/clipping policy.
}

int main() {
    // TODO: adversarial correctness/error tests and footprint/timing comparison.
}
