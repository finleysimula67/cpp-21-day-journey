# Core C++ Concepts

A concise reference for the concepts covered in the `cpp-21-day-journey`
repository.

Use this document to revise concepts, not as a substitute for writing
and testing code. If something is unclear, create a small program and
observe its behavior.

## 1. Build and Compilation

A typical C++ build has three main stages:

1.  **Preprocessing** --- processes directives such as `#include` and
    macros.
2.  **Compilation** --- translates each source file into object code.
3.  **Linking** --- combines object files and libraries into an
    executable.

``` bash
g++ -c main.cpp -o main.o
g++ main.o User.o -o program
```

-   Header files (`.h` or `.hpp`) commonly declare interfaces.
-   Source files (`.cpp`) commonly contain implementations.
-   Include guards or `#pragma once` help prevent repeated inclusion of
    a header.
-   A declaration introduces an entity; a definition provides its
    implementation or creates it.

## 2. Variables, Pointers, and References

``` cpp
int value = 10;
int* pointer = &value;
int& reference = value;
```

-   `value` stores the integer `10`.
-   `&value` obtains the variable's address.
-   `pointer` stores an address.
-   `*pointer` accesses the object at that address.
-   `reference` is another name for `value`.

A pointer can be reassigned or set to `nullptr`. A reference must be
initialized when declared and normally acts as an alias. Never
dereference a null, dangling, or otherwise invalid pointer.

## 3. Scope, Lifetime, and Storage Duration

These terms describe different things:

-   **Scope** --- where a name can be used.
-   **Lifetime** --- when an object exists.
-   **Storage duration** --- how long storage for an object is provided,
    such as automatic, static, or dynamic storage duration.

A raw pointer does not own its target and does not automatically release
it.

``` cpp
int* pointer = new int(42);
delete pointer;
pointer = nullptr;
```

This is an example of manual allocation and cleanup. In modern C++,
prefer standard containers and smart pointers over manually managing
`new` and `delete`.

## 4. Function Parameters

``` cpp
void byValue(int value);             // receives a copy
void byReference(int& value);        // can modify the caller's object
void byPointer(int* value);          // receives an address; may be null
void readOnly(const std::string& s); // reads without copying the string
```

Choose a parameter type based on intent:

-   Use **value** for small values or when an independent copy is
    wanted.
-   Use **`const T&`** to read a potentially expensive-to-copy object
    without copying it.
-   Use **`T&`** when a function should modify an existing object.
-   Use **`T*`** when explicit pointer semantics are useful, including
    representing an optional object with `nullptr`.

Java also passes arguments by value. For an object argument, the copied
value is the reference, so a method can change the referenced object's
state but cannot replace the caller's reference itself.

## 5. Classes and Composition

-   `private` restricts direct access to class members.
-   `public` exposes the class interface.
-   A constructor establishes the initial state of an object.
-   A destructor performs cleanup when an object's lifetime ends.
-   `this` refers to the current object inside a non-static member
    function.
-   **Composition** models a "has-a" relationship.
-   Use inheritance when a genuine "is-a" relationship and
    substitutability make sense, not merely to reuse code.
-   A `const` member function promises not to modify the object's
    ordinary non-`mutable` member state.

## 6. Copying Objects

``` cpp
Buffer second = first; // copy construction: creates a new object
second = first;        // copy assignment: updates an existing object
```

For a class that directly owns a raw resource, copying only the pointer
is usually incorrect: two objects could try to release the same
resource.

A **deep copy** creates an independent resource containing equivalent
data.

When implementing copy assignment, consider:

1.  Self-assignment.
2.  Creating the replacement safely.
3.  Releasing the old resource.
4.  Updating the object.
5.  Returning `*this`.

## 7. Moving Objects

``` cpp
Buffer second = std::move(first); // move construction
second = std::move(first);        // move assignment
```

-   A **move constructor** initializes a new object from a source
    object.
-   **Move assignment** replaces the state of an existing destination.
-   `std::move(x)` does not move a resource by itself. It allows an
    applicable move operation to be selected.
-   Move operations must preserve the class's invariants and handle the
    destination's existing resources.
-   For a simple raw-pointer owner, a move may transfer the pointer and
    set the source pointer to `nullptr`.

