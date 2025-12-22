# Common Mistakes & How to Avoid Them
## Learn from These - Don't Repeat Them!

> **This document catalogs the most common pointer/dynamic memory mistakes seen in FAST exams with clear explanations and fixes.**

---

## Category 1: Delete/Deallocation Errors

### ❌ Mistake 1.1: Using `delete` Instead of `delete[]`
```cpp
int* arr = new int[100];
delete arr;  // WRONG!
```

**Why it's wrong:** Arrays need `delete[]`, not `delete`.

**Fix:**
```cpp
int* arr = new int[100];
delete[] arr;  // CORRECT
```

**Impact:** Undefined behavior, memory leak, possible crash.

---

### ❌ Mistake 1.2: Wrong 2D Deallocation Order
```cpp
int** mat = new int*[5];
for (int i = 0; i < 5; i++)
    mat[i] = new int[10];

delete[] mat;  // WRONG! Rows not freed
```

**Why it's wrong:** Rows are allocated separately and must be deleted first.

**Fix:**
```cpp
// Delete rows first
for (int i = 0; i < 5; i++) {
    delete[] mat[i];
}
// Then delete array of pointers
delete[] mat;
```

**Impact:** Memory leak of 50 integers (5 rows × 10 cols).

---

### ❌ Mistake 1.3: Using Wrong Delete Operator
```cpp
int** mat = new int*[3];
for (int i = 0; i < 3; i++)
    mat[i] = new int[4];

for (int i = 0; i < 3; i++)
    delete mat[i];  // Missing []
delete mat;  // Missing []
```

**Fix:**
```cpp
for (int i = 0; i < 3; i++)
    delete[] mat[i];  // Correct
delete[] mat;  // Correct
```

---

### ❌ Mistake 1.4: Double Delete
```cpp
int* arr = new int[10];
delete[] arr;
delete[] arr;  // CRASH! Already freed
```

**Fix:**
```cpp
delete[] arr;
arr = nullptr;  // Prevent double delete
if (arr != nullptr)
    delete[] arr;  // Won't execute now
```

---

## Category 2: Memory Leaks

### ❌ Mistake 2.1: Forgetting to Delete
```cpp
void function() {
    int* arr = new int[1000];
    // Use array...
    // Oops, forgot to delete!
}  // arr pointer destroyed, memory still allocated
```

**Fix:**
```cpp
void function() {
    int* arr = new int[1000];
    // Use array...
    delete[] arr;  // Don't forget!
}
```

**Impact:** Each call leaks 4000 bytes (assuming 4-byte int).

---

### ❌ Mistake 2.2: Memory Leak from Reassignment
```cpp
int* ptr = new int[100];
ptr = new int[200];  // First 100 leaked!
```

**Fix:**
```cpp
int* ptr = new int[100];
delete[] ptr;        // Free first
ptr = new int[200];  // Then allocate new
```

**Impact:** 400 bytes leaked (100 ints × 4 bytes).

---

### ❌ Mistake 2.3: Memory Leak from Early Return
```cpp
void process(bool condition) {
    int* data = new int[500];
    
    if (condition) {
        return;  // LEAK! Forgot to delete
    }
    
    delete[] data;
}
```

**Fix:**
```cpp
void process(bool condition) {
    int* data = new int[500];
    
    if (condition) {
        delete[] data;  // Delete before return
        return;
    }
    
    delete[] data;
}
```

---

## Category 3: Dangling Pointers

### ❌ Mistake 3.1: Using After Delete
```cpp
int* ptr = new int(42);
delete ptr;
cout << *ptr;  // UNDEFINED BEHAVIOR!
```

**Fix:**
```cpp
int* ptr = new int(42);
cout << *ptr;  // Use before delete
delete ptr;
ptr = nullptr;  // Prevent accidental use
```

---

### ❌ Mistake 3.2: Returning Local Variable Address
```cpp
int* getNumber() {
    int x = 10;    // Local variable
    return &x;     // DANGER! x destroyed when function ends
}

int main() {
    int* ptr = getNumber();
    cout << *ptr;  // CRASH or garbage!
}
```

**Fix:** Use dynamic allocation or return by value.
```cpp
int* getNumber() {
    int* x = new int(10);  // Heap allocation
    return x;  // Safe - caller must delete
}

int main() {
    int* ptr = getNumber();
    cout << *ptr;
    delete ptr;  // Don't forget!
}
```

---

## Category 4: Pointer Arithmetic Errors

### ❌ Mistake 4.1: Out of Bounds Access
```cpp
int* arr = new int[5];
arr[10] = 100;  // UNDEFINED! Out of bounds
```

