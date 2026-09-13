# C++ Compilation Model

## 1. The build pipeline

```text
source files (.cpp) + headers
              ↓
        preprocessing
              ↓
       translation units
              ↓
          compilation
              ↓
       object files (.o/.obj)
              ↓
           linking
              ↓
      executable (for example .exe)
```

### Preprocessing

The preprocessor handles directives such as `#include`, `#define`, and
conditional compilation. `#include` essentially inserts the header's text into
the source before compilation; it does not connect `.cpp` files.

### Translation units and compilation

A translation unit is one source file after preprocessing, including the
contents of its headers. Each `.cpp` file is compiled separately. The compiler
checks syntax, types, expressions, and other language rules, then produces an
object file containing machine code and linker information.

### Linking

The linker combines object files and libraries. It resolves references such as
a call in `main.o` to a function implemented in `math.o`.

## 2. Declaration and definition

A declaration introduces an entity without providing its implementation:

```cpp
int add(int a, int b);
```

A definition provides the implementation:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Declarations can usually appear more than once in a translation unit. Most
non-`inline` definitions must appear only once in the program (the One
Definition Rule).

## 3. Headers and source files

Headers commonly contain declarations and type definitions. Source files
contain function definitions and other implementation details.

### `math.h`

```cpp
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

struct Calculator
{
    int value{};
};

#endif
```

### `main.cpp`

```cpp
#include <iostream>
#include "math.h"

int main()
{
    Calculator c;
    c.value = add(10, 20);
    std::cout << c.value << '\n';
}
```

### `math.cpp`

```cpp
#include "math.h"

int add(int a, int b)
{
    return a + b;
}
```

The include guard prevents a header's contents from being processed twice in
the same translation unit. Modern projects may use `#pragma once` instead.

```text
main.cpp + math.h → main.o
math.cpp + math.h → math.o
main.o + math.o   → program.exe
```

## 4. Practical build commands

Compile and link in one step:

```bash
g++ -std=c++20 -Wall -Wextra main.cpp math.cpp -o program
```

Compile and link separately:

```bash
g++ -std=c++20 -Wall -Wextra -c main.cpp -o main.o
g++ -std=c++20 -Wall -Wextra -c math.cpp -o math.o
g++ main.o math.o -o program
```

On Windows, the object files may use the `.obj` extension and the executable
usually uses `.exe`.

## 5. Diagnosing errors

### Compiler error

The compiler rejects invalid source code:

```cpp
int main()
{
    std::cout << "Hello"   // missing semicolon
    return 0;
}
```

### Linker error

The source can compile successfully, but linking fails when a required
definition is missing:

```cpp
int add(int a, int b);

int main()
{
    return add(2, 3);
}
```

If `math.cpp` is not included in the link command, a toolchain may report an
error such as `undefined reference to add(int, int)`.

## 6. Common syntax pitfall

These are not equivalent:

```cpp
c.value = add(10, 20); // calls add; result is 30
c.value = (10, 20);    // comma operator; result is 20
```

The comma operator evaluates its left operand and then yields the value of its
right operand. It is unrelated to function argument separation.

## Key takeaways

- Each `.cpp` file becomes a separate translation unit after preprocessing.
- Headers are textually included; they do not perform linking.
- The compiler creates object files, and the linker creates the executable.
- Declarations describe entities; definitions provide them.
- Include guards or `#pragma once` prevent duplicate header contents.
- Missing declarations usually cause compiler errors; missing definitions usually cause linker errors.