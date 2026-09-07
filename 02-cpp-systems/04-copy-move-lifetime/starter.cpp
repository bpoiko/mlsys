#include <cstddef>

class TraceBuffer {
public:
    explicit TraceBuffer(std::size_t count);
    ~TraceBuffer();

    // TODO: declare the copy/move policy you choose.

private:
    float *data_ = nullptr;
    std::size_t size_ = 0;
};

int main() {
    // TODO: test construction, chosen copy/move operations, and destruction.
}
