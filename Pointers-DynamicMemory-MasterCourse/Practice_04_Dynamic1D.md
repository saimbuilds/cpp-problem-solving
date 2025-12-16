# Practice Set 4: Dynamic Memory - 1D Arrays
## 30 Minutes - Memory Management Master

> **Goal**: Master dynamic allocation, deallocation, and avoid memory leaks

---

## Section A: Dry Run & Analysis (15 minutes)

### Problem 1: Basic Allocation
```cpp
int* ptr = new int(25);
*ptr += 5;
cout << *ptr;
delete ptr;
```
**Output:** `__________`

---

### Problem 2: Dynamic Array
```cpp
int n = 5;
int* arr = new int[n];
for (int i = 0; i < n; i++) {
    arr[i] = i * i;
}
cout << arr[3];
delete[] arr;
```
**Output:** `__________`

---

### Problem 3: Memory Leak Detection
```cpp
void func() {
    int* p = new int[10];
    p[0] = 100;
}

int main() {
    for (int i = 0; i < 3; i++) {
        func();
    }
    return 0;
}
```
**Question:** How many integers worth of memory is leaked?  
**Answer:** `__________`

---

### Problem 4: Correct vs Incorrect
```cpp
// Code A
int* arr = new int[5];
delete arr;

// Code B
int* arr = new int[5];
delete[] arr;
```
**Which is correct?** `__________`

---

### Problem 5: Dangling Pointer
```cpp
int* p = new int(10);
delete p;
*p = 20;
cout << *p;
```
**What happens?**  
A) Outputs 20  
B) Outputs 10  
C) Undefined behavior  
D) Compilation error  

**Answer:** `__________`

---

### Problem 6: Dynamic Array Manipulation
```cpp
int n = 4;
int* arr = new int[n];
arr[0] = 5;
arr[1] = 10;
arr[2] = 15;
arr[3] = 20;

int* ptr = arr + 2;
*ptr = *ptr + 5;
cout << arr[2] << " ";

delete[] arr;
```
**Output:** `__________`

---

### Problem 7: Function Return
```cpp
int* createArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int* myArr = createArray(3);
    cout << myArr[0] << " " << myArr[2];
    delete[] myArr;
    return 0;
}
```
**Output:** `__________`

---

### Problem 8: Multiple Allocations
```cpp
int* p1 = new int(5);
int* p2 = new int(10);
*p1 = *p1 + *p2;
*p2 = *p1 - *p2;
cout << *p1 << " " << *p2;
delete p1;
delete p2;
```
**Output:** `__________`

---

### Problem 9: Array Resize Pattern
```cpp
int* old = new int[3];
old[0] = 1; old[1] = 2; old[2] = 3;

int* newArr = new int[5];
for (int i = 0; i < 3; i++) {
    newArr[i] = old[i];
}
newArr[3] = 4;
newArr[4] = 5;

delete[] old;
cout << newArr[2] << " " << newArr[4];
delete[] newArr;
```
**Output:** `__________`

---

### Problem 10: FAST-Style Challenge
```cpp
int* merge(int* a1, int s1, int* a2, int s2) {
    int* result = new int[s1 + s2];
    for (int i = 0; i < s1; i++) {
        result[i] = a1[i];
    }
    for (int i = 0; i < s2; i++) {
        result[s1 + i] = a2[i];
    }
    return result;
}

int main() {
    int* arr1 = new int[2];
    arr1[0] = 10; arr1[1] = 20;
    
    int* arr2 = new int[3];
    arr2[0] = 30; arr2[1] = 40; arr2[2] = 50;
    
    int* merged = merge(arr1, 2, arr2, 3);
    cout << merged[1] << " " << merged[3];
    
    delete[] arr1;
    delete[] arr2;
    delete[] merged;
    return 0;
}
```
**Output:** `__________`

---

## Section B: MCQs (10 minutes)

### Q1. What's the correct way to free this?
```cpp
int* arr = new int[100];
```
A) `free(arr);`  
B) `delete arr;`  
C) `delete[] arr;`  
D) `delete[100] arr;`  

---

### Q2. What causes memory leak?
```cpp
int* p = new int[10];
p = new int[20];
delete[] p;
```
A) First allocation  
B) Second allocation  
C) Both  
D) Neither  

---

### Q3. What's printed?
```cpp
int* p = new int(15);
int* q = p;
*q = 25;
cout << *p;
delete p;
```
A) 15  
B) 25  
C) Garbage  
D) Compilation error  

---

### Q4. Which is TRUE?
A) Stack memory requires delete  
B) Heap memory auto-frees at scope end  
C) new allocates on heap  
D) All dynamically allocated memory is stack memory  

---

### Q5. What's wrong?
```cpp
int* arr = new int[5];
delete[] arr;
delete[] arr;
```
A) Nothing  
B) Memory leak  
C) Double deletion  
D) Syntax error  

---