A moved-from standard-library object is generally valid but may have an
unspecified value. A custom class should maintain a clearly defined
valid moved-from state.

## 8. RAII and Smart Pointers

**RAII** (Resource Acquisition Is Initialization) ties resource
ownership to an object's lifetime so cleanup happens automatically.

-   `std::unique_ptr<T>` represents exclusive ownership.
-   `std::make_unique<T>(...)` is the preferred way to create a
    `unique_ptr`.
-   `std::unique_ptr` is movable but not copyable.
-   `std::shared_ptr<T>` supports shared ownership when it is genuinely
    needed. Shared ownership adds reference-counting overhead and can
    create cycles.
-   Prefer standard types such as `std::vector` and `std::string` over
    raw owning pointers.

``` cpp
#include <memory>

auto value = std::make_unique<int>(100);
```

When `value` goes out of scope, its owned integer is released
automatically.

## 9. Rule of Three, Five, and Zero

### Rule of Three

If a class directly manages a resource and needs a custom destructor,
copy constructor, or copy-assignment operator, it may need all three.

### Rule of Five

In addition to those three operations, consider a move constructor and
move-assignment operator.

The Rule of Five is a guideline for resource-managing types. It does not
mean every class should manually define five special member functions.

### Rule of Zero

Prefer members that manage their own resources, such as `std::string`,
`std::vector`, and `std::unique_ptr`. This often removes the need to
write custom destructor, copy, and move operations.

## 10. `const`, `auto`, and Namespaces

-   `const T x` prevents modification through that name.
-   `const T& x` provides read-only access through a reference.
-   `auto` asks the compiler to deduce a variable's type from its
    initializer.
-   `std::` qualifies a name from the standard namespace.
-   `using namespace std;` can be convenient in small exercises, but
    avoid putting it in headers because it affects every file that
    includes the header.

## 11. Essential Standard Library Types

  Type or tool           Typical purpose
  ---------------------- -----------------------------------
  `std::vector<T>`       Dynamic contiguous sequence
  `std::string`          Text
  `std::array<T, N>`     Fixed-size sequence
  `std::map`             Ordered key-value lookup
  `std::unordered_map`   Hash-based key-value lookup
  `std::sort`            Sorts a range
  `std::find`            Finds a matching value in a range
  `std::count`           Counts matching values in a range

Prefer standard containers and algorithms over manual memory-management
code unless there is a clear reason not to.

## 12. Common Mistakes

Watch for these problems:

-   Dereferencing `nullptr` or a dangling pointer.
-   Forgetting to release a manually owned resource.
-   Releasing the same allocation twice.
-   Shallow-copying an owning raw pointer.
-   Overwriting a destination pointer before releasing its old
    allocation.
-   Leaving a moved-from object in an invalid state.
-   Confusing copy construction with copy assignment.
-   Assuming `std::move` transfers a resource by itself.
-   Assuming code is correct because it compiled and ran once.
-   Drawing broad performance conclusions from one tiny timing test.

## 13. Debugging Checklist

When a program behaves unexpectedly, ask:

1.  What is the exact compiler error or runtime symptom?
2.  Which object owns each resource?
3.  How long does each pointed-to object live?
4.  Which constructor, assignment operator, or destructor runs?
5.  Is the source object still valid after a copy or move?
6.  Can self-assignment or self-move occur?
7.  Have null, empty, and other edge cases been tested?
8.  Could a standard-library type remove the need for manual resource
    management?

Compile practice programs with warnings:

``` bash
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o program
```

For suitable programs, sanitizers can help detect memory errors.
Availability depends on the compiler and environment.

## 14. What to Study Next

Treat these as future learning areas, not prerequisites to master all at
once:

1.  More practice with functions, classes, references, and `const`
    correctness.
2.  STL containers, iterators, and algorithms.
3.  RAII, exception safety, and the Rule of Zero.
4.  Debugging tools and sanitizers.
5.  CMake and multi-file builds.
6.  Unit testing.
7.  Profiling with realistic workloads.
8.  A small project that you can explain, test, and maintain
    independently.

## Final Reminder

For each concept, aim to explain:

-   What it does.
-   Why it is useful.
-   What happens to memory and object lifetime.
-   What can go wrong.
-   When a standard-library solution is simpler.

Understanding grows through implementation, debugging, and repeated
practice---not memorization alone.
