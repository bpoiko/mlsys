#include <cstddef>
#include <span>

class BufferView {
public:
    BufferView(float *data, std::size_t size);
    std::size_t size() const;
    float &at(std::size_t index);
    const float &at(std::size_t index) const;

private:
    float *data_;
    std::size_t size_;
};

int main() {
    // TODO: implement and test mutable and const views plus lifetime tracing.
}
