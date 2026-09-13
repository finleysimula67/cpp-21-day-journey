# Headers and Includes

## 1. What is a header?

A header (`.h` / `.hpp`) contains declarations that other source files need to know about.

Example:

```cpp
// math.h
int add(int a, int b);
```

The header tells the compiler:

"There is a function called add that takes two ints and returns an int."

The actual implementation can be in a .cpp file.

## 2. What does `#include` do?

`#include` is handled by the preprocessor.

```cpp
#include "math.h"
```

Conceptually, the contents of math.h are inserted into the source file before compilation.

It does NOT directly connect main.cpp to math.cpp.

The .cpp files are compiled separately and the linker connects their definitions later.

## 3. Why do we need include guards?

If the same header is included multiple times, its definitions can appear multiple times in one translation unit.

Example:

```cpp
#include "math.h"
#include "math.h"
```

If `math.h` contains:

```cpp
struct Calculator
{
    int value;
};
```

the compiler can see the same struct definition twice and report:

redefinition of 'struct Calculator'
## 4. Traditional include guard

A header can protect itself using:

#ifndef MATH_H
#define MATH_H

struct Calculator
{
    int value;
};

#endif

The first time the header is included:

`MATH_H` is not defined
        ↓
define `MATH_H`
        ↓
process the header

The second time:

`MATH_H` is already defined
        ↓
skip the header contents
## 5. `#pragma once`

Modern C++ headers commonly use:

#pragma once

struct Calculator
{
    int value;
};

It tells the compiler to process this header only once per translation unit.

So even if:

#include "math.h"
#include "math.h"

appears twice, the header is processed only once.

## 6. `#pragma once` vs. include guards

### `#pragma once`

- Simple and easy to read
- Common in modern C++ projects
- Prevents multiple inclusion of the same header

### Include guards

- Traditional and widely used
- Based on the C/C++ preprocessor
- Useful to understand because existing projects use them

Both solve the same basic problem:

Prevent a header from being processed multiple times in the same translation unit.

## 7. Header/source separation

A common C++ project structure is:

```text
include/
    Task.h

src/
    Task.cpp

main.cpp
```

The header contains declarations:

```cpp
class Task
{
public:
    Task(int id, std::string title);
    int getId() const;
};
```

The .cpp contains definitions:

```cpp
Task::Task(int id, std::string title)
    : id(id), title(title)
{
}

int Task::getId() const
{
    return id;
}
```

## Mental model

```text
.h
 ↓
WHAT exists?

.cpp
 ↓
HOW it works?
```

## Key takeaway

- `#include` is preprocessing/textual inclusion.

- Headers provide declarations and class definitions.

- Include guards and `#pragma once` prevent duplicate inclusion problems.

- The compiler compiles translation units, while the linker connects definitions across `.cpp` files.




