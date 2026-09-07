#include <cstddef>
#include <vector>

struct RequestTrace {
    double arrival_ms;
    std::vector<double> token_ready_ms;
};

// TODO: define a Metrics result type with TTFT, inter-token latency, and throughput.
// TODO: implement metric calculation from explicit trace events.

int main() {
    // TODO: validate on hand-computed traces, then analyze a batch sweep.
}
