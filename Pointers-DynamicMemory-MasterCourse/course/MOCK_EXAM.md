# MOCK EXAM: Pointers & Dynamic Memory
## FAST-Style Final Exam Simulation (50 Minutes)

> **Instructions:**
> - Total Marks: 50
> - Time: 50 minutes
> - No notes, no calculators
> - Show all work for partial credit
> - This is HARDER than actual exam by design!

---

## Section A: Multiple Choice (15 marks, 1 mark each)

### Q1. What is the output?
```cpp
int x = 10;
int* p = &x;
*p += 5;
cout << x;
```
A) 10  
B) 15  
C) Garbage  
D) Compilation error  

---

### Q2. Which is correct for 2D dynamic array?
A) `int** arr = new int[5][10];`  
B) `int** arr = new int*[5]; for(i) arr[i] = new int[10];`  
C) `int arr[][] = new int[5][10];`  
D) `int* arr[5][10] = new int;`  

---

### Q3. Memory leak?
```cpp
int* p = new int[100];
p = new int[200];
delete[] p;
```
A) No leak  
B) 100 integers leaked  
C) 200 integers leaked  
D) 300 integers leaked  

---

### Q4. Output?
```cpp
int arr[] = {2, 4, 6, 8};
int* p = arr + 1;
cout << *(p + 1);
```
A) 2  
B) 4  
C) 6  
D) 8  

---

### Q5. Correct deallocation?
```cpp
int** mat = new int*[3];
for (int i = 0; i < 3; i++)
    mat[i] = new int[4];
```
A) `delete[] mat;`  
B) `for(i) delete mat[i]; delete mat;`  
C) `for(i) delete[] mat[i]; delete[] mat;`  
D) `delete[][] mat;`  

---

### Q6. What's **pptr?
```cpp
int x = 7;
int* p = &x;
int** pptr = &p;
```
A) Address of x  
B) Address of p  
C) Value of x  
D) Syntax error  

---

### Q7. Output?
```cpp
int x = 5, y = 10;
int* p = &x;
p = &y;
*p = 20;
cout << x << " " << y;
```
A) 5 10  
B) 20 10  
C) 5 20  
D) 20 20  

---

### Q8. Which is TRUE?
A) Array names can be incremented  
B) Pointers always require delete  
C) `arr[i]` equals `*(arr + i)`  
D) Stack memory requires delete  

---

### Q9. Output?
```cpp
int arr[] = {10, 20, 30};
int* p = arr;
cout << (*p)++ << " " << *p;
```
A) 10 10  
B) 10 11  
C) 11 11  
D) 10 20  

---

### Q10. What's the issue?
```cpp
int* getArray() {
    int arr[5] = {1,2,3,4,5};
    return arr;
}
```
A) Nothing wrong  
B) Returning local array address  
C) Syntax error  
D) Memory leak  

---

### Q11. Size of pointer on 64-bit?
A) 4 bytes  
B) 8 bytes  
C) Depends on type  
D) 16 bytes  

---

### Q12. Output?
```cpp
int** arr = new int*[2];
arr[0] = new int[2]{1, 2};
arr[1] = arr[0];
arr[1][0] = 5;
cout << arr[0][0];
```
A) 1  
B) 2  
C) 5  
D) Undefined  

---

### Q13. Which allocates on heap?
A) `int arr[100];`  
B) `int* arr = new int[100];`  
C) `int arr[] = {1,2,3};`  
D) `int x = 10;`  

---

### Q14. Output?
```cpp
int x = 3;
int* p = &x;
cout << p - p;
```
A) 0  
B) Address value  
C) Compilation error  
D) Undefined  

---

### Q15. What's wrong?
```cpp
int* p = new int(10);
delete p;
cout << *p;
```
A) Nothing  
B) Memory leak  
C) Dangling pointer dereference  
D) Wrong delete syntax  

---

## Section B: Dry Run Problems (15 marks, 3 marks each)

### Problem 1
```cpp
int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int* ptr = arr + 2;
    
    *ptr += 10;
    ptr--;
    *ptr = *ptr * 2;
    ptr += 3;
    
    cout << arr[1] << " " << arr[2] << " " << *ptr;
    return 0;
}
```
**Output:** `__________`

---

