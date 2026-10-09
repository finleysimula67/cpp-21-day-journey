# C++ Self-Assessment

## Purpose

This file helps me check what I have learned during my 21-day C++ journey.

The goal is to understand what I know, what I can do on my own, and what I need to practise more.

## Instructions

- Answer in my own words.
- Explain concepts instead of memorizing definitions.
- Write code when needed.
- Test my code by compiling and running it.
- Mark questions I cannot answer and return to them later.
- Try to answer without looking at my notes first.

---

## 1. Compilation and Headers

1. What happens when we compile a C++ program?
2. What is the difference between a declaration and a definition?
3. Why do we use header files and source files?
4. What is the difference between a compiler error and a linker error?

## 2. Pointers, References, and Functions

5. What is the difference between a pointer and a reference?
6. What do `&` and `*` mean in C++?
7. What is the difference between pass by value, pass by reference, and pass by pointer?
8. Why does changing a copied value not change the original variable?
9. What is a dangling pointer, and why is it dangerous?

## 3. Scope, Lifetime, and Classes

10. What is the difference between scope and object lifetime?
11. What happens when an object goes out of scope?
12. What is the difference between a constructor and a destructor?
13. What is composition? Give an example.
14. Why should we care about how long an object lives?

## 4. Copying Objects

15. What is the difference between a copy constructor and copy assignment?
16. What is the difference between a shallow copy and a deep copy?
17. Why can copying a raw pointer cause problems?
18. What is self-assignment, and how can we handle it?

## 5. Move Semantics

19. What is the difference between move construction and move assignment?
20. What does `std::move` do?
21. What should happen to an object after its resources are moved?
22. Why must move assignment handle the destination's existing resource?
23. What does `noexcept` mean, and why can it matter for move operations?

## 6. Memory and Resource Management

24. What is RAII, and why is it useful?
25. How does `std::unique_ptr` manage a resource?
26. Why can we move a `std::unique_ptr` but not copy it?
27. What are the Rule of Three and Rule of Five?
28. What is the Rule of Zero, and why is it useful?

## 7. Standard Library and Basic C++

29. When should we use `std::vector` instead of a raw array?
30. Why is `std::string` useful for working with text?
31. Why are range-based loops useful?
32. What does `const` do?
33. Why should we avoid `using namespace std;` in header files?

## 8. Reading and Debugging Code

34. Can I identify which constructor, assignment operator, or destructor runs in a program?
35. Can I explain what happens to an object after it is moved?
36. Can I find a possible memory leak or double deletion?
37. Why can a program compile successfully but still have a bug?
38. How can compiler warnings help me find problems?

## 9. Practical Tasks

39. Can I write a class with a copy constructor and copy assignment operator?
40. Can I write move construction and move assignment for a class that owns a resource?
41. Can I implement and test the Rule of Five?
42. Can I use standard library types instead of managing memory manually?
43. Can I split a C++ program into multiple files and compile it correctly?

---

## Review Notes

**Date:**

**Questions I answered confidently:**

**Questions I need to review:**

**Code I wrote or tested:**

**What I learned:**

**What I will practise next:**

---

## Final Reflection

After completing this assessment, ask myself:

1. Which concepts can I explain without looking at my notes?
2. Which concepts can I use in my own code?
3. Which mistakes do I still make?
4. What should I learn or practise next?

**Remember:** Finishing the 21-day journey does not mean I have mastered C++. It means I have built a foundation that I can improve through practice and projects.