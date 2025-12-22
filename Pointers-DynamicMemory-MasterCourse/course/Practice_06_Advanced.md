# Practice Set 6: Advanced Mixed Problems
## 40 Minutes - Integration Challenge

> **Goal**: Combine all concepts - this is what FAST exams look like!

---

## Section A: Hardcore Dry Runs (25 minutes)

### Problem 1: Pointer to Pointer
```cpp
int x = 12;
int* p = &x;
int** pp = &p;

**pp += 3;
*p = *p * 2;
cout << x;
```
**Output:** `__________`

---

### Problem 2: Complex Expression Chain
```cpp
int arr[] = {2, 4, 6, 8, 10};
int* ptr = arr + 1;

cout << *ptr++ << " ";
cout << (*ptr)++ << " ";
cout << *++ptr << " ";
cout << ++*ptr;
```
**Output:** `__________`

---

### Problem 3: 2D + Pointer to Pointer
```cpp
int** mat = new int*[2];
mat[0] = new int[3]{1, 2, 3};
mat[1] = new int[3]{4, 5, 6};

int*** ppp = &mat;
cout << ***ppp << " ";
cout << (*ppp)[1][2];

for (int i = 0; i < 2; i++) delete[] mat[i];
delete[] mat;
```
**Output:** `__________`

---

### Problem 4: Shallow vs Deep Copy
```cpp
int* arr1 = new int[3]{10, 20, 30};
int* arr2 = arr1;  // Shallow copy

arr2[1] = 50;
arr1[2] = 60;

cout << arr1[1] << " " << arr2[2];

delete[] arr1;
// Note: Deleting arr2 would crash (double delete)
```
**Output:** `__________`

---

### Problem 5: Memory Leak Calculation
```cpp
void leak1() {
    int* p = new int[10];
}

void leak2() {
    int** mat = new int*[5];
    for (int i = 0; i < 5; i++)
        mat[i] = new int[4];
    delete[] mat;  // Wrong!
}

int main() {
    leak1();
    leak1();
    leak2();
    return 0;
}
```
**How many total integers leaked?** `__________`

---

### Problem 6: Function with 2D Array
```cpp
int** func(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) {
        m[i] = new int[c];
        for (int j = 0; j < c; j++) {
            m[i][j] = i + j;
        }
    }
    return m;
}

int main() {
    int** mat = func(3, 3);
    cout << mat[0][2] << " " << mat[1][1] << " " << mat[2][0];
    
    for (int i = 0; i < 3; i++) delete[] mat[i];
    delete[] mat;
    return 0;
}
```
**Output:** `__________`

---

### Problem 7: Tricky Pointer Arithmetic
```cpp
int arr[] = {3, 6, 9, 12, 15};
int* p1 = arr + 1;
int* p2 = arr + 4;

cout << (p2 - p1) << " ";
cout << *(p1 + 2) << " ";

int** pp = &p1;
cout << **pp;
```
**Output:** `__________`

---

### Problem 8: Matrix FAST-Style
```cpp
int r = 2, c = 3;
int** arr = new int*[r];
for (int i = 0; i < r; i++) {
    arr[i] = new int[c];
}

arr[0][0]=5; arr[0][1]=10; arr[0][2]=15;
arr[1][0]=20; arr[1][1]=25; arr[1][2]=30;

// Swap rows
int* temp = arr[0];
arr[0] = arr[1];
arr[1] = temp;

// Modify
arr[0][0] += 5;
arr[1][2] -= 5;

cout << arr[0][0] << " " << arr[1][2];

for (int i = 0; i < r; i++) delete[] arr[i];
delete[] arr;
```
**Output:** `__________`

---

### Problem 9: All Concepts Combined
```cpp
int** process(int n) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = (i == j) ? 1 : 0;
        }
    }
    return arr;
}

int main() {
    int** mat = process(3);
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += mat[i][i];
    }
    cout << sum << " ";
    
    mat[1][1] = 10;
    cout << mat[1][1];
    
    for (int i = 0; i < 3; i++) delete[] mat[i];
    delete[] mat;
    return 0;
}
```
**Output:** `__________`

