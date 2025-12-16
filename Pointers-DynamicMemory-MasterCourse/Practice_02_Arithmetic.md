# Practice Set 2: Pointer Arithmetic & Arrays
## 30 Minutes - Intense Drill

> **Goal**: Become lightning-fast at pointer arithmetic and array manipulation

---

## Section A: Dry Run Challenges (18 minutes)

### Problem 1: Basic Arithmetic
```cpp
int arr[] = {5, 10, 15, 20, 25};
int* ptr = arr + 2;
cout << *ptr << " ";
ptr++;
cout << *ptr << " ";
ptr -= 2;
cout << *ptr;
```
**Output:** `__________`

---

### Problem 2: Array-Pointer Equivalence
```cpp
int arr[] = {100, 200, 300, 400};
cout << arr[1] << " ";
cout << *(arr + 1) << " ";
cout << 1[arr];
```
**Output:** `__________`

---

### Problem 3: Modification Through Pointer
```cpp
int arr[] = {2, 4, 6, 8, 10};
int* p = arr;
*(p + 2) = 50;
p++;
*p = 40;
for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
```
**Output:** `__________`

---

### Problem 4: Pointer Difference
```cpp
int arr[10];
int* p1 = &arr[2];
int* p2 = &arr[7];
cout << (p2 - p1) << " ";
cout << (p1 - p2);
```
**Output:** `__________`

---

### Problem 5: Traversal Pattern
```cpp
int arr[] = {1, 3, 5, 7, 9};
int* ptr = arr;
int sum = 0;
for (int i = 0; i < 5; i++) {
    sum += *ptr;
    ptr++;
}
cout << sum;
```
**Output:** `__________`

---

### Problem 6: Post-Increment Trick
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;
cout << *ptr++ << " ";
cout << *ptr++ << " ";
cout << *ptr;
```
**Output:** `__________`

---

### Problem 7: Complex Expression
```cpp
int arr[] = {5, 10, 15, 20};
int* p = arr + 1;
int result = *(p + 1) + *(p - 1);
cout << result;
```
**Output:** `__________`

---

### Problem 8: Reverse Traversal
```cpp
int arr[] = {2, 4, 6, 8};
int* ptr = arr + 3;
for (int i = 0; i < 4; i++) {
    cout << *ptr << " ";
    ptr--;
}
```
**Output:** `__________`

---

### Problem 9: Two Pointer Pattern
```cpp
int arr[] = {1, 2, 3, 4, 5};
int* start = arr;
int* end = arr + 4;
while (start < end) {
    int temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
}
for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
```
**Output:** `__________`

---

### Problem 10: FAST-Style Complex
```cpp
int arr[] = {3, 6, 9, 12, 15};
int* p1 = arr;
int* p2 = arr + 4;
*p1 = *p1 + *p2;
*(p1 + 1) = *(p2 - 1);
p2 = p1 + 2;
*p2 = 0;
for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
```
**Output:** `__________`

---

### Problem 11: Address Arithmetic
```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;
cout << (ptr + 2) - ptr << " ";
cout << (ptr + 3) - (ptr + 1);
```
**Output:** `__________`

---

### Problem 12: Increment vs Dereference
```cpp
int arr[] = {5, 10, 15};
int* ptr = arr;
cout << (*ptr)++ << " ";
cout << *ptr << " ";
cout << *++ptr;
```
**Output:** `__________`

---

## Section B: MCQs (8 minutes)

### Q1. What's the output?
```cpp
int arr[] = {1, 2, 3, 4};
int* p = arr + 2;
cout << p[-1];
```
A) 1  
B) 2  
C) 3  
D) Garbage  

---

### Q2. If `int* p = arr;` where arr has 10 elements, what's valid?
A) `p[10]`  
B) `*(p + 10)`  
C) `arr++`  
D) `p + 9`  

---

### Q3. What's the output?
```cpp
int arr[] = {5, 10, 15};
int* p = &arr[2];
cout << *(p - 2);
```
A) 5  
B) 10  
C) 15  
D) Compilation error  

---

### Q4. Given `int arr[5];`, which is INVALID?
A) `arr + 3`  
B) `&arr[3]`  
C) `arr += 2`  
D) `*(arr + 3)`  

---

### Q5. What's printed?
```cpp
int arr[] = {10, 20, 30};
int* p1 = arr;
int* p2 = arr + 2;
cout << (p2 > p1);
```
A) 0  
B) 1  
C) Address  
D) Compilation error  

---

### Q6. Output?
```cpp
int arr[] = {1, 2, 3};
cout << 2[arr];
```
A) Compilation error  
B) 2  
C) 3  
D) Undefined  

---

### Q7. What's the result?
```cpp
int arr[5] = {0};
int* p = arr + 2;
*p = 10;
cout << arr[2];
```
A) 0  
B) 10  
C) 2  
D) Garbage  

---

### Q8. Which is TRUE?
A) `arr[i]` is always faster than `*(arr + i)`  
B) Pointer arithmetic is done in bytes  
C) `ptr++` moves by sizeof(type) bytes  
D) You can add two pointers  

---

## Section C: Code Writing (4 minutes)

### Task 1: Find Maximum
```cpp
// Find maximum element in array using pointers only
int findMax(int* arr, int size) {
    // Your code - no arr[i] notation allowed!
}

