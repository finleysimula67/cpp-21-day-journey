# C++ 21-Day Journey

A focused 21-day journey to develop a strong foundation in modern C++, with emphasis on memory, object lifetime, resource management, STL, performance, systems programming, and practical software engineering.

## 🎯 Goal

The goal of this journey is **not to master all of C++ in 21 days**.

The goal is to build a solid mental model of C++ and become comfortable reading, writing, debugging, and designing intermediate-level C++ programs.

By the end of the journey, I aim to understand:

* C++ compilation and linking
* C++ types and value semantics
* Pointers and references
* Memory and object lifetime
* Classes and object-oriented programming
* Copy and move semantics
* RAII and resource management
* Smart pointers
* STL containers and algorithms
* Templates and generic programming
* Modern C++ practices
* Concurrency fundamentals
* CMake and build systems
* Testing and debugging
* Performance considerations
* Real-world C++ software architecture

---

## 👨‍💻 Background

I already have programming experience, primarily with:

* Java
* Java SE
* Object-oriented programming
* Spring / Spring Boot
* REST APIs
* SQL and databases
* Backend development
* General software engineering

I also had previous exposure to C++ fundamentals in 2025.

Therefore, this journey is **not a beginner syntax course**.

Instead, the focus is on understanding what makes C++ fundamentally different from managed languages such as Java, especially:

```text
Memory
Ownership
Object Lifetime
Value Semantics
Resource Management
Performance
Compilation
```

---

# 🗺️ 21-Day Roadmap

## Phase 1 — C++ Mental Model & Fundamentals

**Days 1–7**

* C++ compilation model
* Preprocessing, compilation, linking
* Headers and source files
* Types and initialization
* Functions
* References
* Pointers
* `const`
* Scope and lifetime
* Stack and heap
* Arrays and strings
* Structs and enums
* Error handling
* STL fundamentals
* Multi-file programs

---

## Phase 2 — OOP & Modern C++

**Days 8–14**

* Classes and objects
* Constructors and destructors
* Member functions
* Encapsulation
* Composition
* Inheritance
* Polymorphism
* Virtual functions
* Abstract classes
* Virtual destructors
* Multiple inheritance
* Object slicing
* Operator overloading
* Copy constructor
* Copy assignment
* Move constructor
* Move assignment
* Rule of 0
* Rule of 3
* Rule of 5
* RAII
* Smart pointers
* Templates
* STL containers
* Iterators
* Algorithms
* Lambdas

---

## Phase 3 — Real-World C++ & Project

**Days 15–21**

* Where C++ is used in industry
* Memory layout
* Cache awareness
* Performance
* Concurrency fundamentals
* Threads
* Mutexes
* Atomics
* Filesystem
* File I/O
* Networking concepts
* CMake
* Static and dynamic linking
* Testing
* Debugging
* Sanitizers
* Profiling
* Code organization
* API design
* Project implementation

---

# 🚀 Final Project

## C++ Log Processing & Analytics Engine

The final project will be a modular C++ application capable of processing log files and generating useful analytics.

The project is intended to apply concepts learned throughout the journey, including:

* Object-oriented design
* STL
* Data structures
* Algorithms
* RAII
* Smart pointers where appropriate
* File I/O
* Error handling
* Templates where justified
* Modular architecture
* CMake
* Testing
* Debugging
* Performance analysis
* Concurrency where it provides a real benefit

The project will prioritize **good engineering decisions over unnecessary complexity**.

---

# 📅 Progress

### Phase 1 — Fundamentals

* [ ] Day 01 — C++ Mental Model & Compilation
* [ ] Day 02 — Types, Operators & Control Flow
* [ ] Day 03 — Functions, References & `const`
* [ ] Day 04 — Pointers & Memory
* [ ] Day 05 — Arrays, Strings & Data Representation
* [ ] Day 06 — Structs, Enums & Error Handling
* [ ] Day 07 — Fundamentals Integration

### Phase 2 — OOP + Modern C++

* [ ] Day 08 — Classes, Objects & Lifetime
* [ ] Day 09 — Composition, Inheritance & Polymorphism
* [ ] Day 10 — C++ OOP Design & Pitfalls
* [ ] Day 11 — Copy Semantics & Resource Management
* [ ] Day 12 — Move Semantics
* [ ] Day 13 — RAII & Smart Pointers
* [ ] Day 14 — Templates, STL, Algorithms & Lambdas