---

### Problem 10: The Ultimate Challenge
```cpp
int* func(int* a, int sa, int* b, int sb) {
    int* result = new int[sa + sb];
    int i = 0, j = 0, k = 0;
    
    while (i < sa && j < sb) {
        if (a[i] < b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
    
    while (i < sa) result[k++] = a[i++];
    while (j < sb) result[k++] = b[j++];
    
    return result;
}

int main() {
    int* arr1 = new int[3]{1, 5, 9};
    int* arr2 = new int[4]{2, 4, 6, 8};
    
    int* result = func(arr1, 3, arr2, 4);
    
    cout << result[0] << " " << result[3] << " " << result[6];
    
    delete[] arr1;
    delete[] arr2;
    delete[] result;
    return 0;
}
```
**Output:** `__________`

---

## Section B: Hardcore MCQs (10 minutes)

### Q1. What's the output?
```cpp
int x = 5;
int* p = &x;
int** pp = &p;
**pp = 10;
*p += 5;
cout << x;
```
A) 5  
B) 10  
C) 15  
D) 20  

---

### Q2. Memory leak?
```cpp
int** arr = new int*[3];
for (int i = 0; i < 3; i++)
    arr[i] = new int[5];
delete[] arr[0];
delete[] arr;
```
A) No leak  
B) 10 integers leaked  
C) 15 integers leaked  
D) 5 integers leaked

---

### Q3. What's different?
```cpp
int* arr[3];  // A
int (*arr)[3]; // B
```
A) Same thing  
B) A is array of pointers, B is pointer to array  
C) A is pointer to array, B is array of pointers  
D) Both invalid  

---

### Q4. Output?
```cpp
int arr[] = {10, 20, 30};
int* p = arr;
cout << *p++ + *p;
```
A) 20  
B) 30  
C) 40  
D) Undefined  

---

### Q5. What happens?
```cpp
int* p1 = new int[10];
int* p2 = p1;
delete[] p1;
delete[] p2;
```
A) Safe  
B) Memory leak  
C) Double delete  
D) Compilation error  

---

### Q6. Correct?
```cpp
int** mat = new int*[3];
for (int i = 0; i < 3; i++)
    mat[i] = new int[4];
    
// Cleanup:
for (int i = 0; i < 3; i++)
    delete mat[i];
delete mat;
```
A) Correct  
B) Should use delete[]  
C) Wrong order  
D) Memory leak  

---

### Q7. Output?
```cpp
int x = 7;
int* p = &x;
cout << (*p)++ << " " << *p;
```
A) 7 7  
B) 7 8  
C) 8 8  
D) 8 7  

---

### Q8. What's wrong?
```cpp
int* arr = new int[100];
arr = new int[200];
delete[] arr;
```
A) Nothing  
B) First allocation leaked  
C) Syntax error  
D) Wrong delete  

---

## Section C: Coding Challenges (5 minutes)

### Task 1: Merge Sorted Arrays
```cpp
// Merge two sorted arrays into one sorted array
int* mergeSorted(int* a, int sizeA, int* b, int sizeB) {
    // Your code
}
```

---

### Task 2: Matrix Diagonal Sum
```cpp
// Return sum of both diagonals (avoid counting center twice for odd n)
int diagonalSum(int** mat, int n) {
    // Your code
}
```

---

### Task 3: Deep Copy 2D Array
```cpp
// Create completely independent copy
int** deepCopy2D(int** source, int rows, int cols) {
    // Your code
}
```

---

## Solutions

### Section A Solutions

<details>
<summary>Problem 1</summary>

**Output:** `30`

Trace:
- **pp += 3 → x = 12 + 3 = 15
- *p = 15 * 2 = 30 → x = 30
</details>

<details>
<summary>Problem 2</summary>

**Output:** `4 6 8 9`

