#include <cstddef>
#include <memory>

class OwnedBuffer {
public:
    explicit OwnedBuffer(std::size_t count);
    float *data();
    const float *data() const;
    std::size_t size() const;

private:
    // TODO: choose representation that expresses unique ownership.
};

int main() {
    // TODO: test empty/non-empty lifetime and an early-return path.
}
