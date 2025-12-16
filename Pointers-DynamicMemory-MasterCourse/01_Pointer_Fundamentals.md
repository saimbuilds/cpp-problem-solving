# Module 1: Pointer Fundamentals
## From Zero to Hero in 30 Minutes

> **Learning Objective**: Master pointer syntax, operators, and basic manipulation to build a rock-solid foundation.

---

## Table of Contents
1. [What is a Pointer?](#what-is-a-pointer)
2. [Declaration & Initialization](#declaration--initialization)
3. [The `&` and `*` Operators](#the--and--operators)
4. [NULL and nullptr](#null-and-nullptr)
5. [Common Pitfalls](#common-pitfalls)
6. [Quick Reference](#quick-reference)

---

## What is a Pointer?

A pointer is a **variable that stores a memory address**.

```cpp
int x = 10;      // Regular variable
int* ptr = &x;   // Pointer variable (stores address of x)
```

**Memory Visualization:**
```
Variable: x
Value: 10
Address: 0x7ffd1234

Variable: ptr
Value: 0x7ffd1234 (address of x)
Address: 0x7ffd5678
```

---

## Declaration & Initialization

### Syntax Variations (All Correct)
```cpp
int* ptr1;    // Preferred style
int *ptr2;    // Also valid
int * ptr3;   // Also valid
int* ptr4, ptr5;  // ⚠️ ptr4 is pointer, ptr5 is int (COMMON MISTAKE!)
int *ptr6, *ptr7; // Both are pointers
```

### Initialization Methods
```cpp
// Method 1: Initialize with address
int x = 5;
int* ptr = &x;

// Method 2: Initialize as NULL
int* ptr = NULL;        // C-style
int* ptr = nullptr;     // C++11 (preferred)

// Method 3: Uninitialized (DANGEROUS!)
int* ptr;  // Contains garbage address - DO NOT DEREFERENCE!
```

---

## The `&` and `*` Operators

### `&` - Address-of Operator
Returns the memory address of a variable.

```cpp
int x = 42;
cout << &x;  // Prints address, e.g., 0x7ffd1234
```

### `*` - Two Uses!

#### 1. Declaration (makes a pointer)
```cpp
int* ptr;  // Declaration: ptr is a pointer to int
```

#### 2. Dereference (access value at address)
```cpp
int x = 100;
int* ptr = &x;
cout << *ptr;  // Output: 100 (value at address stored in ptr)
*ptr = 200;    // Changes x to 200!
```

### Complete Example
```cpp
int a = 10;
int* p = &a;

cout << a;     // 10 (value of a)
cout << &a;    // 0x1234 (address of a)
cout << p;     // 0x1234 (value of p, which is address of a)
cout << *p;    // 10 (value at address stored in p)
cout << &p;    // 0x5678 (address of p itself)
```

---

## NULL and nullptr

### NULL (C-style)
```cpp
int* ptr = NULL;  // Defined as 0 or ((void*)0)
```

### nullptr (C++11, Preferred)
```cpp
int* ptr = nullptr;  // Type-safe null pointer
```

### Why Check for NULL?
```cpp
int* ptr = nullptr;

if (ptr != nullptr) {
    cout << *ptr;  // Safe
} else {
    cout << "Pointer is null!";
}

// Without check:
// cout << *ptr;  // CRASH! Dereferencing null pointer
```

---

## Common Pitfalls

### ❌ Mistake 1: Dereferencing Uninitialized Pointer
```cpp
int* ptr;      // Contains garbage
cout << *ptr;  // CRASH or unpredictable behavior
```

**✅ Fix:**
```cpp
int* ptr = nullptr;
// or
int x = 5;
int* ptr = &x;
```

### ❌ Mistake 2: Type Mismatch
```cpp
int x = 10;
double* ptr = &x;  // ERROR! Type mismatch
```

**✅ Fix:**
```cpp
int x = 10;
int* ptr = &x;  // Pointer type matches variable type
```

### ❌ Mistake 3: Modifying Constant
```cpp
const int x = 10;
int* ptr = &x;     // ERROR or warning
*ptr = 20;         // Undefined behavior
```

**✅ Fix:**
```cpp
const int x = 10;
const int* ptr = &x;  // Pointer to constant
// *ptr = 20;  // ERROR: can't modify through const pointer
```

### ❌ Mistake 4: Confusing Pointer Declaration
```cpp
int* p1, p2;  // p1 is pointer, p2 is int!
```

**✅ Fix:**
```cpp
int *p1, *p2;  // Both are pointers
// or
int* p1;
int* p2;
```

---

## Quick Reference

| Expression | Meaning |
|------------|---------|
| `int* ptr` | Declare pointer to int |
| `&var` | Address of var |
| `*ptr` | Value at address stored in ptr |
| `ptr` | Address stored in ptr |
| `&ptr` | Address of ptr itself |
| `ptr = &var` | Make ptr point to var |
| `*ptr = value` | Change value at address stored in ptr |
| `ptr = nullptr` | Make ptr point to nothing |

---

## Dry Run Practice Problems

### Problem 1: Basic Dry Run
```cpp
int x = 5;
int* p = &x;
*p = 10;
int y = *p + 5;
cout << x << " " << y;
```

**What's the output?**

<details>
<summary>Click for answer</summary>

**Output:** `10 15`

**Trace:**
1. `x = 5`
2. `p = &x` (p points to x)
3. `*p = 10` (changes x to 10 through pointer)
4. `y = *p + 5` → `y = 10 + 5` → `y = 15`
5. Output: `10 15`
</details>

### Problem 2: Multiple Pointers
```cpp
int a = 7;
int* p1 = &a;
int* p2 = p1;
*p2 = 3;
cout << a << " " << *p1 << " " << *p2;
```

**What's the output?**

<details>
<summary>Click for answer</summary>

**Output:** `3 3 3`

**Trace:**
1. `a = 7`
2. `p1 = &a` (p1 points to a)
3. `p2 = p1` (p2 also points to a)
4. `*p2 = 3` (changes a to 3)
5. All three (a, *p1, *p2) refer to same location
6. Output: `3 3 3`
</details>

### Problem 3: Swapping via Pointers
```cpp
int x = 10, y = 20;
int* p = &x;
int* q = &y;
*p = *p + *q;
*q = *p - *q;
*p = *p - *q;
cout << x << " " << y;
```

**What's the output?**

<details>
<summary>Click for answer</summary>

**Output:** `20 10`

**Trace:**
1. `x = 10, y = 20`
2. `p = &x, q = &y`
3. `*p = *p + *q` → `x = 10 + 20` → `x = 30`
4. `*q = *p - *q` → `y = 30 - 20` → `y = 10`
5. `*p = *p - *q` → `x = 30 - 10` → `x = 20`
6. Output: `20 10`

This is a swap!
</details>

### Problem 4: Pointer Reassignment
```cpp
int a = 5, b = 10;
int* ptr = &a;
*ptr = 8;
ptr = &b;
*ptr = 3;
cout << a << " " << b;
```

**What's the output?**

<details>
<summary>Click for answer</summary>

**Output:** `8 3`

**Trace:**
1. `a = 5, b = 10`
2. `ptr = &a` (ptr points to a)
3. `*ptr = 8` → `a = 8`
4. `ptr = &b` (ptr now points to b)
5. `*ptr = 3` → `b = 3`
6. Output: `8 3`
</details>

---

## MCQs (FAST-Style)

### Q1. What is the size of a pointer on a 64-bit system?
A) 4 bytes  
B) 8 bytes  
C) Depends on the type it points to  
D) 16 bytes  

<details>
<summary>Answer</summary>
**B) 8 bytes**

Pointer size depends on system architecture (32-bit = 4 bytes, 64-bit = 8 bytes), NOT on what it points to.
</details>

### Q2. Which is valid?
A) `int* p = 5;`  
B) `int* p = &5;`  
C) `int x = 5; int* p = &x;`  
D) `int* p = *x;`  

<details>
<summary>Answer</summary>
**C) `int x = 5; int* p = &x;`**

A) Can't assign integer to pointer  
B) Can't take address of literal  
D) Syntax error (should be `&x`)
</details>

### Q3. What does this print?
```cpp
int x = 10;
int* p = &x;
cout << &p;
```
A) 10  
B) Address of x  
C) Address of p  
D) Compilation error  

<details>
<summary>Answer</summary>
**C) Address of p**

`&p` gives the address of the pointer variable itself.
</details>

---

## Key Takeaways

1. ✅ Pointer stores an **address**
2. ✅ `&` gets address, `*` accesses value
3. ✅ Always initialize pointers
4. ✅ Check for nullptr before dereferencing
5. ✅ Pointer type must match variable type
6. ✅ `int* p, q;` → p is pointer, q is int

**Next**: Move to Module 2 (Pointer Arithmetic) after solving Practice_01_Basics.md

---

*🎯 You've completed Module 1! Now practice before moving forward.*
