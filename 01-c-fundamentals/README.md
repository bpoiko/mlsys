# 01 — C Fundamentals

Objective: make memory behavior predictable before adding C++ abstractions or GPU
memory spaces. Follow this order:

1. `memory-safety-checkpoint` (repair current learner code)
2. `pointers`
3. `arrays-strings`
4. `structs`
5. `malloc-free`
6. `memory-layout`
7. `linked-list` (integration gate)

Every submitted C program must compile under strict warnings and run cleanly under
AddressSanitizer and UndefinedBehaviorSanitizer. A README checkbox is not a pass;
the code and tool output are.
