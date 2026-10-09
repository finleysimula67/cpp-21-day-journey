# Day 04 — Function Parameters

## Objective

Understand how C++ passes data to functions and how the choice of parameter type affects copying, modification, and memory access.

## Core Concepts

### 1. Pass by Value

The function receives a copy of the argument. Changes to the parameter do not affect the original variable.

```cpp
void changeValue(int number)
{
    number = 100;
}
```

### 2. Pass by Reference

The parameter becomes an alias for the original variable. Changes affect the caller's variable.

```cpp
void changeValue(int& number)
{
    number = 100;
}
```

### 3. Pass by Pointer

The function receives a pointer containing an address. It can access or modify the original object through that pointer.

```cpp
void changeValue(int* number)
{
    if (number != nullptr)
    {
        *number = 100;
    }
}
```

### 4. Pass by Const Reference

The function can access the original object without copying it, but cannot modify it through that reference.

```cpp
void display(const std::string& name)
{
    std::cout << name << '\n';
}
```

This is useful for reading larger objects without unnecessary copying.

## Java Comparison

| C++ | General idea |
|---|---|
| Pass by value | A copy of the argument is passed |
| Pass by reference | An alias to the original object |
| Pass by pointer | An address is passed explicitly |
| Pass by const reference | Read-only access through an alias |

Java also passes arguments by value. For object arguments, the copied value is the reference, so a method can modify the referenced object's state but cannot replace the caller's reference itself.

## Key Takeaways

- Value parameters are independent copies.
- Reference parameters alias existing objects.
- Pointer parameters provide explicit address-based access.
- Const references provide read-only access without copying the object.
- A function's parameter type communicates how it intends to use its input.

## Practice

1. Write a function that doubles an integer using pass by value.
2. Rewrite it using pass by reference and observe the difference.
3. Write a pointer-based version with a null check.
4. Write a function that prints a string using `const std::string&`.
5. Explain why changing a value parameter does not change the caller's variable.

## Completion Criteria

Complete the exercises, compile the programs, and explain the differences between value, reference, pointer, and const-reference parameters without relying on memorized definitions.