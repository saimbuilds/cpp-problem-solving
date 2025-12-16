# Module 6: Advanced Pointers & Edge Cases
## The Final Boss - Complex Patterns

> **Learning Objective**: Master advanced pointer concepts including pointer to pointer, complex expressions, and tricky edge cases that appear in FAST exams.

---

## Table of Contents
1. [Pointer to Pointer Deep Dive](#pointer-to-pointer-deep-dive)
2. [Complex Pointer Expressions](#complex-pointer-expressions)
3. [Arrays of Pointers vs Pointer to Array](#arrays-of-pointers-vs-pointer-to-array)
4. [Function Pointers (Brief)](#function-pointers-brief)
5. [Common Edge Cases](#common-edge-cases)
6. [FAST Exam Tricks](#fast-exam-tricks)

---

## Pointer to Pointer Deep Dive

### What is Pointer to Pointer?

A variable that stores the address of another pointer.

```cpp
int x = 10;
int* ptr = &x;      // ptr points to x
int** pptr = &ptr;  // pptr points to ptr

cout << x;          // 10 (value)
cout << *ptr;       // 10 (value through ptr)
cout << **pptr;     // 10 (value through pptr)
cout << *pptr;      // Address stored in ptr (address of x)
cout << pptr;       // Address of ptr itself
```

### Memory Diagram
```
Variable: x
Value: 10
Address: 0x1000

Variable: ptr
Value: 0x1000 (address of x)
Address: 0x2000

Variable: pptr
Value: 0x2000 (address of ptr)
Address: 0x3000
```

### Modifying Through Pointer to Pointer
```cpp
int x = 5;
int* ptr = &x;
int** pptr = &ptr;

**pptr = 20;  // Changes x to 20!

cout << x;     // 20
cout << *ptr;  // 20
cout << **pptr; // 20
```

### Use Case: 2D Arrays ARE Pointer to Pointer!
```cpp
int** arr = new int*[3];  // arr is pointer to pointer!

// arr → array of pointers
// arr[i] → pointer to row i
// arr[i][j] → element at row i, col j
```

---

## Complex Pointer Expressions

### `*ptr++` vs `(*ptr)++` vs `*++ptr` vs `++*ptr`

| Expression | Meaning |
|------------|---------|
| `*ptr++` | Dereference, then increment pointer (post) |
| `(*ptr)++` | Increment value at pointer (post) |
| `*++ptr` | Increment pointer, then dereference |
| `++*ptr` | Pre-increment value at pointer |

### Examples

#### Example 1: `*ptr++`
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << *ptr++;  // Output: 10
cout << *ptr;    // Output: 20
```
**Explanation:** Use current value, then move pointer forward.

#### Example 2: `(*ptr)++`
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << (*ptr)++;  // Output: 10
cout << arr[0];    // Output: 11
cout << *ptr;      // Output: 11
```
**Explanation:** Use value at pointer, then increment that value.

#### Example 3: `*++ptr`
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << *++ptr;  // Output: 20
cout << *ptr;    // Output: 20
```
**Explanation:** Move pointer forward first, then use value.

#### Example 4: `++*ptr`
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << ++*ptr;  // Output: 11
cout << arr[0];  // Output: 11
```
**Explanation:** Increment value at pointer first, then use it.

---

## Arrays of Pointers vs Pointer to Array

### Array of Pointers: `int* arr[n]`
```cpp
int* arr[3];  // Array of 3 pointers

int a = 10, b = 20, c = 30;
arr[0] = &a;
arr[1] = &b;
arr[2] = &c;

cout << *arr[0];  // 10
cout << *arr[1];  // 20
```

**Use case:** Jagged arrays, string arrays

```cpp
char* names[3];
names[0] = "Alice";
names[1] = "Bob";
names[2] = "Charlie";

cout << names[0];  // Alice
```

### Pointer to Array: `int (*ptr)[n]`
```cpp
int arr[3] = {1, 2, 3};
int (*ptr)[3] = &arr;  // Pointer to entire array

cout << (*ptr)[0];  // 1
cout << (*ptr)[1];  // 2
```

**Difference:**
- `int* arr[3]` = array of 3 pointers
- `int (*arr)[3]` = pointer to array of 3 ints

---

## Function Pointers (Brief)

### Concept
Function names are also addresses! You can store them in pointers.

```cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int (*funcPtr)(int, int) = add;  // Point to function
    
    int result = funcPtr(5, 3);  // Call through pointer
    cout << result;  // Output: 8
    
    return 0;
}
```

**Note:** Function pointers rarely appear in FAST PF exams, but know the concept.

---

## Common Edge Cases

### Edge Case 1: Null Pointer Dereference
```cpp
int* ptr = nullptr;
cout << *ptr;  // CRASH!
```

**Always check:**
```cpp
if (ptr != nullptr) {
    cout << *ptr;
}
```

### Edge Case 2: Dangling Pointer
```cpp
int* ptr = new int(10);
delete ptr;
*ptr = 20;  // UNDEFINED! Accessing freed memory
```

**Fix:**
```cpp
delete ptr;
ptr = nullptr;  // Clear the pointer
```

### Edge Case 3: Memory Leak from Reassignment
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

### Edge Case 4: Shallow vs Deep Copy
```cpp
int* arr1 = new int[3]{1, 2, 3};
int* arr2 = arr1;  // SHALLOW COPY! Both point to same memory

arr2[0] = 100;
cout << arr1[0];  // 100 (both changed!)
```

**Deep copy:**
```cpp
int* arr1 = new int[3]{1, 2, 3};
int* arr2 = new int[3];
for (int i = 0; i < 3; i++) {
    arr2[i] = arr1[i];  // Independent copy
}
```

### Edge Case 5: Out of Bounds
```cpp
int* arr = new int[5];
arr[10] = 100;  // UNDEFINED! Out of bounds
```

**No built-in bounds checking in C++!** You must track size yourself.

---

## FAST Exam Tricks

### Trick 1: Pointer Arithmetic with Different Types
```cpp
int arr[5];
int* ptr = arr;

cout << (ptr + 2) - ptr;  // Output: 2 (elements, not bytes!)
```

### Trick 2: Multiple Indirection
```cpp
int x = 5;
int* p1 = &x;
int** p2 = &p1;
int*** p3 = &p2;

***p3 = 10;  // Changes x to 10!
```

### Trick 3: Array Name vs Pointer
```cpp
int arr[5];
int* ptr = arr;

ptr++;  // OK
arr++;  // ERROR! Array name is constant
```

### Trick 4: Pointer Comparison
```cpp
int arr[5];
int* p1 = &arr[1];
int* p2 = &arr[3];

if (p1 < p2) {
    cout << "p1 is before p2";  // TRUE
}

cout << (p2 - p1);  // 2 (element distance)
```

### Trick 5: Expression Precedence
```cpp
int arr[] = {1, 2, 3};
int* ptr = arr;

cout << *ptr + 1;   // 2 (dereference, then add)
cout << *(ptr + 1); // 2 (move pointer, then dereference)
```

---

## Practice Problems

### Problem 1: Pointer to Pointer
```cpp
int x = 7;
int* p = &x;
int** pp = &p;

**pp = **pp * 2;
cout << x;
```
**Output:** `__________`

<details>
<summary>Answer</summary>

**Output:** `14`

**pp accesses x, multiplies by 2 → x = 14
</details>

### Problem 2: Complex Expression
```cpp
int arr[] = {5, 10, 15, 20};
int* ptr = arr;

cout << *ptr++ + *ptr;
```
**Output:** `__________`

<details>
<summary>Answer</summary>

**Output:** `15`

*ptr++ uses 5, then moves to 10. Then *ptr is 10. Total: 5 + 10 = 15
</details>

### Problem 3: Shallow Copy Issue
```cpp
int* arr1 = new int[2]{3, 7};
int* arr2 = arr1;
arr2[0] = 10;
cout << arr1[0];
delete[] arr1;
```
**Output:** `__________`

<details>
<summary>Answer</summary>

**Output:** `10`

Shallow copy - both point to same memory. Modifying arr2 affects arr1.
</details>

---

## MCQs

### Q1. What does `int**` represent?
A) Array of integers  
B) Pointer to integer  
C) Pointer to pointer to integer  
D) Invalid syntax  

<details>
<summary>Answer</summary>
**C)** Pointer to pointer to integer
</details>

### Q2. Output?
```cpp
int x = 5;
int* p = &x;
int** pp = &p;
*p = 10;
cout << **pp;
```
A) 5  
B) 10  
C) Garbage  
D) Compilation error  

<details>
<summary>Answer</summary>
**B) 10** - **pp accesses x through double indirection
</details>

---

## Key Takeaways

1. ✅ `int**` is pointer to pointer (used in 2D arrays)
2. ✅ `*ptr++` ≠ `(*ptr)++` ≠ `*++ptr`
3. ✅ Always check for nullptr before dereferencing
4. ✅ Deep copy needed for independent arrays
5. ✅ Watch out for memory leaks from reassignment
6. ✅ Array names are constant pointers
7. ✅ Understand operator precedence with pointers

**Next**: Practice_06_Advanced.md → Final Mixed Practice

---

*🎯 Advanced patterns conquered! Now let's integrate everything!*