### Q6. Valid statement?
A) `int arr[n];` where n is variable  
B) `int* arr = new int[n];` where n is variable  
C) Both A and B  
D) Neither  

---

### Q7. What happens?
```cpp
int* p = new int(10);
delete p;
p = nullptr;
delete p;
```
A) Crash  
B) Memory leak  
C) Safe (no-op)  
D) Compilation error  

---

### Q8. Output?
```cpp
int* arr = new int[3]{10, 20, 30};
cout << *(arr + 1);
delete[] arr;
```
A) 10  
B) 20  
C) 30  
D) Compilation error  

---

## Section C: Code Writing (5 minutes)

### Task 1: Dynamic Input
```cpp
// Read n integers into dynamic array and return it
int* readArray(int n) {
    // Your code
}

// Test
int main() {
    int size;
    cin >> size;  // E.g., 3
    int* arr = readArray(size);
    // Input: 5 10 15
    // arr should contain {5, 10, 15}
    delete[] arr;
    return 0;
}
```

---

### Task 2: Copy Array
```cpp
// Create a copy of array (deep copy)
int* copyArray(int* source, int size) {
    // Your code
}

// Test
int main() {
    int original[] = {1, 2, 3, 4};
    int* copy = copyArray(original, 4);
    copy[0] = 100;  // Should not affect original
    cout << original[0];  // Should print: 1
    delete[] copy;
    return 0;
}
```

---

### Task 3: Filter Even Numbers
```cpp
// Create new array with only even numbers
// Return new array and set newSize
int* filterEven(int* arr, int size, int& newSize) {
    // Your code
}

// Test
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int newSize;
    int* evens = filterEven(arr, 6, newSize);
    // evens should be {2, 4, 6}, newSize = 3
    delete[] evens;
    return 0;
}
```

---

## Solutions

### Section A Solutions

<details>
<summary>Problem 1</summary>

**Output:** `30`

Allocates int with value 25, adds 5 → 30
</details>

<details>
<summary>Problem 2</summary>

**Output:** `9`

arr[3] = 3 * 3 = 9
</details>

<details>
<summary>Problem 3</summary>

**Answer:** `30 integers`

Each call to func() leaks 10 integers. Called 3 times = 30 integers (120 bytes on 32-bit)
</details>

<details>
<summary>Problem 4</summary>

**Answer:** Code B is correct

Must use `delete[]` for arrays, not `delete`
</details>

<details>
<summary>Problem 5</summary>

**Answer:** C) Undefined behavior

Accessing deleted memory is undefined behavior
</details>

<details>
<summary>Problem 6</summary>

**Output:** `20`

ptr points to arr[2] (15), adds 5 → 20
</details>

<details>
<summary>Problem 7</summary>

**Output:** `1 3`

Array contains {1, 2, 3}, prints first and third elements
</details>

<details>
<summary>Problem 8</summary>

**Output:** `15 5`

*p1 = 5 + 10 = 15  
*p2 = 15 - 10 = 5
</details>

<details>
<summary>Problem 9</summary>

**Output:** `3 5`

Copies old array to new, then adds 4 and 5. Prints newArr[2]=3 and newArr[4]=5
</details>

<details>
<summary>Problem 10</summary>

**Output:** `20 40`

merged[1] = arr1[1] = 20  
merged[3] = arr2[1] = 40
</details>

---

### Section B MCQ Answers

1. **C)** `delete[]` for arrays
2. **A)** First allocation leaked when p reassigned
3. **B) 25** - Both p and q point to same memory
4. **C)** new allocates on heap
5. **C)** Double deletion causes undefined behavior
6. **B)** Variable-length arrays not standard C++, but dynamic allocation works
7. **C)** Deleting nullptr is safe (no-op)
8. **B) 20** - *(arr + 1) is arr[1] = 20

---

### Section C Solutions

<details>
<summary>Task 1: Read Array</summary>

```cpp
int* readArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}
```
</details>

<details>
<summary>Task 2: Copy Array</summary>

```cpp
int* copyArray(int* source, int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = source[i];
    }
    return copy;
}
```
</details>

<details>
<summary>Task 3: Filter Even</summary>

```cpp
int* filterEven(int* arr, int size, int& newSize) {
    // First, count evens
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            newSize++;
        }
    }
    
    // Allocate and fill
    int* result = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            result[index++] = arr[i];
        }
    }
    return result;
}
```
</details>

---

## Performance Check

- [ ] All dry runs: 10/10
- [ ] Can identify memory leaks
- [ ] Know `delete` vs `delete[]`
- [ ] Understand dangling pointers
- [ ] MCQs: 7/8 or better
- [ ] Time: _______ minutes

**Critical Mastery:**
- ✅ Always `delete[]` what you `new[]`
- ✅ Set to nullptr after delete
- ✅ Never use after delete
- ✅ Check for memory leaks

**Ready for Module 5: 2D Dynamic Arrays!**

---

*🔥 1D Dynamic Memory conquered! Time for the boss level: 2D Arrays!*
