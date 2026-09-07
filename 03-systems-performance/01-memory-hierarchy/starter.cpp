#include <cstddef>
#include <cstdint>
#include <span>

std::uint64_t traverse(std::span<const std::uint32_t> data,
                       std::size_t stride_elements) {
    // TODO: implement a bounds-safe traversal and stable checksum.
}

int main() {
    // TODO: sweep working-set sizes and strides; print machine-readable results.
}
