# Memory Models - Stack vs Heap & Dynamic Allocation

> **Purpose**: Understand memory management completely. Dynamic memory = 20% of your exam.

---

## Table of Contents
1. [Memory Layout Overview](#1-memory-layout-overview)
2. [Stack Memory](#2-stack-memory)
3. [Heap Memory (Dynamic)](#3-heap-memory-dynamic)
4. [1D Dynamic Arrays](#4-1d-dynamic-arrays)
5. [2D Dynamic Arrays](#5-2d-dynamic-arrays)
6. [3D Dynamic Arrays](#6-3d-dynamic-arrays)
7. [Common Memory Mistakes](#7-common-memory-mistakes)
8. [Exam Patterns](#8-exam-patterns)

---

## 1. Memory Layout Overview

### Program Memory Structure:
```
High Address
┌─────────────┐
│   Stack     │ ← Local variables, function parameters
│      ↓      │   (grows downward)
├─────────────┤
│             │
│    Free     │
│             │
├─────────────┤
│      ↑      │
│    Heap     │ ← Dynamic memory (new/malloc)
├─────────────┤   (grows upward)
│    BSS      │ ← Uninitialized global/static
├─────────────┤
│    Data     │ ← Initialized global/static
├─────────────┤
│    Code     │ ← Program instructions
└─────────────┘
Low Address
```

---

## 2. Stack Memory

### Characteristics:
- ✅ **Automatic management** (no new/delete needed)
- ✅ **Fast allocation**
- ✅ **Limited size** (usually ~8MB)
- ✅ **LIFO** (Last In, First Out)
- ❌ **Dies when function ends**

### Example:
```cpp
void func() {
    int x = 10;        // On stack
    int arr[100];      // On stack
    // x and arr destroyed when func() returns
}
```

### Stack Visualization:
```
main() calls:          func() executes:        func() returns:
┌─────────┐           ┌─────────┐             ┌─────────┐
│  main   │           │ arr[100]│             │  main   │
│ locals  │           │    x    │   →         │ locals  │
└─────────┘           │  main   │             └─────────┘
                      │ locals  │
                      └─────────┘
```

**Key**: Stack variables automatically cleaned up!

---

## 3. Heap Memory (Dynamic)

### Characteristics:
- ✅ **Manual management** (you control lifetime)
- ✅ **Larger size** (limited by system RAM)
- ✅ **Persists until deleted**
- ❌ **Slower allocation**
- ❌ **Memory leaks if not freed**

### Syntax:
```cpp
// Allocation
int *p = new int;         // Single int
int *arr = new int[10];   // Array of 10 ints

// Usage
*p = 5;
arr[3] = 42;

// Deallocation (MUST DO!)
delete p;          // For single variable
delete[] arr;      // For arrays
```

### Heap Visualization:
```
Stack:              Heap:
┌─────────┐        ┌──────────────┐
│ p (ptr) │───────→│ int value: 5 │
└─────────┘        └──────────────┘

┌─────────┐        ┌───────────────────┐
│arr (ptr)│───────→│[0][1][2]...[9]    │
└─────────┘        │ 10 ints           │
                   └───────────────────┘
```

**Key**: Pointer lives on stack, data lives on heap!

---

## 4. 1D Dynamic Arrays

### Allocation Pattern:
```cpp
int size;
cin >> size;

// Allocate
int *arr = new int[size];

// Use like normal array
arr[0] = 10;
arr[1] = 20;
for (int i = 0; i < size; i++)
    cout << arr[i];

// MUST free when done
delete[] arr;
arr = nullptr;  // Good practice
```

### Common Operations:

#### Copy 1D Array:
```cpp
int *source = new int[5]{1, 2, 3, 4, 5};
int *dest = new int[5];

for (int i = 0; i < 5; i++)
    dest[i] = source[i];

// Don't forget to free both!
delete[] source;
delete[] dest;
```

#### Resize 1D Array:
```cpp
int *old_arr = new int[5];
int old_size = 5;
int new_size = 10;

// Create new larger array
int *new_arr = new int[new_size];

// Copy old data
for (int i = 0; i < old_size; i++)
    new_arr[i] = old_arr[i];

// Free old array
delete[] old_arr;

// Use new array
old_arr = new_arr;
```

---

## 5. 2D Dynamic Arrays

### Method 1: Array of Pointers (Most Common in Exams)

```cpp
int rows = 3, cols = 4;

// Step 1: Allocate array of row pointers
int **arr = new int*[rows];

// Step 2: Allocate each row
for (int i = 0; i < rows; i++)
    arr[i] = new int[cols];

// Step 3: Use like normal 2D array
arr[0][0] = 10;
arr[1][2] = 42;

for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        cout << arr[i][j];

// Step 4: Deallocate (REVERSE ORDER!)
for (int i = 0; i < rows; i++)
    delete[] arr[i];  // Free each row
delete[] arr;         // Free row pointer array
```

### Memory Model:
```
Stack:          Heap:
┌──────┐       ┌───┐
│ arr  │──────→│ * │──→ [0][1][2][3]  (row 0)
└──────┘       │ * │──→ [0][1][2][3]  (row 1)
               │ * │──→ [0][1][2][3]  (row 2)
               └───┘
           array of    each row is
           pointers    an array
```

### Method 2: Single Block (Less Common)

```cpp
int rows = 3, cols = 4;

// Allocate as single 1D block
int *arr = new int[rows * cols];

// Access using formula: arr[i * cols + j]
arr[0 * cols + 0] = 10;  // arr[0][0]
arr[1 * cols + 2] = 42;  // arr[1][2]

// Use
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        arr[i * cols + j] = i * j;

// Deallocate (much simpler!)
delete[] arr;
```

**Exam Tip**: Array of pointers is more common. Know both!

---

## 6. 3D Dynamic Arrays

### Allocation (Maximum Complexity Expected):

```cpp
int x = 2, y = 3, z = 4;  // dimensions

// Step 1: Allocate array of 2D arrays
int ***arr = new int**[x];

// Step 2: For each 2D array, allocate array of row pointers
for (int i = 0; i < x; i++)
    arr[i] = new int*[y];

// Step 3: For each row, allocate actual data
for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
        arr[i][j] = new int[z];

// Use: arr[i][j][k]
arr[0][0][0] = 10;
arr[1][2][3] = 42;

// Deallocate (REVERSE ORDER! Critical!)
for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
        delete[] arr[i][j];  // Free each row
    }
    delete[] arr[i];  // Free each 2D array
}
delete[] arr;  // Free main array
```

### Memory Structure:
```
arr
 ↓
[*][*]                  ← x pointers (2D arrays)
 ↓  ↓
 ↓  [*][*][*]           ← y pointers (rows) for 2nd 2D array
 ↓   ↓  ↓  ↓
 ↓   ↓  ↓  [][][]       ← z elements (actual data)
 ↓   ↓  ↓
 ↓   ↓  [][][]
 ↓   ↓
 ↓   [][][]
 ↓
[*][*][*]               ← y pointers (rows) for 1st 2D array
 ↓  ↓  ↓
 ↓  ↓  [][][]
 ↓  ↓
 ↓  [][][]
 ↓
[][][]
```

---

## 7. Common Memory Mistakes

### Mistake 1: Memory Leak
```cpp
// BAD: Never freed!
void func() {
    int *p = new int[100];
    // ... use p ...
}  // Memory leaked!

// GOOD:
void func() {
    int *p = new int[100];
    // ... use p ...
    delete[] p;  // Freed!
}
```

---

### Mistake 2: Dangling Pointer
```cpp
// BAD: Using after delete
int *p = new int(10);
delete p;
cout << *p;  // CRASH! Dangling pointer

// GOOD:
int *p = new int(10);
delete p;
p = nullptr;  // Mark as invalid
if (p != nullptr)
    cout << *p;
```

---

### Mistake 3: Double Delete
```cpp
// BAD:
int *p = new int(10);
delete p;
delete p;  // CRASH! Double free

// GOOD:
int *p = new int(10);
delete p;
p = nullptr;  // Prevents double delete
```

---

### Mistake 4: Wrong Delete Form
```cpp
// BAD:
int *arr = new int[10];
delete arr;  // WRONG! Use delete[] for arrays

// GOOD:
int *arr = new int[10];
delete[] arr;  // Correct!
```

**Rule**: Use `delete[]` for arrays, `delete` for single objects.

---

### Mistake 5: Out of Order Deallocation (2D/3D)
```cpp
// BAD:
int **arr = new int*[3];
for (int i = 0; i < 3; i++)
    arr[i] = new int[4];

delete[] arr;  // WRONG! Rows not freed, memory leak!

// GOOD:
for (int i = 0; i < 3; i++)
    delete[] arr[i];  // Free rows FIRST
delete[] arr;          // Then free main array
```

**Rule**: Deallocate in REVERSE order of allocation!

---

## 8. Exam Patterns

### Pattern 1: Allocate, Fill, Deallocate
```cpp
// Typical exam question structure:
int n;
cin >> n;

// Allocate
int *arr = new int[n];

// Fill
for (int i = 0; i < n; i++)
    arr[i] = i * 2;

// Deallocate
delete[] arr;
```

---

### Pattern 2: Function Returning Dynamic Array
```cpp
int* createArray(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i;
    return arr;  // OK to return, caller must delete
}

int main() {
    int *data = createArray(10);
    // ... use data ...
    delete[] data;  // MUST delete!
}
```

---

### Pattern 3: 2D Array Parameter
```cpp
void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j;
}

int main() {
    int **mat = new int*[3];
    for (int i = 0; i < 3; i++)
        mat[i] = new int[4];
    
    fillMatrix(mat, 3, 4);
    
    // Cleanup
    for (int i = 0; i < 3; i++)
        delete[] mat[i];
    delete[] mat;
}
```

---

## Quick Reference

### Memory Allocation Cheatsheet:

| Dimension | Allocation | Deallocation |
|-----------|------------|--------------|
| 1D | `int *arr = new int[n]` | `delete[] arr` |
| 2D | `int **arr = new int*[rows]`<br>`for(i) arr[i] = new int[cols]` | `for(i) delete[] arr[i]`<br>`delete[] arr` |
| 3D | See section 6 | Reverse of allocation |

---

## Exam Day Checklist

For any dynamic memory problem:

1. ✅ **Count allocations**: How many `new` statements?
2. ✅ **Match deletions**: Same number of `delete` statements?
3. ✅ **Correct delete form**: `delete` vs `delete[]`?
4. ✅ **Right order**: Deallocate in reverse order?
5. ✅ **Null check**: Set to nullptr after delete?

---

## Practice Template

When writing dynamic memory code:

```cpp
// 1. Declare pointer
int *arr = nullptr;

// 2. Allocate
arr = new int[size];

// 3. Check allocation (optional but good)
if (arr == nullptr) {
    cout << "Allocation failed!";
    return;
}

// 4. Use
for (int i = 0; i < size; i++)
    arr[i] = i;

// 5. Deallocate
delete[] arr;
arr = nullptr;
```

---

**Next**: Practice with **Dynamic Memory Bootcamp** for hands-on problems!

You'll solve 55 problems covering 1D, 2D, and 3D arrays with all the traps above.