**Fix:** Always check bounds.
```cpp
int* arr = new int[5];
int size = 5;

if (index >= 0 && index < size) {
    arr[index] = value;  // Safe
}
```

---

### ❌ Mistake 4.2: Modifying Array Name
```cpp
int arr[5];
arr++;  // ERROR! Array name is not modifiable
```

**Fix:** Use a pointer variable.
```cpp
int arr[5];
int* ptr = arr;
ptr++;  // OK
```

---

### ❌ Mistake 4.3: Wrong Operator Precedence
```cpp
int arr[] = {1, 2, 3};
int* ptr = arr;
cout << *ptr++;  // Might think this increments value
```

**What it does:** Uses value, then increments pointer.

**If you want to increment value:**
```cpp
cout << (*ptr)++;  // Correct for incrementing value
// or
cout << ++*ptr;    // Pre-increment value
```

---

## Category 5: Initialization Errors

### ❌ Mistake 5.1: Uninitialized Pointer
```cpp
int* ptr;      // Contains garbage address
*ptr = 10;     // CRASH! Dereferencing garbage
```

**Fix:**
```cpp
int* ptr = nullptr;  // Always initialize
// or
int x = 5;
int* ptr = &x;  // Initialize with valid address
```

---

### ❌ Mistake 5.2: Not Checking nullptr
```cpp
int* ptr = searchArray(arr, size, target);
cout << *ptr;  // CRASH if search failed (nullptr)
```

**Fix:**
```cpp
int* ptr = searchArray(arr, size, target);
if (ptr != nullptr) {
    cout << *ptr;  // Safe
} else {
    cout << "Not found";
}
```

---

## Category 6: Copy Issues

### ❌ Mistake 6.1: Shallow Copy Problem
```cpp
int* arr1 = new int[5]{1, 2, 3, 4, 5};
int* arr2 = arr1;  // Shallow copy!

arr2[0] = 100;
cout << arr1[0];  // 100 (both modified!)

delete[] arr1;
delete[] arr2;  // CRASH! Double delete
```

**Fix:** Deep copy
```cpp
int* arr1 = new int[5]{1, 2, 3, 4, 5};
int* arr2 = new int[5];

for (int i = 0; i < 5; i++) {
    arr2[i] = arr1[i];  // Independent copy
}

delete[] arr1;
delete[] arr2;  // Safe
```

---

### ❌ Mistake 6.2: 2D Shallow Copy
```cpp
int** mat1 = createMatrix(3, 4);
int** mat2 = mat1;  // Shallow!

mat2[0][0] = 100;  // Also changes mat1!
```

**Fix:** Deep copy for 2D
```cpp
int** mat2 = new int*[3];
for (int i = 0; i < 3; i++) {
    mat2[i] = new int[4];
    for (int j = 0; j < 4; j++) {
        mat2[i][j] = mat1[i][j];
    }
}
```

---

## Category 7: Function Parameter Errors

### ❌ Mistake 7.1: Expecting Modification Without Pointer
```cpp
void increment(int x) {
    x++;  // Only modifies local copy
}

int main() {
    int num = 5;
    increment(num);
    cout << num;  // Still 5!
}
```

**Fix:** Use pointer parameter
```cpp
void increment(int* x) {
    (*x)++;  // Modifies original
}

int main() {
    int num = 5;
    increment(&num);
    cout << num;  // 6
}
```

---

### ❌ Mistake 7.2: Swapping Pointer Values Instead of Pointed Values
```cpp
void wrongSwap(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;  // Only swaps local pointers!
}

int main() {
    int x = 5, y = 10;
    wrongSwap(&x, &y);
    cout << x << " " << y;  // Still 5 10
}
```

**Fix:**
```cpp
void correctSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;  // Swaps values
}
```

---

## Quick Reference: Error Detection Checklist

When reviewing your code, check for:

- [ ] Every `new` has matching `delete`
- [ ] Arrays use `delete[]`, not `delete`
- [ ] 2D arrays: rows deleted before array of pointers
- [ ] No pointer used after `delete`
- [ ] All pointers initialized
- [ ] `nullptr` checked before dereferencing
- [ ] No returning address of local variables
- [ ] Deep copy for independent arrays
- [ ] Array bounds not exceeded
- [ ] No double delete

---

## Exam Strategy

1. **Read carefully** - Is it `delete` or `delete[]`?
2. **Trace 2D deallocation** - Always check order
3. **Count memory leaks** - Track every `new` and `delete`
4. **Check nullptr** - Before dereferencing returned pointers
5. **Watch expressions** - `*ptr++` ≠ `(*ptr)++`

---

*Learn these mistakes now so you don't make them in the exam!*