// Test
int main() {
    int arr[] = {5, 12, 3, 19, 7};
    cout << findMax(arr, 5);  // Should print: 19
    return 0;
}
```

---

### Task 2: Reverse Array
```cpp
// Reverse array in-place using pointers
void reverseArray(int* arr, int size) {
    // Your code here
}

// Test
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";  // Should print: 5 4 3 2 1
    return 0;
}
```

---

### Task 3: Count Occurrences
```cpp
// Count how many times 'target' appears in array using pointers
int countOccurrences(int* arr, int size, int target) {
    // Your code here
}

// Test
int main() {
    int arr[] = {5, 3, 5, 7, 5, 2};
    cout << countOccurrences(arr, 6, 5);  // Should print: 3
    return 0;
}
```

---

## Solutions

### Section A Dry Runs

<details>
<summary>Problem 1</summary>

**Output:** `15 20 10`

Trace:
- ptr = arr + 2 → &arr[2], *ptr = 15
- ptr++ → &arr[3], *ptr = 20  
- ptr -= 2 → &arr[1], *ptr = 10
</details>

<details>
<summary>Problem 2</summary>

**Output:** `200 200 200`

All three expressions are equivalent!
</details>

<details>
<summary>Problem 3</summary>

**Output:** `2 40 50 8 10`

Trace:
- p = arr (points to arr[0])
- *(p + 2) = 50 → arr[2] = 50
- p++ → p points to arr[1]
- *p = 40 → arr[1] = 40
</details>

<details>
<summary>Problem 4</summary>

**Output:** `5 -5`

Distance from index 2 to 7 is 5 elements.
Reverse is -5.
</details>

<details>
<summary>Problem 5</summary>

**Output:** `25`

Sum: 1 + 3 + 5 + 7 + 9 = 25
</details>

<details>
<summary>Problem 6</summary>

**Output:** `10 20 30`

`*ptr++` → use current value, then increment pointer
</details>

<details>
<summary>Problem 7</summary>

**Output:** `20`

- p = arr + 1 → points to 10
- *(p + 1) = arr[2] = 15
- *(p - 1) = arr[0] = 5
- result = 15 + 5 = 20
</details>

<details>
<summary>Problem 8</summary>

**Output:** `8 6 4 2`

Starts at arr[3] and goes backward.
</details>

<details>
<summary>Problem 9</summary>

**Output:** `5 4 3 2 1`

This is array reversal using two pointers.
</details>

<details>
<summary>Problem 10</summary>

**Output:** `18 12 0 12 15`

Trace:
- *p1 = 3 + 15 = 18 → arr[0] = 18
- *(p1 + 1) = *(p2 - 1) = arr[3] = 12 → arr[1] = 12
- p2 = p1 + 2 → p2 points to arr[2]
- *p2 = 0 → arr[2] = 0
</details>

<details>
<summary>Problem 11</summary>

**Output:** `2 2`

Pointer subtraction gives element distance.
</details>

<details>
<summary>Problem 12</summary>

**Output:** `5 6 10`

Trace:
- (*ptr)++ → use 5, then increment value to 6
- *ptr → now 6
- *++ptr → increment pointer first, then use value (10)
</details>

---

### Section B MCQ Answers

1. **B) 2** - p[-1] is same as *(p - 1) = arr[1] = 2
2. **D)** - D is valid; A and B are out of bounds; C is invalid (can't modify array name)
3. **A) 5** - p points to arr[2], p - 2 points to arr[0]
4. **C)** - Cannot modify array name with +=
5. **B) 1** - p2 is after p1, so condition is true
6. **C) 3** - 2[arr] ≡ *(2 + arr) ≡ arr[2] = 3
7. **B) 10** - p points to arr[2], sets it to 10
8. **C)** - Pointer arithmetic scales by sizeof(type)

---

### Section C Solutions

<details>
<summary>Task 1: Find Max</summary>

```cpp
int findMax(int* arr, int size) {
    int max = *arr;  // First element
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}
```

Or using pointer increment:
```cpp
int findMax(int* arr, int size) {
    int max = *arr;
    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        if (*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}
```
</details>

<details>
<summary>Task 2: Reverse Array</summary>

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
</details>

<details>
<summary>Task 3: Count Occurrences</summary>

```cpp
int countOccurrences(int* arr, int size, int target) {
    int count = 0;
    int* ptr = arr;
    
    for (int i = 0; i < size; i++) {
        if (*ptr == target) {
            count++;
        }
        ptr++;
    }
    return count;
}
```
</details>

---

## Performance Check

- [ ] All dry runs correct (12/12)
- [ ] MCQs: 7/8 or better
- [ ] All code tasks working
- [ ] Can explain `*ptr++` vs `(*ptr)++` vs `*(++ptr)`
- [ ] Time: _______ minutes

**Mastery indicators:**
- ✅ Instant recognition of pointer arithmetic patterns
- ✅ Can trace complex expressions mentally
- ✅ Understand scaling factor for all types

**Ready for Module 3!**

---

*🔥 Pointer arithmetic mastered! Let's tackle Functions next.*
