# Module 4: Dynamic Memory Allocation - 1D Arrays
## The Power of `new` and `delete`

> **Learning Objective**: Master runtime memory allocation for arrays of any size - the foundation of advanced C++ programming.

---

## Table of Contents
1. [Stack vs Heap Memory](#stack-vs-heap-memory)
2. [The `new` and `delete` Operators](#the-new-and-delete-operators)
3. [Dynamic Arrays](#dynamic-arrays)
4. [Memory Leaks](#memory-leaks)
5. [Common Patterns](#common-patterns)
6. [Dangerous Mistakes](#dangerous-mistakes)

---

## Stack vs Heap Memory

### Stack Memory (Static Allocation)
```cpp
int x = 10;           // Stack
int arr[5];           // Stack
int arr[n];           // ERROR! Size must be known at compile time
```

**Limitations:**
- ❌ Size must be constant (known at compile time)
- ❌ Limited size (~1-8 MB typically)
- ❌ Automatically destroyed when scope ends

### Heap Memory (Dynamic Allocation)
```cpp
int* ptr = new int;         // Heap - single int
int* arr = new int[n];      // Heap - array of size n (runtime!)
```

**Advantages:**
- ✅ Size can be determined at runtime
- ✅ Much larger available (~GBs)
- ✅ Persists until explicitly deleted

---

## The `new` and `delete` Operators

### Allocating Single Variable

```cpp
int* ptr = new int;      // Allocate memory for 1 int
*ptr = 42;               // Use it
cout << *ptr;            // Output: 42
delete ptr;              // Free the memory
ptr = nullptr;           // Good practice!
```

### Allocating with Initialization

```cpp
int* ptr = new int(100);     // Allocate and initialize to 100
double* dPtr = new double(3.14);

cout << *ptr;    // Output: 100
cout << *dPtr;   // Output: 3.14

delete ptr;
delete dPtr;
```

---

## Dynamic Arrays

### Syntax

```cpp
int size;
cout << "Enter size: ";
cin >> size;

int* arr = new int[size];  // Allocate array of 'size' elements

// Use it
for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
}

delete[] arr;  // Free the array (note the [] !)
arr = nullptr;
```

### ⚠️ CRITICAL: `delete` vs `delete[]`

```cpp
int* single = new int;
int* array = new int[10];

delete single;    // For single variable
delete[] array;   // For array (note [] !)

// WRONG:
delete array;     // Memory leak! Undefined behavior!
delete[] single;  // Undefined behavior!
```

---

## Complete Example: Dynamic Array Input/Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    // Allocate
    int* arr = new int[n];
    
    // Input
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Process (find sum)
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
    
    // Deallocate
    delete[] arr;
    arr = nullptr;
    
    return 0;
}
```

---

## Memory Leaks

### What is a Memory Leak?

Memory allocated but never freed → program keeps consuming memory.

### ❌ Example: Memory Leak
```cpp
void badFunction() {
    int* arr = new int[1000];
    // ... use array ...
    // Oops, forgot to delete!
}  // arr pointer destroyed, but memory still allocated!

// Call this 1000 times → 4 MB leaked!
for (int i = 0; i < 1000; i++) {
    badFunction();
}
```

### ✅ Example: Proper Cleanup
```cpp
void goodFunction() {
    int* arr = new int[1000];
    // ... use array ...
    delete[] arr;  // Cleaned up!
}
```

### Another Common Leak: Reassignment
```cpp
int* ptr = new int[100];  // Allocate 100 ints
ptr = new int[200];       // Allocate 200 more - first 100 leaked!

// Fix:
int* ptr = new int[100];
delete[] ptr;             // Free first
ptr = new int[200];       // Then allocate new
```

---

## Common Patterns

### Pattern 1: Input Array Size at Runtime
```cpp
int n;
cin >> n;
int* arr = new int[n];

// Use array...

delete[] arr;
```

### Pattern 2: Resize Array (Simulated)
```cpp
// C++ doesn't support true resize, must allocate new + copy

int* old_arr = new int[5];
// Fill old array...

int new_size = 10;
int* new_arr = new int[new_size];

// Copy old data
for (int i = 0; i < 5; i++) {
    new_arr[i] = old_arr[i];
}

delete[] old_arr;  // Free old
old_arr = new_arr; // Point to new
```

### Pattern 3: Function Returning Dynamic Array
```cpp
int* createArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * i;  // Squares
    }
    return arr;  // OK! Heap memory persists
}

int main() {
    int* myArr = createArray(5);
    // Use array...
    delete[] myArr;  // Don't forget!
    return 0;
}
```

### Pattern 4: Safe Deletion
```cpp
if (ptr != nullptr) {
    delete[] ptr;
    ptr = nullptr;
}
```

---

## Dangerous Mistakes

### ❌ Mistake 1: Using After Delete (Dangling Pointer)
```cpp
int* arr = new int[5];
delete[] arr;
arr[0] = 10;  // UNDEFINED BEHAVIOR! Memory freed!
```

**Fix:** Set to nullptr after delete
```cpp
delete[] arr;
arr = nullptr;
```

### ❌ Mistake 2: Forgetting `[]` for Arrays
```cpp
int* arr = new int[100];
delete arr;  // WRONG! Should be delete[]
```

### ❌ Mistake 3: Double Delete
```cpp
int* arr = new int[10];
delete[] arr;
delete[] arr;  // CRASH! Already freed!
```

**Fix:** Set to nullptr
```cpp
delete[] arr;
arr = nullptr;
if (arr != nullptr) {
    delete[] arr;  // Won't execute
}
```

### ❌ Mistake 4: Memory Leak from Exception/Early Return
```cpp
void riskyFunction() {
    int* arr = new int[1000];
    
    if (someCondition) {
        return;  // LEAK! Forgot to delete
    }
    
    delete[] arr;
}
```

**Fix:**
```cpp
void safeFunction() {
    int* arr = new int[1000];
    
    if (someCondition) {
        delete[] arr;
        return;
    }
    
    delete[] arr;
}
```

---

## Dry Run Examples

### Example 1: Basic Allocation
```cpp
int* p = new int(50);
*p = *p + 10;
cout << *p;
delete p;
```
**Output:** `60`

---

### Example 2: Dynamic Array
```cpp
int n = 4;
int* arr = new int[n];
for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
}
cout << arr[2];
delete[] arr;
```
**Output:** `4`

---

### Example 3: Memory Leak?
```cpp
void func() {
    int* ptr = new int[100];
    ptr[0] = 10;
    // Missing delete!
}

int main() {
    func();
    func();
    return 0;
}
```
**Result:** Memory leak! 200 ints leaked (800 bytes on 32-bit)

---

## MCQs

### Q1. What's the difference?
```cpp
int arr[10];        // A
int* arr = new int[10];  // B
```
Which is TRUE?  
A) A is on stack, B is on heap  
B) A size compile-time, B size runtime  
C) B needs delete[], A auto-freed  
D) All of above  

<details>
<summary>Answer</summary>
**D)** All statements are true
</details>

### Q2. What's wrong?
```cpp
int* arr = new int[50];
delete arr;
```
A) Nothing  
B) Should use `delete[]`  
C) Should use `free()`  
D) Memory leak  

<details>
<summary>Answer</summary>
**B)** Must use delete[] for arrays
</details>

### Q3. What happens?
```cpp
int* p = new int(10);
delete p;
*p = 20;
```
A) p is 20  
B) Compilation error  
C) Undefined behavior  
D) p is 10  

<details>
<summary>Answer</summary>
**C)** Using memory after deletion is undefined behavior
</details>

---

## Key Takeaways

1. ✅ `new` allocates memory on heap
2. ✅ `delete` for single, `delete[]` for arrays
3. ✅ Heap memory persists until deleted
4. ✅ Always delete what you new
5. ✅ Set pointer to nullptr after delete
6. ✅ Memory leaks happen when forgetting delete
7. ✅ Can allocate arrays of runtime size

**Next**: Practice_04_Dynamic1D.md → Module 5 (2D Dynamic Arrays!)

---

*🎯 This is THE critical module - master it completely!*
