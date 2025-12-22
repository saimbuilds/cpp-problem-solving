# Pointer Mastery - Complete Reference Guide

> **Purpose**: Master pointers completely. This is 30% of your exam. Zero room for confusion.

---

## Table of Contents
1. [Pointer Basics](#1-pointer-basics)
2. [Pointer Arithmetic](#2-pointer-arithmetic)
3. [Pointers & Arrays](#3-pointers--arrays)
4. [Pointers & Functions](#4-pointers--functions)
5. [Common Pointer Traps](#5-common-pointer-traps)
6. [Speed Techniques](#6-speed-techniques)

---

## 1. Pointer Basics

### What is a Pointer?
A pointer is a variable that stores a **memory address**.

```cpp
int x = 10;
int *p = &x;  // p stores the ADDRESS of x

cout << x;    // 10 (value of x)
cout << &x;   // 0x7ffd... (address of x)
cout << p;    // 0x7ffd... (same as &x)
cout << *p;   // 10 (value at address p points to)
```

### Key Operators:
- `&` = "address of"
- `*` = "value at" (dereference)

### Visual Model:
```
Memory:  [Address]  [Value]
         0x1000     10        ← x lives here
         0x2000     0x1000    ← p lives here, stores address of x

int *p = &x;
     ↓
     p points to x
```

---

## 2. Pointer Arithmetic

### Rule: Pointer arithmetic moves by **SIZE OF TYPE**, not bytes!

```cpp
int arr[] = {10, 20, 30, 40};
int *p = arr;  // p points to arr[0]

p + 1  // Points to arr[1] (moves 4 bytes if int is 4 bytes)
p + 2  // Points to arr[2] (moves 8 bytes)
p + 3  // Points to arr[3] (moves 12 bytes)
```

### Visual:
```
Memory:  [10][20][30][40]
          ↑
          p

p + 1 →  [10][20][30][40]
              ↑

p + 2 →  [10][20][30][40]
                  ↑
```

### Operations:
```cpp
int arr[] = {1, 2, 3, 4, 5};
int *p = arr;

*p        // 1
*(p + 1)  // 2
*(p + 2)  // 3

p[0]      // 1 (equivalent to *p)
p[1]      // 2 (equivalent to *(p + 1))
p[2]      // 3 (equivalent to *(p + 2))
```

### Pointer Subtraction:
```cpp
int arr[] = {10, 20, 30, 40};
int *p1 = &arr[0];
int *p2 = &arr[3];

p2 - p1   // 3 (number of elements between them)
```

**Key**: Subtraction gives **element count**, not byte count!

---

## 3. Pointers & Arrays

### Critical Fact: Array name IS a pointer to first element!

```cpp
int arr[5] = {1, 2, 3, 4, 5};

arr        // Pointer to arr[0]
&arr[0]    // Pointer to arr[0] (same as arr)
*arr       // 1 (value at arr[0])
```

### Equivalences:
```cpp
arr[i]       ≡  *(arr + i)
&arr[i]      ≡  arr + i
```

### Examples:
```cpp
int arr[] = {10, 20, 30, 40};

arr[2]       // 30
*(arr + 2)   // 30 (same)
2[arr]       // 30 (weird but valid! a[b] = *(a+b) = *(b+a) = b[a])
```

---

### Pointer vs Array Name:

| Feature | Array Name | Pointer Variable |
|---------|-----------|------------------|
| Can reassign? | ❌ `arr = ...` is invalid | ✅ `p = arr` is valid |
| Can increment? | ❌ `arr++` is invalid | ✅ `p++` is valid |
| Size? | Fixed at compile time | Can point anywhere |

```cpp
int arr[5];
int *p = arr;

p++;      // VALID
arr++;    // INVALID (compile error)
```

---

## 4. Pointers & Functions

### Pass by Pointer vs Pass by Reference:

```cpp
// Method 1: Pass by pointer
void swap1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Method 2: Pass by reference
void swap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    
    swap1(&x, &y);  // Pass addresses
    // x = 10, y = 5
    
    swap2(x, y);    // Pass references
    // x = 5, y = 10
}
```

### When to Use Each:

| Use Case | Pass by Pointer | Pass by Reference |
|----------|----------------|-------------------|
| Modify original variable | ✅ | ✅ |
| Can be NULL | ✅ | ❌ |
| Cleaner syntax | ❌ | ✅ |
| More explicit at call site | ✅ (`&x` shows modification) | ❌ |

---

### Returning Pointers from Functions:

```cpp
// DANGER: Returning pointer to local variable
int* bad_function() {
    int x = 10;
    return &x;  // BAD! x destroyed after function ends
}

// SAFE: Returning pointer to dynamic memory
int* good_function() {
    int *p = new int;
    *p = 10;
    return p;  // OK, but caller must delete it
}

// SAFE: Returning pointer to static variable
int* okay_function() {
    static int x = 10;
    return &x;  // OK, static persists
}
```

---

### Arrays as Function Parameters:

```cpp
// All these are EQUIVALENT:
void func(int arr[]) { }
void func(int arr[10]) { }  // Size ignored!
void func(int *arr) { }

// All receive a POINTER, not array!
void func(int arr[]) {
    cout << sizeof(arr);  // 8 (pointer size), NOT array size!
}
```

**Key Insight**: Arrays ALWAYS decay to pointers when passed to functions!

---

## 5. Common Pointer Traps

### Trap 5.1: Pointer Increment Ambiguity
```cpp
int arr[] = {10, 20, 30};
int *p = arr;

*p++   // *(p++) → Use *p (10), THEN increment p
*++p   // *(++p) → Increment p FIRST, then use *p (20 if starting from arr)
++*p   // ++(*p) → Increment VALUE at p (changes arr[0] to 11)
(*p)++ // Same as ++*p but postfix
```

**Memory Trace:**
```
Initial:  p → [10][20][30]

*p++:     Returns 10, p now points to [20]
*++p:     p moves first, returns 20
++*p:     p stays, [10] becomes [11]
```

---

### Trap 5.2: Null Pointer Dereference
```cpp
int *p = nullptr;  // or NULL
*p = 10;           // CRASH! Cannot dereference null pointer

// Always check:
if (p != nullptr) {
    *p = 10;
}
```

---

### Trap 5.3: Uninitialized Pointers
```cpp
int *p;      // Wild pointer! Points to random memory
*p = 10;     // CRASH or undefined behavior

int *p = nullptr;  // Safe initialization
```

---

### Trap 5.4: Pointer Comparison
```cpp
int arr[] = {10, 20, 30};
int *p1 = arr;
int *p2 = arr + 1;

p1 < p2   // TRUE (p1 points before p2)
p1 == arr // TRUE
*p1 == *p2 // FALSE (10 != 20)
```

---

### Trap 5.5: Array Name Address Confusion
```cpp
int arr[10];

arr       // Type: int*, value: address of arr[0]
&arr      // Type: int(*)[10], value: same address but different type!
&arr[0]   // Type: int*, value: address of arr[0]

// Comparison:
arr == &arr[0]  // TRUE (same address)
arr == &arr     // TRUE (same address, but conceptually different!)

// Arithmetic difference:
arr + 1    // Points to arr[1] (4 bytes ahead if int is 4 bytes)
&arr + 1   // Points 40 bytes ahead (entire array size!)
```

---

### Trap 5.6: Const Pointers

```cpp
// Pointer to const int (cannot change value)
const int *p1 = &x;
*p1 = 10;  // ERROR
p1 = &y;   // OK

// Const pointer to int (cannot change pointer)
int * const p2 = &x;
*p2 = 10;  // OK
p2 = &y;   // ERROR

// Const pointer to const int (both immutable)
const int * const p3 = &x;
*p3 = 10;  // ERROR
p3 = &y;   // ERROR
```

**Mnemonic**: Read right-to-left
- `const int *p` = pointer to const int
- `int * const p` = const pointer to int

---

## 6. Speed Techniques

### Technique 1: Draw Quick Memory Diagrams
For complex pointer problems, 10 seconds of drawing saves 2 minutes:

```
Question: What does this output?
int arr[] = {1, 2, 3, 4};
int *p = arr + 1;
cout << *p++ << *p;

Quick Diagram:
Initial: p → [1][2][3][4]
              ↑ *p = 2, then p++
After:   p → [1][2][3][4]
                  ↑ *p = 3
Output: 23
```

---

### Technique 2: Operator Precedence Shortcut

**Priority (High → Low):** `[]` > `++/--` (postfix) > `*` > `++/--` (prefix)

```cpp
*p[i]    // *(p[i]) - array of pointers
(*p)[i]  // dereference p, then index

*p++     // *(p++) - use *p, move p
*++p     // *(++p) - move p, use *p
```

**Exam Hack**: If in doubt, add parentheses mentally and solve inside-out.

---

### Technique 3: Substitution for Verification

If unsure about expression, substitute with simple values:

```cpp
Question: What is arr[2] when arr = {10, 20, 30}?
Method: arr[2] = *(arr + 2)
        = *(address_of_10 + 2*sizeof(int))
        = value at third position
        = 30
```

---

### Technique 4: Pattern Recognition

Learn to spot these instantly:

| Pattern | Output |
|---------|--------|
| `arr == &arr[0]` | TRUE |
| `*arr` | arr[0] |
| `*(arr + i)` | arr[i] |
| `arr[i][j]` | `*(*(arr + i) + j)` |
| `*p++` | Use, then move |
| `*++p` | Move, then use |

---

## Exam Day Checklist

Before solving any pointer problem:

1. ✅ **Initialize value**: What does the pointer point to initially?
2. ✅ **Check operators**: Postfix vs prefix? Dereference vs address?
3. ✅ **Trace execution**: What happens at each step?
4. ✅ **Verify output**: Does the final value make sense?

---

## Practice Problem Template

When dry-running pointer code:

```
Step 1: Draw memory layout
Step 2: Mark initial pointer position
Step 3: Execute line by line:
        - If ++/-- → move pointer or change value?
        - If * → dereference and use value
        - If [] → convert to pointer arithmetic
Step 4: Write final output
```

---

## Quick Reference Table

### Pointer Operations Summary:

| Expression | Meaning | Example (int *p = arr, arr = {10,20,30}) |
|------------|---------|------------------------------------------|
| `p` | Address stored in p | 0x1000 |
| `*p` | Value at address p | 10 |
| `&p` | Address of pointer itself | 0x2000 |
| `p + i` | Address i elements ahead | arr + 1 |
| `*(p + i)` | Value i elements ahead | 20 |
| `p++` | Move pointer forward | Now points to 20 |
| `(*p)++` | Increment value at p | Changes 10 to 11 |
| `p[i]` | Same as `*(p + i)` | 20 |

---

**Next Step**: Apply this knowledge in **Dry Run Set 1: Pointer Arithmetic Hell**!

You'll trace through 15 tricky pointer problems that cover every trap above. No memorization - just pattern recognition through practice.
