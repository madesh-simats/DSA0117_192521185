# Assignment 4 – C++ Solutions (CO4)

These are task-wise C++17 reference implementations based on the uploaded Assignment 4 PDF.
They cover the main implementation requirements for Tasks 1–6. Read the source comments and
adapt the report explanations, output screenshots, and your own GitHub submission before submitting.

## Compile
Use g++ 13 (or another C++17-compatible compiler):

```bash
g++ -std=c++17 -Wall -Wextra Task01/task01.cpp -o task01
```

Run on Windows PowerShell:
```powershell
.\task01.exe
```

Each task is independent. Compile each `.cpp` file separately.

## Files
- `Task01/task01.cpp` – Staff hierarchy, overriding and polymorphic processing
- `Task02/task02.cpp` – Person/Student/Staff/TeachingAssistant virtual diamond
- `Task03/task03.cpp` – Base/member initialization and construction/destruction order
- `Task04/task04.cpp` – Virtual dispatch, virtual destructor, slicing demonstration and smart pointers
- `Task05/task05.cpp` – Cart object access, `this`, chaining and highest-total search
- `Task06/task06.cpp` – Extensible vehicle rental hierarchy with abstract base class

## Important
1. Predict the output for the PDF's prediction questions yourself **before** running the matching program.
2. The assignment requires evidence: screenshots, sanitizer output, UML, access table, pseudocode,
   complexity comparisons, and progressive Git commits. This ZIP does not create those submission
   artifacts automatically.
3. Update the README with your name, register number, compiler version, exact commands and results.
