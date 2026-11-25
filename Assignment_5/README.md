# Assignment 5 – CO5 C++ Reference Pack

Folders:
- PartA_Design/Design_Answers.md: Part A written design, UML, pseudocode, binding, exception strategy and complexity notes.
- TaskB1/billing.cpp: polymorphic bill hierarchy, four bill types and payer classes; completes TODO 1–3.
- TaskB2/exceptions.cpp: claim validation, catch/rethrow, conversion and allocation error demonstrations; completes TODOs.
- TaskB3/benchmark.cpp: virtual vs switch vs variant timing; return-code vs exception validation timing.
- TaskB4/production.cpp: extension with DayCareBill and CorporatePayer plus RAII recovery demonstration.

Compile separately with:
`g++ -std=c++17 -Wall -Wextra path/to/file.cpp -o program`
For B3 use `g++ -std=c++17 -O2 -Wall -Wextra TaskB3/benchmark.cpp -o benchmark`.
For sanitizer tests, where supported: `g++ -std=c++17 -g -fsanitize=address -fno-omit-frame-pointer ...`.

Run each program, take your own screenshots, record compiler/version and actual timings, and complete the required GitHub commits. Make your output predictions before running. Timings are machine-dependent; no fabricated measurements are included.
