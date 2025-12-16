# Module 3: Pointers & Functions
## Mastering Pass-by-Reference and Function Pointers

> **Learning Objective**: Understand how pointers enable powerful function patterns - pass by value vs reference, returning pointers, and function arguments.

---

## Table of Contents
1. [Pass by Value vs Pass by Pointer](#pass-by-value-vs-pass-by-pointer)
2. [Returning Pointers from Functions](#returning-pointers-from-functions)
3. [Array as Function Parameters](#array-as-function-parameters)
4. [Common Patterns](#common-patterns)
5. [Dangerous Mistakes](#dangerous-mistakes)

---

## Pass by Value vs Pass by Pointer

### Pass by Value (Copy)
```cpp
void increment(int x) {
    x = x + 10;  // Only modifies local copy
}

int main() {
    int num = 5;
    increment(num);
    cout << num;  // Output: 5 (unchanged!)
    return 0;
}
```

### Pass by Pointer (Reference to Original)
```cpp
void increment(int* x) {
    *x = *x + 10;  // Modifies original!
}

int main() {
    int num = 5;
    increment(&num);  // Pass address
    cout << num;  // Output: 15 (changed!)
    return 0;
}
```

### Comparison Table

| Aspect | Pass by Value | Pass by Pointer |
|--------|--------------|-----------------|
| Syntax | `func(x)` | `func(&x)` |
| Function parameter | `void func(int x)` | `void func(int* x)` |
| Access | `x` | `*x` |
| Original modified? | ❌ No | ✅ Yes |
| Use case | Read-only | Want to modify |

---

## Multiple Return Values Using Pointers

Can't return multiple values? Use pointers!

### Traditional (Can Only Return 1 Value)
```cpp
int add(int a, int b) {
    return a + b;  // Only 1 return value
}
```

### Using Pointers (Simulated Multiple Returns)
```cpp
void calculate(int a, int b, int* sum, int* product) {
    *sum = a + b;
    *product = a * b;
}

int main() {
    int x = 5, y = 3;
    int sum, product;
    
    calculate(x, y, &sum, &product);
    cout << sum << " " << product;  // Output: 8 15
    return 0;
}
```

### Example: Swap Function
```cpp
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    cout << x << " " << y;  // Output: 20 10
    return 0;
}
```

---

## Returning Pointers from Functions

### ✅ Valid: Returning Pointer to External Data
```cpp
int* findMax(int* arr, int size) {
    int* max = arr;  // Points to first element
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }
    return max;  // Returns pointer to max element
}

int main() {
    int arr[] = {5, 12, 3, 19, 7};
    int* maxPtr = findMax(arr, 5);
    cout << *maxPtr;  // Output: 19
    return 0;
}
```

### ❌ DANGEROUS: Returning Pointer to Local Variable
```cpp
int* createNumber() {
    int x = 10;  // Local variable
    return &x;   // DANGER! x will be destroyed
}

int main() {
    int* ptr = createNumber();
    cout << *ptr;  // UNDEFINED BEHAVIOR!
    return 0;
}
```

**Why dangerous?** Local variables are destroyed when function ends. Pointer points to garbage!

---

## Array as Function Parameters

### Key Fact: Arrays Passed as Pointers

When you pass an array to a function, it **decays to a pointer** to the first element.

```cpp
void printArray(int arr[], int size) {
    // arr is actually int*
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// These are ALL equivalent:
void func1(int arr[], int size) { }
void func2(int* arr, int size) { }
void func3(int arr[10], int size) { } // Size ignored!
```

### Example: Array Modification
```cpp
void doubleValues(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= 2;  // or arr[i] *= 2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    doubleValues(arr, 4);
    // arr is now {2, 4, 6, 8}
    return 0;
}
```

### Why Size Parameter is Needed

Arrays don't carry size information when passed!

```cpp
void printArray(int* arr) {
    // How many elements? WE DON'T KNOW!
    // That's why we need size parameter
}

void printArray(int* arr, int size) {
    // Now we know!
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```

---

## Common Patterns

### Pattern 1: Input/Output Parameters
```cpp
void getSumAndAvg(int* arr, int size, int* sum, double* avg) {
    *sum = 0;
    for (int i = 0; i < size; i++) {
        *sum += arr[i];
    }
    *avg = (double)(*sum) / size;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int sum;
    double avg;
    
    getSumAndAvg(arr, 4, &sum, &avg);
    cout << sum << " " << avg;  // Output: 100 25
    return 0;
}
```

### Pattern 2: Finding Element (Return Pointer)
```cpp
int* findElement(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == target) {
            return arr + i;  // Return pointer to found element
        }
    }
    return nullptr;  // Not found
}

int main() {
    int arr[] = {5, 10, 15, 20};
    int* result = findElement(arr, 4, 15);
    
    if (result != nullptr) {
        cout << "Found at index: " << (result - arr);  // Output: 2
        *result = 100;  // Can modify through pointer!
    }
    return 0;
}
```

### Pattern 3: Const Pointers (Read-Only)
```cpp
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        // arr[i] = 10;  // ERROR! Can't modify const
    }
}
```

---

## Dangerous Mistakes

### ❌ Mistake 1: Forgetting to Pass Address
```cpp
void increment(int* x) {
    *x += 10;
}

int main() {
    int num = 5;
    increment(num);  // ERROR! Need &num
    return 0;
}
```

### ❌ Mistake 2: Dereferencing When Not Needed
```cpp
void func(int* x) {
    x = x + 10;  // Wrong! Modifying pointer, not value
}

// Should be:
void func(int* x) {
    *x = *x + 10;  // Correct!
}
```

### ❌ Mistake 3: Returning Local Address
```cpp
int* getArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;  // DANGER! arr is local
}
```

**Fix:** Use dynamic memory (covered in Module 4!)

### ❌ Mistake 4: Not Checking nullptr
```cpp
int* ptr = findElement(arr, size, target);
cout << *ptr;  // DANGER if nullptr!
```

**Fix:**
```cpp
int* ptr = findElement(arr, size, target);
if (ptr != nullptr) {
    cout << *ptr;
}
```

---

## Dry Run Examples

### Example 1: Swap
```cpp
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 7, y = 3;
    swap(&x, &y);
    cout << x << " " << y;
    return 0;
}
```

**Output:** `3 7`

---

### Example 2: Multiple Outputs
```cpp
void divideMod(int a, int b, int* quotient, int* remainder) {
    *quotient = a / b;
    *remainder = a % b;
}

int main() {
    int q, r;
    divideMod(17, 5, &q, &r);
    cout << q << " " << r;
    return 0;
}
```

**Output:** `3 2`

---

### Example 3: Array Modification
```cpp
void addTen(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) += 10;
    }
}

int main() {
    int arr[] = {5, 10, 15};
    addTen(arr, 3);
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    return 0;
}
```

**Output:** `15 20 25`

---

## MCQs

### Q1. What's the output?
```cpp
void func(int x) { x = 100; }
int main() {
    int a = 50;
    func(a);
    cout << a;
}
```
A) 50  
B) 100  
C) Garbage  
D) Compilation error  

<details>
<summary>Answer</summary>
**A) 50** - Pass by value doesn't modify original
</details>

### Q2. How to modify original value?
A) `void func(int x)`  
B) `void func(int* x)`  
C) `void func(int& x)`  
D) Both B and C  

<details>
<summary>Answer</summary>
**D)** - Both pointers and references allow modification
</details>

---

## Key Takeaways

1. ✅ Pass by value = copy (original unchanged)
2. ✅ Pass by pointer = can modify original
3. ✅ Arrays decay to pointers in functions
4. ✅ Always pass size with arrays
5. ✅ Never return pointer to local variable
6. ✅ Check nullptr before dereferencing
7. ✅ Use `const` for read-only parameters

**Next**: Practice_03_Functions.md → Module 4 (Dynamic Memory!)

---

*🎯 Master this - it's foundation for dynamic memory!*
