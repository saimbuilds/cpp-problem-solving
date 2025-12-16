# Module 5: 2D Dynamic Arrays
## The FAST Exam Boss Level

> **Learning Objective**: Master 2D dynamic arrays - the most tested topic in FAST finals for pointers/dynamic memory.

---

## Table of Contents
1. [Concept: Array of Pointers](#concept-array-of-pointers)
2. [Allocating 2D Arrays](#allocating-2d-arrays)
3. [Deallocating 2D Arrays](#deallocating-2d-arrays)
4. [Jagged Arrays](#jagged-arrays)
5. [Common Patterns](#common-patterns)
6. [Critical Mistakes](#critical-mistakes)

---

## Concept: Array of Pointers

A 2D dynamic array is essentially an **array of pointers**, where each pointer points to a 1D array (row).

### Memory Structure

```
arr → [ ptr ] [ ptr ] [ ptr ]     (Array of pointers - rows)
        ↓       ↓       ↓
      [1][2]  [3][4]  [5][6]      (Each points to a 1D array)
```

### Declaration
```cpp
int** arr;  // Pointer to pointer (2D array)
```

Think of it as:
- `int**` = pointer to an array of pointers
- Each `int*` in that array points to a row

---

## Allocating 2D Arrays

### Method: Row-by-Row Allocation

```cpp
int rows = 3;
int cols = 4;

// Step 1: Allocate array of row pointers
int** arr = new int*[rows];

// Step 2: Allocate each row
for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
}

// Now arr[i][j] works like normal 2D array!
```

### Complete Example with Input/Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    
    // Allocate
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    // Input
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Output
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // CRITICAL: Deallocate (see next section)
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  // Delete each row
    }
    delete[] arr;  // Delete array of pointers
    
    return 0;
}
```

---

## Deallocating 2D Arrays

### ⚠️ CRITICAL: Order Matters!

**✅ Correct Order:**
```cpp
// 1. Delete each row first
for (int i = 0; i < rows; i++) {
    delete[] arr[i];
}

// 2. Then delete array of pointers
delete[] arr;
```

**❌ WRONG - Memory Leak:**
```cpp
delete[] arr;  // WRONG! Rows not freed!
```

**❌ WRONG - Crash:**
```cpp
delete[] arr;           // Frees array of pointers
for (int i = 0; i < rows; i++) {
    delete[] arr[i];    // CRASH! arr already freed!
}
```

### Mnemonic: LIFO (Last In, First Out)
- First allocated: array of pointers
- Last allocated: individual rows
- First to delete: individual rows
- Last to delete: array of pointers

---

## Jagged Arrays

Arrays where each row can have different length!

### Example: Jagged Array
```cpp
int rows = 3;
int** arr = new int*[rows];

// Row 0: 2 elements
arr[0] = new int[2];

// Row 1: 4 elements  
arr[1] = new int[4];

// Row 2: 3 elements
arr[2] = new int[3];

// Use it:
arr[0][0] = 1; arr[0][1] = 2;
arr[1][0] = 3; arr[1][1] = 4; arr[1][2] = 5; arr[1][3] = 6;
arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;

// Deallocate
for (int i = 0; i < rows; i++) {
    delete[] arr[i];
}
delete[] arr;
```

**Structure:**
```
arr → [ptr0] [ptr1] [ptr2]
        ↓      ↓      ↓
      [1][2] [3][4][5][6] [7][8][9]
```

---

## Common Patterns

### Pattern 1: Read Matrix from User
```cpp
int** createMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    
    return mat;
}
```

### Pattern 2: Transpose Matrix
```cpp
int** transpose(int** mat, int rows, int cols) {
    // Create new matrix (cols x rows)
    int** trans = new int*[cols];
    for (int i = 0; i < cols; i++) {
        trans[i] = new int[rows];
    }
    
    // Fill transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    
    return trans;
}
```

### Pattern 3: Matrix Addition
```cpp
int** addMatrices(int** a, int** b, int rows, int cols) {
    int** result = new int*[rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}
```

### Pattern 4: deallocate Function
```cpp
void deallocate2D(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
```

---

## Critical Mistakes

### ❌ Mistake 1: Single Delete
```cpp
int** arr = new int*[3];
for (int i = 0; i < 3; i++) {
    arr[i] = new int[4];
}

delete[] arr;  // MEMORY LEAK! Rows not freed!
```

### ❌ Mistake 2: Wrong Order
```cpp
delete[] arr;  // Frees pointers array
for (int i = 0; i < rows; i++) {
    delete[] arr[i];  // CRASH! Can't access arr
}
```

### ❌ Mistake 3: Wrong Delete Syntax
```cpp
for (int i = 0; i < rows; i++) {
    delete arr[i];  // WRONG! Should be delete[]
}
delete arr;  // WRONG! Should be delete[]
```

### ❌ Mistake 4: Accessing After Delete
```cpp
for (int i = 0; i < rows; i++) {
    delete[] arr[i];
}
delete[] arr;

arr[0][0] = 10;  // CRASH! Memory freed!
```

---

## Dry Run Examples

### Example 1: Basic 2D Allocation
```cpp
int** arr = new int*[2];
arr[0] = new int[3];
arr[1] = new int[3];

arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;

cout << arr[1][2];

for (int i = 0; i < 2; i++) {
    delete[] arr[i];
}
delete[] arr;
```
**Output:** `6`

---

### Example 2: Jagged Array
```cpp
int** arr = new int*[3];
arr[0] = new int[1]; arr[0][0] = 10;
arr[1] = new int[2]; arr[1][0] = 20; arr[1][1] = 30;
arr[2] = new int[3]; arr[2][0] = 40; arr[2][1] = 50; arr[2][2] = 60;

cout << arr[1][1] << " " << arr[2][2];

for (int i = 0; i < 3; i++) {
    delete[] arr[i];
}
delete[] arr;
```
**Output:** `30 60`

---

### Example 3: Matrix Sum
```cpp
int r = 2, c = 2;
int** mat = new int*[r];
for (int i = 0; i < r; i++) {
    mat[i] = new int[c];
}

mat[0][0] = 1; mat[0][1] = 2;
mat[1][0] = 3; mat[1][1] = 4;

int sum = 0;
for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        sum += mat[i][j];
    }
}
cout << sum;

for (int i = 0; i < r; i++) {
    delete[] mat[i];
}
delete[] mat;
```
**Output:** `10`

Sum: 1+2+3+4 = 10

---

## MCQs

### Q1. How to declare 2D dynamic array?
A) `int arr[][];`  
B) `int* arr[];`  
C) `int** arr;`  
D) `int arr**;`  

<details>
<summary>Answer</summary>
**C)** `int**` = pointer to pointer
</details>

### Q2. Correct deallocation order?
A) Delete rows, then array of pointers  
B) Delete array of pointers, then rows  
C) Order doesn't matter  
D) Single delete[] is enough  

<details>
<summary>Answer</summary>
**A)** Must delete rows first, then array of pointers
</details>

### Q3. What's wrong?
```cpp
int** arr = new int*[3];
for (int i = 0; i < 3; i++) {
    arr[i] = new int[4];
}
delete[] arr;
```
A) Nothing  
B) Memory leak  
C) Syntax error  
D) Wrong delete syntax  

<details>
<summary>Answer</summary>
**B)** Rows not deleted, memory leak!
</details>

---

## Key Takeaways

1. ✅ `int**` for 2D dynamic arrays
2. ✅ Allocate: array of pointers, then each row
3. ✅ Deallocate: each row first, then array of pointers
4. ✅ Can create jagged arrays (different row sizes)
5. ✅ Use `delete[]` for both steps
6. ✅ Order of deallocation is CRITICAL
7. ✅ This is the MOST tested dynamic memory topic!

**Next**: Practice_05_Dynamic2D.md (INTENSE practice!)

---

*🎯 Master this completely - it's 40% of your exam!*
