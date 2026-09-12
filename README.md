# Data Structures — C++ Implementations

A collection of homework and assignment submissions from the Data Structures course at An-Najah National University. Each sub-directory is a self-contained C++ program demonstrating a specific data structure or algorithm concept. All projects were developed with Visual Studio (`.sln` / `.vcxproj` files included).

## What's Implemented

| Directory | File | Data structure / concept | Key operations | Time complexity |
|---|---|---|---|---|
| `Task3/` | `Task3.cpp` | Postfix expression evaluator (stack-based) | Evaluates multi-digit integer postfix expressions using `std::stack` | O(n) scan |
| `HW111/` | `HW#111.cpp` | `Polynomial` class with dynamic array | `SetCoefficient`, `GetCoefficient`, `operator+`, `operator-`, `operator+=`, `operator-=`, `operator=`, overloaded `<<` / `>>` | O(n) for arithmetic ops |
| `HW222/` | `HW222.cpp` | Shape hierarchy (OOP / polymorphism) | Abstract `Shape` base with virtual `getArea()` and `getCoordinates()`; concrete subclasses `Circle`, `Rectangle`, `Triangle`; non-member `operator+` summing areas | O(1) per shape |
| `Assignment4/` | `Assignment#4.cpp` | Templated `Deque<T>` (doubly linked list) | `pushFront`, `pushBack`, `popFront`, `popBack`, `front`, `back`, `isEmpty`, `getSize` | O(1) all operations |
| `DS/` | `DS.cpp` | Templated singly linked `LinkedList<T>` | `addFront`, `addBack`, `removeFront`, `find`, `traverse`, `removeBefore(x)` | O(1) front ops; O(n) `addBack`, `find`, `removeBefore` |

## Tech Stack

| Component | Detail |
|---|---|
| Language | C++ (C++11 or later; standard library `<stack>`, `<stdexcept>`) |
| Build | Visual Studio solution files (`.sln` + `.vcxproj`) per sub-project |
| Compiler | MSVC (Visual Studio); also compilable with `g++` |
| No external dependencies | Uses only the C++ standard library |

## Project Structure

```
Data-Structures-Project/
â”œâ”€â”€ Task3/
â”‚   â””â”€â”€ Task3.cpp              # Postfix evaluator
â”œâ”€â”€ HW111/
â”‚   â””â”€â”€ HW#111.cpp             # Polynomial class
â”œâ”€â”€ HW222/
â”‚   â””â”€â”€ HW222.cpp              # Shape hierarchy
â”œâ”€â”€ Assignment4/
â”‚   â””â”€â”€ Assignment#4.cpp       # Templated Deque
â””â”€â”€ DS/
    â””â”€â”€ DS.cpp                 # Templated LinkedList
```

Each directory also contains Visual Studio project files (`.sln`, `.vcxproj`) which can be ignored when compiling from the command line.

## Build & Run

Each file is a single self-contained translation unit with a `main()` driver. Compile any of them with:

```bash
g++ -std=c++14 Task3/Task3.cpp -o task3 && ./task3
g++ -std=c++14 "Assignment4/Assignment#4.cpp" -o deque && ./deque
g++ -std=c++14 DS/DS.cpp -o linkedlist && ./linkedlist
g++ -std=c++14 HW111/HW#111.cpp -o polynomial && ./polynomial
g++ -std=c++14 HW222/HW222.cpp -o shapes && ./shapes
```

Or open the corresponding `.sln` file in Visual Studio and press **Ctrl+F5**.

## Implementation Notes

- **`Deque<T>`** (`Assignment4`) uses a doubly linked list with `head` and `tail` pointers, giving O(1) insertions and deletions at both ends. Throws `std::runtime_error` on pop from an empty deque.
- **`LinkedList<T>`** (`DS`) is a singly linked list. The custom `removeBefore(x)` method locates the node whose successor holds value `x` and removes that predecessor node.
- **`Polynomial`** (`HW111`) stores coefficients in a heap-allocated dynamic array that is resized on demand when `SetCoefficient` is called with an exponent beyond the current capacity.
- **Shape hierarchy** (`HW222`) demonstrates runtime polymorphism: an array of `Shape*` pointers can call the correct `getArea()` override for each concrete type.

---

*Software Engineering degree, An-Najah National University*

## License & copyright

Copyright © 2026 Ali Yaqoub. All rights reserved.

This software and its contents are proprietary. Unauthorized copying, distribution, modification, or commercial use is prohibited without prior written permission from the copyright holder.

See the [LICENSE](./LICENSE) file for the full notice.
