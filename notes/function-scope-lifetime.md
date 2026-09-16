````markdown
# Day 4 — Functions and Function Parameters

## 1. Functions in C++

A function has:

- Return type
- Name
- Parameters
- Function body

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
````

A function allows us to organize code into reusable pieces.

---

## 2. Function Parameters

C++ provides different ways to pass data to a function.

The three important forms are:

```text
T value
   ↓
COPY

T& value
   ↓
REFERENCE / SAME OBJECT

T* value
   ↓
POINTER / ADDRESS
```

---

## 2.1 Pass by Value

When a parameter is written normally:

```cpp
void change(int value)
{
    value = 500;
}
```

The function receives a **copy** of the argument.

Conceptually:

```text
Original object
┌──────────┐
│ value=10 │
└──────────┘
      │
      │ copy
      ↓
Function parameter
┌──────────┐
│ value=10 │
└──────────┘

Two separate objects.

Changing the function's value
does NOT change the original.
```

Example:

```cpp
#include <iostream>

void change(int value)
{
    value = 500;
}

int main()
{
    int value = 10;

    change(value);

    std::cout << value << '\n';

    return 0;
}
```

Output:

```text
10
```

The function changed its own copy, not the original object.

---

## 2.2 Pass by Reference

When `&` is used:

```cpp
void change(int& value)
{
    value = 500;
}
```

The parameter refers to the **original object**.

Conceptually:

```text
Original object
┌──────────┐
│ value=10 │
└──────────┘
      ↑
      │
   reference
      │
Function parameter

Both names refer to the SAME object.

Changing the function's value
changes the original object.
```

Example:

```cpp
#include <iostream>

void change(int& value)
{
    value = 500;
}

int main()
{
    int value = 10;

    change(value);

    std::cout << value << '\n';

    return 0;
}
```

Output:

```text
500
```

The reference allows the function to modify the original object.

---

## 2.3 Pass by Pointer

When a pointer is used:

```cpp
void change(int* value)
{
    *value = 500;
}
```

The function receives an **address**.

Example call:

```cpp
int value = 10;

change(&value);
```

`&value` gives the address of `value`.

Conceptually:

```text
Pointer
┌──────────────┐
│   address    │
└──────────────┘
       │
       │ points to
       ↓
Original object
┌──────────┐
│ value=10 │
└──────────┘

The pointer stores the object's address.

*pointer → accesses the object at that address.
```

Example:

```cpp
#include <iostream>

void change(int* value)
{
    *value = 500;
}

int main()
{
    int value = 10;

    change(&value);

    std::cout << value << '\n';

    return 0;
}
```

Output:

```text
500
```

The pointer allows the function to access and modify the original object through its address.

---

# 3. Comparing the Three

| Parameter  | What it receives    | Modifies original? |
| ---------- | ------------------- | ------------------ |
| `T value`  | Copy                | No                 |
| `T& value` | Reference to object | Yes                |
| `T* value` | Address of object   | Yes, through `*`   |

Quick mental model:

```text
T value
   ↓
COPY

T& value
   ↓
ALIAS / SAME OBJECT

T* value
   ↓
ADDRESS / POINTER
```

---

# 4. Understanding Addresses

We can use addresses to prove the difference between pass by value, reference, and pointer.

Example:

```cpp
void changeByValue(int value)
{
    std::cout << &value << '\n';
}

void changeByReference(int& value)
{
    std::cout << &value << '\n';
}
```

In `main()`:

```cpp
int value = 10;

std::cout << &value << '\n';

changeByValue(value);

changeByReference(value);
```

Conceptually:

```text
Pass by Value:

main object      → 0xABC
function object  → 0xDEF

Different addresses
→ different objects
→ a copy was made
```

```text
Pass by Reference:

main object      → 0xABC
function parameter → 0xABC

Same address
→ same object
→ no separate int object
```

---

# 5. Understanding Pointers

Suppose:

```cpp
int value = 10;

int* ptr = &value;
```

Then:

```text
value
  ↓
actual object

&value
  ↓
address of the object

ptr
  ↓
address stored inside the pointer

*ptr
  ↓
object/value at that address
```

Example:

```cpp
std::cout << &value << '\n';
std::cout << ptr << '\n';
std::cout << *ptr << '\n';
```

These represent:

```text
&value → address of the original object

ptr    → address stored in the pointer

*ptr   → value/object being pointed to
```

---

## 5.1 `&*pointer`

This expression was also used during the experiment:

```cpp
&*value
```

Read it from the inside:

```text
value
  ↓
*value
  ↓
object being pointed to
  ↓
&(*value)
  ↓
address of that object
```

Therefore:

```cpp
&*value
```

gives the address of the object being pointed to.

For learning purposes, this is useful for understanding how `*` and `&` relate to each other.

---

# 6. Important Pointer Distinction

Inside this function:

```cpp
void change(int* value)
{
}
```

`value` is itself a pointer variable.

Therefore:

```cpp
value
```

means:

> The address stored inside the pointer.

While:

```cpp
&value
```

means:

> The address of the pointer variable itself.

And:

```cpp
*value
```

means:

> The object located at the address stored in the pointer.

So:

```text
value
  ↓
address stored in pointer

&value
  ↓
address of pointer variable

*value
  ↓
object being pointed to
```

---

# 7. Java Comparison

In Java:

```java
void change(int value)
{
    value = 500;
}
```

The primitive `int` is passed by value.

C++ gives us more explicit control over how function parameters interact with objects:

```cpp
void change(int value);   // copy

void change(int& value);  // reference

void change(int* value);  // pointer
```

This becomes especially important when working with:

* Object lifetime
* Memory
* Ownership
* RAII
* Smart pointers
* Performance

---

# 8. Scope vs Lifetime

These are important C++ concepts that will be covered separately.

```text
Scope
  ↓
Where can I access the NAME?

Lifetime
  ↓
How long does the OBJECT exist?
```

They are related, but they are not the same thing.

---

# 9. Key Takeaways

The most important mental model from Day 4 so far:

```text
T value
   ↓
COPY

T& value
   ↓
ALIAS / SAME OBJECT

T* value
   ↓
ADDRESS / POINTER
```

For pointers:

```text
value
  ↓
address stored in pointer

*value
  ↓
object at that address

&value
  ↓
address of the pointer variable
```

For references:

```text
reference
  ↓
another name for the same object
```

The important C++ question is not only:

> "Does this code work?"

Also ask:

> "Am I working with a copy, the original object, or an address?"

```
