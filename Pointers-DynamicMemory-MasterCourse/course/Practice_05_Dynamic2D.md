# Practice Set 5: 2D Dynamic Arrays
## 30 Minutes - The Ultimate Challenge

> **Goal**: Become unstoppable at 2D dynamic arrays - FAST's favorite exam topic

---

## Section A: Dry Run Challenges (18 minutes)

### Problem 1: Basic 2D Allocation & Access
```cpp
int** arr = new int*[2];
arr[0] = new int[3];
arr[1] = new int[3];

arr[0][0] = 5; arr[0][1] = 10; arr[0][2] = 15;
arr[1][0] = 20; arr[1][1] = 25; arr[1][2] = 30;

cout << arr[0][2] << " " << arr[1][1];

for (int i = 0; i < 2; i++) {
    delete[] arr[i];
}
delete[] arr;
```
**Output:** `__________`

---

### Problem 2: Matrix Sum
```cpp
int r = 2, c = 3;
int** mat = new int*[r];
for (int i = 0; i < r; i++) {
    mat[i] = new int[c];
}

mat[0][0]=1; mat[0][1]=2; mat[0][2]=3;
mat[1][0]=4; mat[1][1]=5; mat[1][2]=6;

int sum = 0;
for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        sum += mat[i][j];
    }
}
cout << sum;

for (int i = 0; i <r; i++) {
    delete[] mat[i];
}
delete[] mat;
```
**Output:** `__________`

---

### Problem 3: Jagged Array
```cpp
int** arr = new int*[3];
arr[0] = new int[2];
arr[1] = new int[4];
arr[2] = new int[1];

arr[0][0]=1; arr[0][1]=2;
arr[1][0]=3; arr[1][1]=4; arr[1][2]=5; arr[1][3]=6;
arr[2][0]=7;

cout << arr[1][3] << " " << arr[2][0];

for (int i = 0; i < 3; i++) {
    delete[] arr[i];
}
delete[] arr;
```
**Output:** `__________`

---

### Problem 4: Diagonal Sum
```cpp
int n = 3;
int** mat = new int*[n];
for (int i = 0; i < n; i++) {
    mat[i] = new int[n];
}

mat[0][0]=1; mat[0][1]=2; mat[0][2]=3;
mat[1][0]=4; mat[1][1]=5; mat[1][2]=6;
mat[2][0]=7; mat[2][1]=8; mat[2][2]=9;

int diag_sum = 0;
for (int i = 0; i < n; i++) {
    diag_sum += mat[i][i];
}
cout << diag_sum;

for (int i = 0; i < n; i++) {
    delete[] mat[i];
}
delete[] mat;
```
**Output:** `__________`

---

### Problem 5: Matrix Modification
```cpp
int r = 2, c = 3;
int** arr = new int*[r];
for (int i = 0; i < r; i++) {
    arr[i] = new int[c];
    for (int j = 0; j < c; j++) {
        arr[i][j] = (i + 1) * (j + 1);
    }
}

cout << arr[0][0] << " " << arr[1][2];

for (int i = 0; i < r; i++) {
    delete[] arr[i];
}
delete[] arr;
```
**Output:** `__________`

---

### Problem 6: Row Swap
```cpp
int** mat = new int*[2];
mat[0] = new int[3];
mat[1] = new int[3];

mat[0][0]=1; mat[0][1]=2; mat[0][2]=3;
mat[1][0]=4; mat[1][1]=5; mat[1][2]=6;

// Swap rows
int* temp = mat[0];
mat[0] = mat[1];
mat[1] = temp;

cout << mat[0][0] << " " << mat[1][0];

for (int i = 0; i < 2; i++) {
    delete[] mat[i];
}
delete[] mat;
```
**Output:** `__________`

---

### Problem 7: Transpose
```cpp
int r = 2, c = 3;
int** mat = new int*[r];
for (int i = 0; i < r; i++) {
    mat[i] = new int[c];
}

mat[0][0]=1; mat[0][1]=2; mat[0][2]=3;
mat[1][0]=4; mat[1][1]=5; mat[1][2]=6;

// Create transpose (3x2)
int** trans = new int*[c];
for (int i = 0; i < c; i++) {
    trans[i] = new int[r];
}

for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        trans[j][i] = mat[i][j];
    }
}

cout << trans[1][0] << " " << trans[2][1];

// Cleanup
for (int i = 0; i < r; i++) delete[] mat[i];
delete[] mat;
for (int i = 0; i < c; i++) delete[] trans[i];
delete[] trans;
```
**Output:** `__________`