### Phase 3 — Real-World C++ + Project

* [ ] Day 15 — Real-World C++ & Project Architecture
* [ ] Day 16 — Memory & Performance
* [ ] Day 17 — Concurrency Fundamentals
* [ ] Day 18 — Filesystem, I/O & Networking Concepts
* [ ] Day 19 — CMake, Testing & Debugging
* [ ] Day 20 — Project Implementation
* [ ] Day 21 — Project Completion & Final Assessment

---

# 📁 Repository Structure

```text
cpp-21-day-journey/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── days/
│   ├── .gitkeep
│   └── day-00/
│       └── main.cpp
│
├── project/
│   └── .gitkeep
│
└── notes/
    └── .gitkeep
```

---

# 🧠 Learning Principles

### Understand before memorizing

Syntax is easy to look up. Mental models are not.

### Think about lifetime

For non-trivial objects, ask:

> Who creates it?

> Who owns it?

> How long does it live?

> Who destroys it?

### Prefer modern C++

Understand older C++ mechanisms, but prefer modern practices when writing new code.

### Don't use complexity for its own sake

A feature should be used because it solves a real problem, not because it looks advanced.

### Understand performance

Consider:

* Time complexity
* Space complexity
* Copies
* Moves
* Allocations
* Memory locality
* Indirection

But avoid premature optimization.

### Solve before looking at solutions

Exercises will be attempted independently before solutions are reviewed.

### Write meaningful Git commits

Commits should describe the actual change.

Examples:

```text
Add reference and const examples
Implement vector iteration exercises
Add RAII resource wrapper
Introduce CMake build configuration
Add log parser tests
```

Avoid meaningless commits such as:

```text
updated code
fixed stuff
day 3
changes
```

---

# 📊 Learning Priority

## MUST

Core concepts required for practical C++:

* Types
* Functions
* References
* Pointers
* `const`
* Object lifetime
* Classes
* Polymorphism
* STL
* Copy/move semantics
* RAII
* Smart pointers
* Algorithms
* CMake
* Debugging
* Testing

## SHOULD

Important supporting knowledge:

* `std::optional`
* `std::string_view`
* Filesystem
* Threads
* Mutexes
* Atomics
* Memory layout
* Cache awareness
* Static/dynamic linking
* Profiling

## OPTIONAL

Topics that can wait:

* Concepts in depth
* Advanced ranges
* Coroutines
* Advanced allocators
* Advanced template metaprogramming
* Lock-free programming

## SKIP FOR NOW

* Compiler development
* Kernel development
* Advanced GPU programming
* Template metaprogramming
* Advanced lock-free algorithms
* Deep coroutine internals
* Obscure language edge cases

---

# 📝 Daily Workflow

Each day follows approximately:

```text
Learn
  ↓
Understand
  ↓
Code
  ↓
Solve Exercises
  ↓
Challenge
  ↓
Review
  ↓
Commit
```

Each day will contain:

1. Learning objectives
2. Core concepts
3. Java → C++ comparisons where useful
4. Under-the-hood explanations
5. Examples
6. Exercises
7. Challenge problem
8. Mini implementation task
9. Common mistakes
10. Knowledge checkpoint
11. GitHub commit

---

# 📈 Final Assessment

At the end of Day 21, the journey will be evaluated across:

* C++ syntax
* Programming fundamentals
* Memory understanding
* Pointers and references
* Object lifetime
* OOP
* RAII and resource management
* STL
* Modern C++
* Debugging
* Performance awareness
* Code quality
* Architecture
* Problem solving
* Ability to read C++ code
* Ability to build a project independently

The final assessment will distinguish between:

**What I understand**

**What I only know at an introductory level**

**What I still don't understand**

**What I need to improve**

**What I should learn next**

---

# 📌 Status

**Day 0 — Repository Setup Complete**

The repository was created and initialized before the 21-day challenge.

**Day 1 begins next.**

---

## Repository

**GitHub:** `finleysimula67/cpp-21-day-journey`

---

> The objective is not to learn everything about C++.
>
> The objective is to understand enough of C++ deeply enough to continue learning it independently.
