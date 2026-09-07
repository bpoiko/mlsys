#include <chrono>
#include <cstddef>
#include <functional>
#include <vector>

struct Summary {
    double median_seconds;
    double minimum_seconds;
    double variance_seconds_squared;
};

Summary benchmark(const std::function<void()> &work,
                  std::size_t warmups,
                  std::size_t samples) {
    // TODO: collect and summarize independent timed samples.
}

int main() {
    // TODO: validate statistics and benchmark non-removable work.
}