Trace:
- *ptr++ → use 4, ptr moves to 6
- (*ptr)++ → use 6, value becomes 7
- *++ptr → ptr moves to 8, use 8
- ++*ptr → 8 becomes 9, use 9
</details>

<details>
<summary>Problem 3</summary>

**Output:** `1 6`

***ppp = mat[0][0] = 1  
(*ppp)[1][2] = mat[1][2] = 6
</details>

<details>
<summary>Problem 4</summary>

**Output:** `50 60`

Shallow copy - both point to same array. Changes affect both.
</details>

<details>
<summary>Problem 5</summary>

**Answer:** `40 integers`

- leak1() called twice: 2 × 10 = 20 integers
- leak2(): 5 rows × 4 cols = 20 integers (rows not freed)
- Total: 40 integers
</details>

<details>
<summary>Problem 6</summary>

**Output:** `2 2 2`

m[i][j] = i + j  
m[0][2] = 0+2 = 2  
m[1][1] = 1+1 = 2  
m[2][0] = 2+0 = 2
</details>

<details>
<summary>Problem 7</summary>

**Output:** `3 12 6`

- p2 - p1 = index difference = 4 - 1 = 3
- *(p1 + 2) = arr[3] = 12
- **pp = *p1 = arr[1] = 6
</details>

<details>
<summary>Problem 8</summary>

**Output:** `25 10`

After swap: arr[0] points to old row 1, arr[1] points to old row 0  
arr[0][0] = 20 + 5 = 25  
arr[1][2] = 15 - 5 = 10
</details>

<details>
<summary>Problem 9</summary>

**Output:** `3 10`

Identity matrix has 1s on diagonal. Sum = 3.  
Then mat[1][1] changed to 10.
</details>

<details>
<summary>Problem 10</summary>

**Output:** `1 4 8`

Merged sorted: {1, 2, 4, 5, 6, 8, 9}  
merged[0]=1, merged[3]=5... wait let me recount:  
{1, 2, 4, 5, 6, 8, 9}  
merged[0]=1 ✓  
merged[3]=5  
merged[6]=9

Actually output: `1 5 9`
</details>

---

### Section B MCQ Answers

1. **C) 15** - x set to 10, then 5 added = 15
2. **B) 10 integers** - arr[1] and arr[2] not freed (2 rows × 5 = 10)
3. **B)** - A is array of 3 int pointers, B is pointer to array of 3 ints
4. **B) 30** - *p++ uses 10, moves to 20, then *p is 20. Total: 10+20=30
5. **C)** - Double delete (both point to same memory)
6. **B)** - Should use delete[] for arrays
7. **B) 7 8** - (*p)++ uses 7, then increments to 8
8. **B)** - First 100 integers leaked when reassigning

---

### Section C Solutions

<details>
<summary>Task 1</summary>

```cpp
int* mergeSorted(int* a, int sizeA, int* b, int sizeB) {
    int* result = new int[sizeA + sizeB];
    int i = 0, j = 0, k = 0;
    
    while (i < sizeA && j < sizeB) {
        if (a[i] <= b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
    
    while (i < sizeA) result[k++] = a[i++];
    while (j < sizeB) result[k++] = b[j++];
    
    return result;
}
```
</details>

<details>
<summary>Task 2</summary>

```cpp
int diagonalSum(int** mat, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];           // Main diagonal
        sum += mat[i][n - 1 - i];   // Anti-diagonal
    }
    
    // If odd n, center counted twice
    if (n % 2 == 1) {
        sum -= mat[n/2][n/2];
    }
    
    return sum;
}
```
</details>

<details>
<summary>Task 3</summary>

```cpp
int** deepCopy2D(int** source, int rows, int cols) {
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
- [ ] Can handle complex expressions
- [ ] Understand shallow vs deep copy
- [ ] Can calculate memory leaks
- [ ] MCQs: 7/8 or better
- [ ] All coding tasks complete
- [ ] Time: _______ minutes

**You're ready for the mock exam!**

---

*🔥 Advanced problems mastered! Final push ahead!*