### Problem 2
```cpp
int main() {
    int** mat = new int*[3];
    for (int i = 0; i < 3; i++) {
        mat[i] = new int[2];
        mat[i][0] = i * 2;
        mat[i][1] = i * 2 + 1;
    }
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += mat[i][1];
    }
    
    cout << sum;
    
    for (int i = 0; i < 3; i++) delete[] mat[i];
    delete[] mat;
    return 0;
}
```
**Output:** `__________`

---

### Problem 3
```cpp
void modify(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 12, y = 8;
    modify(&x, &y);
    cout << x << " " << y;
    return 0;
}
```
**Output:** `__________`

---

### Problem 4
```cpp
int main() {
    int x = 5;
    int* p1 = &x;
    int** p2 = &p1;
    
    **p2 = 10;
    *p1 += 5;
    
    cout << x << " " << *p1 << " " << **p2;
    return 0;
}
```
**Output:** `__________`

---

### Problem 5
```cpp
int main() {
    int* arr1 = new int[3]{2, 4, 6};
    int* arr2 = new int[3];
    
    for (int i = 0; i < 3; i++) {
        arr2[i] = arr1[i] * 2;
    }
    
    arr1[1] = 10;
    
    cout << arr1[1] << " " << arr2[1];
    
    delete[] arr1;
    delete[] arr2;
    return 0;
}
```
**Output:** `__________`

---

## Section C: Code Writing (20 marks, 10 marks each)

### Problem 1: Reverse 1D Array (10 marks)
Write a function that reverses an array in-place using ONLY pointers (no array indexing notation).

```cpp
void reverseArray(int* arr, int size) {
    // Your code here
    // Must use only pointer notation (*ptr, ptr++, etc)
    // No arr[i] allowed!
}

// Test
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    // Should print: 5 4 3 2 1
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```

**Requirements:**
- Use only pointer arithmetic
- In-place reversal
- Two-pointer approach

---

### Problem 2: Create & Transpose Matrix (10 marks)
Write TWO functions:
1. Create a matrix and fill with sequential values
2. Return transpose of the matrix

```cpp
// Function 1: Create matrix
int** createMatrix(int rows, int cols) {
    // Allocate and fill with:
    // mat[i][j] = i * cols + j + 1
    // Example 2x3: [[1,2,3], [4,5,6]]
}

// Function 2: Transpose
int** transpose(int** mat, int rows, int cols) {
    // Create new transposed matrix (cols x rows)
    // Don't modify original
}

// Function 3: Deallocate
void deallocate(int** mat, int rows) {
    // Properly free 2D array
}

// Test
int main() {
    int** mat = createMatrix(2, 3);
    int** trans = transpose(mat, 2, 3);
    
    // Print transpose
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    
    deallocate(mat, 2);
    deallocate(trans, 3);
    return 0;
}
```

**Requirements:**
- Proper allocation
- Correct transpose logic
- Proper deallocation
- No memory leaks

---

## SOLUTIONS

### Section A Answers
1. B  
2. B  
3. B  
4. C  
5. C  
6. C  
7. C  
8. C  
9. B  
10. B  
11. B  
12. C  
13. B  
14. A  
15. C  

### Section B Answers
1. `20 25 25`
2. `9` (sum of 1, 3, 5)
3. `8 12` (swapped)
4. `15 15 15`
5. `10 8`

### Section C Solutions

**Problem 1:**
```cpp
void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
```

**Problem 2:**
```cpp
int** createMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            mat[i][j] = i * cols + j + 1;
        }
    }
    return mat;
}

int** transpose(int** mat, int rows, int cols) {
    int** trans = new int*[cols];
    for (int i = 0; i < cols; i++) {
        trans[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            trans[i][j] = mat[j][i];
        }
    }
    return trans;
}

void deallocate(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}
```

---

## Scoring Guide

**Section A (15 marks):**
- 13-15: Excellent
- 10-12: Good  
- 7-9: Pass
- <7: Review basics

**Section B (15 marks):**
- 13-15: Excellent
- 10-12: Good
- 7-9: Pass
- <7: More practice needed

**Section C (20 marks):**
- 18-20: Perfect
- 14-17: Very good
- 10-13: Good effort
- <10: Review concepts

**Total /50:**
- 45-50: You'll ace the exam! 🔥
- 35-44: Very good, minor review
- 25-34: Good foundation, practice more
- <25: Need more preparation

---

*🎯 This is harder than the real exam - if you score well here, you're ready!*
