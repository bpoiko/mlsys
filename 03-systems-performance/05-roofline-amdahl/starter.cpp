#include <cstddef>

double arithmetic_intensity(double operations, double bytes_moved) {
    // TODO: validate units/input and return operations per byte.
}

double roofline_ceiling(double intensity,
                        double peak_ops_per_second,
                        double bandwidth_bytes_per_second) {
    // TODO: calculate the applicable ceiling.
}

double amdahl_speedup(double optimized_fraction, double local_speedup) {
    // TODO: calculate total speedup and handle limiting cases.
}

int main() {
    // TODO: validate hand cases, then model measured kernels.
}