---

### Problem 8: Memory Leak Detection
```cpp
void func() {
    int** data = new int*[3];
    for (int i = 0; i < 3; i++) {
        data[i] = new int[4];
    }
    // Forgot to delete!
}

int main() {
    for (int i = 0; i < 2; i++) {
        func();
    }
    return 0;
}
```
**How many integers leaked?** `__________`

---

### Problem 9: Partial Deallocation (Bug!)
```cpp
int** arr = new int*[3];
for (int i = 0; i < 3; i++) {
    arr[i] = new int[4];
}

// Wrong deallocation
delete[] arr;

// What happened? Memory leak? Crash? Both?
```
**Answer:** `__________`

---

### Problem 10: FAST-Style Complex
```cpp
int** process(int r, int c) {
    int** data = new int*[r];
    for (int i = 0; i < r; i++) {
        data[i] = new int[c];
        for (int j = 0; j < c; j++) {
            data[i][j] = i * c + j;
        }
    }
    return data;
}

int main() {
    int** mat = process(3, 4);
    
    cout << mat[0][3] << " ";
    cout << mat[1][2] << " ";
    cout << mat[2][1];
    
    for (int i = 0; i < 3; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}
```
**Output:** `__________`

---

## Section B: MCQs (8 minutes)

### Q1. Correct declaration for 2D dynamic array?
A) `int* arr[];`  
B) `int arr[][];`  
C) `int** arr;`  
D) `int arr[10][10];`  

---

### Q2. Allocate 3x4 matrix correctly:
A) `int** m = new int[3][4];`  
B) `int** m = new int*[3]; for(i) m[i] = new int[4];`  
C) `int** m = new int[12];`  
D) `int** m[3][4];`  

---

### Q3. Correct deallocation order?
```cpp
int** arr = new int*[5];
for (int i = 0; i < 5; i++)
    arr[i] = new int[10];
```
A) `delete[] arr;` only  
B) `for(i) delete[] arr[i];` only  
C) `delete[] arr; then for(i) delete[] arr[i];`  
D) `for(i) delete[] arr[i]; then delete[] arr;`  

---

### Q4. What causes memory leak?
```cpp
int** mat = new int*[4];
for (int i = 0; i < 4; i++)
    mat[i] = new int[5];
delete[] mat;
```
A) Nothing leaked  
B) 4 pointers leaked  
C) 20 integers leaked  
D) Both B and C  

---

### Q5. Output?
```cpp
int** arr = new int*[2];
arr[0] = new int[2]{1, 2};
arr[1] = new int[2]{3, 4};
cout << arr[1][0];
```
A) 1  
B) 2  
C) 3  
D) 4  

---

### Q6. Jagged array legal?
A) No, all rows must be same size  
B) Yes, each row can differ  
C) Only in C, not C++  
D) Syntax error  

---

### Q7. What's wrong?
```cpp
int** arr = new int*[3];
for (int i = 0; i < 3; i++)
    arr[i] = new int[4];
for (int i = 0; i < 3; i++)
    delete arr[i];
delete arr;
```
A) Nothing  
B) Should use delete[]  
C) Wrong order  
D) Memory leak  

---

### Q8. FAST-Style: Output?
```cpp
int** arr = new int*[2];
arr[0] = new int[2]; arr[0][0] = 5; arr[0][1] = 10;
arr[1] = arr[0];
arr[1][0] = 20;
cout << arr[0][0] << " " << arr[1][0];
```
A) 5 20  
B) 20 20  
C) 5 5  
D) 20 5  

---

## Section C: Code Writing (4 minutes)

### Task 1: Matrix Multiplication
```cpp
// Multiply two matrices (r1 x c1) * (r2 x c2)
// Assume c1 == r2
int** multiplyMatrices(int** a, int r1, int c1, 
                       int** b, int r2, int c2) {
    // Your code
    // Result should be r1 x c2
}

// Test case: A(2x3) * B(3x2) = C(2x2)
```

---

### Task 2: Find Max in Each Row
```cpp
// Return 1D array containing max of each row
int* findRowMaximums(int** mat, int rows, int cols) {
    // Your code
}

// Test:
// mat = [[1,5,3], [9,2,7], [4,8,6]]
// Should return [5, 9, 8]
```

---

