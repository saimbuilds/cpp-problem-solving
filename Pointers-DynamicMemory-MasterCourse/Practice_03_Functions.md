# Practice Set 3: Pointers & Functions
## 30 Minutes - Function Mastery

> **Goal**: Master pointer parameters, returns, and array function arguments

---

## Section A: Dry Run Challenges (15 minutes)

### Problem 1: Basic Pass by Pointer
```cpp
void modify(int* x) {
    *x = *x * 3;
}

int main() {
    int num = 7;
    modify(&num);
    cout << num;
    return 0;
}
```
**Output:** `__________`

---

### Problem 2: Double Pointer Modification
```cpp
void change(int* a, int* b) {
    *a = *a + 5;
    *b = *b - 3;
}

int main() {
    int x = 10, y = 20;
    change(&x, &y);
    cout << x << " " << y;
    return 0;
}
```
**Output:** `__________`

---

### Problem 3: Swap Function
```cpp
void swap(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int a = 5, b = 15;
    swap(&a, &b);
    cout << a << " " << b;
    return 0;
}
```
**Output:** `__________`

---

### Problem 4: Array Function Parameter
```cpp
void incrementArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) += 1;
    }
}

int main() {
    int arr[] = {10, 20, 30};
    incrementArray(arr, 3);
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**Output:** `__________`

---

### Problem 5: Multiple Return Values
```cpp
void calculate(int a, int b, int* sum, int* diff) {
    *sum = a + b;
    *diff = a - b;
}

int main() {
    int s, d;
    calculate(25, 10, &s, &d);
    cout << s << " " << d;
    return 0;
}
```
**Output:** `__________`

---

### Problem 6: Return Pointer
```cpp
int* findMin(int* arr, int size) {
    int* minPtr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *minPtr) {
            minPtr = arr + i;
        }
    }
    return minPtr;
}

int main() {
    int arr[] = {50, 20, 70, 10, 60};
    int* min = findMin(arr, 5);
    cout << *min;
    return 0;
}
```
**Output:** `__________`

---

### Problem 7: Tricky Modification
```cpp
void mysterious(int* x, int* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() {
    int a = 8, b = 3;
    mysterious(&a, &b);
    cout << a << " " << b;
    return 0;
}
```
**Output:** `__________`

---

### Problem 8: Array Doubling
```cpp
void doubleEven(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            *(arr + i) *= 2;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    doubleEven(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**Output:** `__________`

---

### Problem 9: Complex Chain
```cpp
void processValues(int* a, int* b, int* c) {
    *a = *b + *c;
    *b = *a - *c;
    *c = *a + *b;
}

int main() {
    int x = 5, y = 10, z = 15;
    processValues(&x, &y, &z);
    cout << x << " " << y << " " << z;
    return 0;
}
```
**Output:** `__________`

---

### Problem 10: FAST-Style Challenge
```cpp
int* findSecondLargest(int* arr, int size) {
    int* first = arr;
    int* second = arr;
    
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *first) {
            second = first;
            first = arr + i;
        } else if (*(arr + i) > *second && (arr + i) != first) {
            second = arr + i;
        }
    }
    return second;
}

int main() {
    int arr[] = {10, 50, 30, 70, 20};
    int* result = findSecondLargest(arr, 5);
    cout << *result;
    return 0;
}
```
**Output:** `__________`

---

## Section B: MCQs (10 minutes)

### Q1. What's wrong?
```cpp
void func(int x) { x = 100; }
int main() {
    int a = 50;
    func(&a);
    cout << a;
}
```
A) Nothing wrong  
B) Should be `func(a)` without `&`  
C) Should be `void func(int* x)`  
D) Both B and C  

---

### Q2. What's the output?
```cpp
void swap(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    cout << x << " " << y;
}
```
A) 10 5  
B) 5 10  
C) 0 0  
D) Compilation error  

---

### Q3. Which is TRUE about array function parameters?
A) Arrays are passed by value  
B) Array size must be specified in parameter  
C) Arrays decay to pointers  
D) Cannot pass arrays to functions  

---

### Q4. What's valid?
A) Returning pointer to local variable  
B) Returning pointer to array element  
C) Returning pointer to literal  
D) None of above  

---

### Q5. What's the output?
```cpp
void func(int* arr, int size) {
    arr[2] = 100;
}
int main() {
    int arr[] = {1, 2, 3, 4};
    func(arr, 4);
    cout << arr[2];
}
```
A) 3  
B) 100  
C) Garbage  
D) Compilation error  

---

### Q6. Identify error:
```cpp
int* getNumber() {
    int x = 10;
    return &x;
}
```
A) Syntax error  
B) Type mismatch  
C) Returning address of local variable  
D) No error  

---

### Q7. What does `const int* ptr` mean?
A) Pointer cannot change  
B) Value at pointer cannot change  
C) Both A and B  
D) Neither A nor B  

