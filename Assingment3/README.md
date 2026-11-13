# Assignment 3 — CO3 (C++ Constructors, Destructors and Operator Overloading)

Student: [Fill your name]
Register Number: [Fill your register number]
Repository: `DSA01-<RegisterNumber>-Assignment3`
Compiler: [Record your installed g++ version]
Standard: C++17

## Compile and run
Compile each source separately because each contains its own `main()`:
`g++ -std=c++17 -Wall -Wextra Task01/task01_constructors.cpp -o task01`
Then run `./task01` (Windows: `task01.exe`).

## Task files
- Task01: default, overloaded, delegating and parameterized constructors; invalid copies rejected.
- Task02: Prescription deep copy, copy assignment, destructor and self-assignment.
- Task03: dynamic two-dimensional seat allocation, booking/canceling and destructor order.
- Task04: Money arithmetic, comparison and stream insertion.
- Task05: prefix/postfix increment, Time comparisons and checked Playlist subscript.
- Task06: Text class Rule of Three, concatenation and comparison.
- Task07: Complex arithmetic and AC impedance series/parallel calculations.

## Important submission evidence
Run every program yourself. Save genuine terminal screenshots in each Task folder. Run Q2, Q3 and Q6 with AddressSanitizer if your compiler supports it, e.g.:
`g++ -std=c++17 -Wall -Wextra -fsanitize=address -g Task02/task02_deep_copy.cpp -o task02_asan`
Record the actual compiler version, actual run output, sanitizer output and measured timings. Do not claim tests or timings are completed until you run them.

Make at least one progressive Git commit per task. Add your faculty-approved details and GitHub URL to the report. The assignment asks for a public repository or private repository with faculty as collaborator.