### Task 3: Deep Copy 2D Array
```cpp
// Create independent copy of 2D array
int** deepCopy(int** source, int rows, int cols) {
    // Your code
}

// Modifying copy should NOT affect original
```

---

## Solutions

### Section A Solutions

<details>
<summary>Problem 1</summary>

**Output:** `15 25`

arr[0][2] = 15, arr[1][1] = 25
</details>

<details>
<summary>Problem 2</summary>

**Output:** `21`

Sum: 1+2+3+4+5+6 = 21
</details>

<details>
<summary>Problem 3</summary>

**Output:** `6 7`

arr[1][3] = 6 (4th element of 2nd row)  
arr[2][0] = 7
</details>

<details>
<summary>Problem 4</summary>

**Output:** `15`

Diagonal: mat[0][0] + mat[1][1] + mat[2][2] = 1 + 5 + 9 = 15
</details>

<details>
<summary>Problem 5</summary>

**Output:** `1 6`

arr[i][j] = (i+1)*(j+1)  
arr[0][0] = 1*1 = 1  
arr[1][2] = 2*3 = 6
</details>

<details>
<summary>Problem 6</summary>

**Output:** `4 1`

After swap: mat[0] points to old row 1, mat[1] points to old row 0  
mat[0][0] = 4, mat[1][0] = 1
</details>

<details>
<summary>Problem 7</summary>

**Output:** `2 6`

trans[1][0] = mat[0][1] = 2  
trans[2][1] = mat[1][2] = 6
</details>

<details>
<summary>Problem 8</summary>

**Answer:** `24 integers`

Each call leaks 3 rows × 4 cols = 12 integers  
Called 2 times = 24 integers leaked
</details>

<details>
<summary>Problem 9</summary>

**Answer:** Memory leak (rows not freed) + possible later issues

Deleting array of pointers first leaks all row memory. Total leak: 3 × 4 = 12 integers
</details>

<details>
<summary>Problem 10</summary>

**Output:** `3 6 9`

mat[0][3] = 0*4 + 3 = 3  
mat[1][2] = 1*4 + 2 = 6  
mat[2][1] = 2*4 + 1 = 9
</details>

---

### Section B MCQ Answers

1. **C)** `int**` is correct for 2D dynamic arrays
2. **B)** Must allocate array of pointers, then each row
3. **D)** Delete rows first, then array of pointers
4. **C)** 20 integers leaked (4 rows × 5 cols)
5. **C) 3** - arr[1][0] is 3
6. **B)** Yes, jagged arrays are legal
7. **B)** Should use delete[] for arrays
8. **B) 20 20** - arr[1] and arr[0] point to same array!

---

### Section C Solutions

<details>
<summary>Task 1: Matrix Multiplication</summary>

```cpp
int** multiplyMatrices(int** a, int r1, int c1,
                       int** b, int r2, int c2) {
    int** result = new int*[r1];
    for (int i = 0; i < r1; i++) {
        result[i] = new int[c2];
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}
```
</details>

<details>
<summary>Task 2: Row Maximums</summary>

```cpp
int* findRowMaximums(int** mat, int rows, int cols) {
    int* maxes = new int[rows];
    for (int i = 0; i < rows; i++) {
        maxes[i] = mat[i][0];  // Initialize with first element
        for (int j = 1; j < cols; j++) {
            if (mat[i][j] > maxes[i]) {
                maxes[i] = mat[i][j];
            }
        }
    }
    return maxes;
}
```
</details>

<details>
<summary>Task 3: Deep Copy</summary>

```cpp
int** deepCopy(int** source, int rows, int cols) {
    int** copy = new int*[rows];
    for (int i = 0; i < rows; i++) {
        copy[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            copy[i][j] = source[i][j];
        }
    }
    return copy;
}
```
</details>

---

## Performance Check

- [ ] All dry runs: 10/10
- [ ] Understand jagged arrays
- [ ] Can write allocation/deallocation blind
- [ ] MCQs: 7/8 or better
- [ ] All coding tasks complete
- [ ] Time: _______ minutes

**CRITICAL MASTERY:**
- ✅ Allocate: array of pointers → each row
- ✅ Deallocate: each row → array of pointers
- ✅ Both use delete[]
- ✅ Order is EVERYTHING

**This is the exam killer topic - own it!**

---1

*🔥 2D Arrays conquered! Let's finish the advanced topics!*
so this is how you can change the value in the code and this is how you change the code in the process and this is how ithana be hten most powrfulamn22222222
and this is how you can change the code in the porcess life is changed abh