---

### Q8. Output?
```cpp
void modify(int* x, int* y) {
    *x = 20;
    y = x;
}
int main() {
    int a = 10, b = 30;
    modify(&a, &b);
    cout << a << " " << b;
}
```
A) 20 20  
B) 20 30  
C) 10 30  
D) 10 20  

---

## Section C: Code Writing (5 minutes)

### Task 1: Find Maximum
```cpp
// Return pointer to maximum element in array
int* findMax(int* arr, int size) {
    // Your code
}

// Test
int main() {
    int arr[] = {12, 45, 23, 67, 34};
    int* maxPtr = findMax(arr, 5);
    cout << *maxPtr;  // Should print: 67
    return 0;
}
```

---

### Task 2: Rotate Array
```cpp
// Rotate array right by 1 position
// {1,2,3,4} becomes {4,1,2,3}
void rotateRight(int* arr, int size) {
    // Your code
}

// Test
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    rotateRight(arr, 5);
    // Should print: 5 1 2 3 4
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```

---

### Task 3: Get Min and Max
```cpp
// Find both min and max using pointers
void findMinMax(int* arr, int size, int* min, int* max) {
    // Your code
}

// Test
int main() {
    int arr[] = {34, 12, 78, 5, 90};
    int minimum, maximum;
    findMinMax(arr, 5, &minimum, &maximum);
    cout << minimum << " " << maximum;  // Should print: 5 90
    return 0;
}
```

---

## Solutions

### Section A Solutions

<details>
<summary>Problem 1</summary>

**Output:** `21`

num = 7, passed to modify, 7 * 3 = 21
</details>

<details>
<summary>Problem 2</summary>

**Output:** `15 17`

x = 10 + 5 = 15  
y = 20 - 3 = 17
</details>

<details>
<summary>Problem 3</summary>

**Output:** `15 5`

Values swapped
</details>

<details>
<summary>Problem 4</summary>

**Output:** `11 21 31`

Each element incremented by 1
</details>

<details>
<summary>Problem 5</summary>

**Output:** `35 15`

sum = 25 + 10 = 35  
diff = 25 - 10 = 15
</details>

<details>
<summary>Problem 6</summary>

**Output:** `10`

findMin returns pointer to smallest element (10)
</details>

<details>
<summary>Problem 7</summary>

**Output:** `3 8`

This is a swap without temp variable!  
Trace:
- a = 8 + 3 = 11, b = 3
- b = 11 - 3 = 8
- a = 11 - 8 = 3
</details>

<details>
<summary>Problem 8</summary>

**Output:** `1 4 3 8 5`

Only even numbers doubled: 2→4, 4→8
</details>

<details>
<summary>Problem 9</summary>

**Output:** `25 10 35`

Trace:
- x = 10 + 15 = 25
- y = 25 - 15 = 10
- z = 25 + 10 = 35
</details>

<details>
<summary>Problem 10</summary>

**Output:** `50`

Second largest in {10, 50, 30, 70, 20} is 50
</details>

---

### Section B MCQ Answers

1. **D)** - Parameter should be pointer and call should pass value (or parameter should be value and call should pass address)
2. **B) 5 10** - Swapping pointers doesn't swap values! Common mistake!
3. **C)** - Arrays decay to pointers when passed to functions
4. **B)** - Can return pointer to array element (lives beyond function)
5. **B) 100** - Array modified through pointer
6. **C)** - Returning address of local variable causes undefined behavior
7. **B)** - `const int*` means value cannot be changed through pointer
8. **B) 20 30** - a is modified to 20, but b unchanged (only local pointer y changed)

---

### Section C Solutions

<details>
<summary>Task 1: Find Max</summary>

```cpp
int* findMax(int* arr, int size) {
    int* maxPtr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    return maxPtr;
}
```
</details>

<details>
<summary>Task 2: Rotate Right</summary>

```cpp
void rotateRight(int* arr, int size) {
    int last = *(arr + size - 1);
    for (int i = size - 1; i > 0; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *arr = last;
}
```
</details>

<details>
<summary>Task 3: Find Min Max</summary>

```cpp
void findMinMax(int* arr, int size, int* min, int* max) {
    *min = *arr;
    *max = *arr;
    
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
    }
}
```
</details>

---

## Performance Check

- [ ] All dry runs: 10/10
- [ ] MCQs: 7/8 or better
- [ ] All coding tasks working
- [ ] Understand why Q2 MCQ doesn't swap
- [ ] Time: _______ minutes

**Critical Understanding:**
- ✅ Swapping pointer values ≠ swapping pointed values
- ✅ Arrays are always passed by pointer
- ✅ Never return address of local variable
- ✅ Use const for read-only parameters

**Ready for Module 4: Dynamic Memory!**

---

*🔥 Function pointers mastered! Now the BIG topic: Dynamic Memory Allocation!*
