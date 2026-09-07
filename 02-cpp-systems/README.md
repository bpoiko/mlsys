# 02 — Modern C++ Systems Programming

Order: language foundations → RAII/smart pointers → containers/generic code →
copy/move lifetime → concurrency/cache. The target is explicit, reviewable
ownership and predictable performance—not syntax coverage.

Use C++20, strict warnings, and sanitizers. Keep each ownership decision in your
notes. `std::shared_ptr` is a reasoning exercise unless shared lifetime is truly
required.
