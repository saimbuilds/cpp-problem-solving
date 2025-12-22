# Practice Set 1: Pointer Fundamentals
## 30 Minutes of Intense Practice

> **Goal**: Master basic pointer operations through dry runs and coding challenges

---

## Section A: Dry Run Challenges (15 minutes)

### Problem 1: Basic Trace
```cpp
int main() {
    int a = 15;
    int* ptr = &a;
    *ptr = *ptr + 5;
    int b = *ptr * 2;
    cout << a << " " << b << " " << *ptr;
    return 0;
}
```
**Output:** `__________`

---

### Problem 2: Multiple Assignments
```cpp
int main() {
    int x = 3;
    int* p1 = &x;
    int* p2 = p1;
    *p1 = 7;
    *p2 = *p2 + 2;
    cout << x << " " << *p1 << " " << *p2;
    return 0;
}
```
**Output:** `__________`

---

### Problem 3: Pointer Swap Pattern
```cpp
int main() {
    int m = 12, n = 8;
    int* a = &m;
    int* b = &n;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << m << " " << n;
    return 0;
}
```
**Output:** `__________`

---

### Problem 4: Tricky Reassignment
```cpp
int main() {
    int x = 5, y = 10, z = 15;
    int* ptr = &x;
    *ptr = 20;
    ptr = &y;
    *ptr = *ptr + 5;
    ptr = &z;
    cout << x << " " << y << " " << z << " " << *ptr;
    return 0;
}
```
**Output:** `__________`

---

### Problem 5: Nested Operations
```cpp
int main() {
    int a = 4;
    int* p = &a;
    *p = (*p) * (*p);
    *p = *p + a;
    cout << a << " " << *p;
    return 0;
}
```
**Output:** `__________`

---

### Problem 6: Chain of Pointers
```cpp
int main() {
    int val = 100;
    int* p1 = &val;
    int* p2 = p1;
    int* p3 = p2;
    *p3 = 50;
    *p1 = *p2 + *p3;
    cout << val << " " << *p1 << " " << *p2 << " " << *p3;
    return 0;
}
```
**Output:** `__________`

---

### Problem 7: Expression Evaluation
```cpp
int main() {
    int x = 6;
    int* ptr = &x;
    int result = (*ptr)++ + ++(*ptr);
    cout << x << " " << result;
    return 0;
}
```
**Output:** `__________`  
**Hint:** Remember post-increment vs pre-increment!

---

### Problem 8: FAST-Style Tricky One
```cpp
int main() {
    int a = 2, b = 3;
    int* p = &a;
    int* q = &b;
    *p = *q;
    *q = *p;
    p = q;
    *p = 5;
    cout << a << " " << b;
    return 0;
}
```
**Output:** `__________`

---

## Section B: MCQs (10 minutes)

### Q1. What is the output?
```cpp
int x = 10;
int* p = &x;
*p += 5;
x -= 3;
cout << *p;
```
A) 10  
B) 12  
C) 15  
D) 13  

---

### Q2. Which statement is FALSE?
A) A pointer can point to another pointer  
B) A pointer variable has its own memory address  
C) All pointer types have the same size on a given system  
D) You can perform division on pointers  

---

### Q3. What does this print?
```cpp
int arr[] = {1, 2, 3};
int* p = arr;
cout << *p;
```
A) Garbage value  
B) 1  
C) Address of arr  
D) Compilation error  

---

### Q4. Identify the error:
```cpp
int x = 5;
int* p;
*p = x;
```
A) Cannot assign int to pointer  
B) Pointer not initialized before dereferencing  
C) Type mismatch  
D) No error  

---

### Q5. What's the output?
```cpp
int a = 5;
int* p = &a;
cout << (p == &a);
```
A) 0  
B) 1  
C) Address of a  
D) Compilation error  

---

### Q6. Which is valid initialization?
A) `int* p = 0x1234;`  
B) `int* p = new int;`  
C) `int* p = 5;`  
D) `int* p = &(&x);`  

---

### Q7. What's printed?
```cpp
int x = 10;
int* p = &x;
int* q = p;
*q = 20;
cout << x;
```
A) 10  
B) 20  
C) Garbage  
D) Compilation error  

---

### Q8. Size of pointer?
```cpp
double* p;
cout << sizeof(p) << " " << sizeof(*p);
```
On 64-bit system:  
A) 8 4  
B) 8 8  
C) 4 8  
D) Depends on compiler  

---

## Section C: Code Writing (5 minutes)

### Task 1: Write a function
```cpp
// Write a function that swaps two integers using pointers
void swapValues(int* a, int* b) {
    // Your code here
}

// Test
int main() {
    int x = 10, y = 20;
    swapValues(&x, &y);
    cout << x << " " << y;  // Should print: 20 10
    return 0;
}
```

---

### Task 2: Find Maximum
```cpp
// Write a function that returns pointer to the larger of two numbers
int* findMax(int* a, int* b) {
    // Your code here
}

// Test
int main() {
    int x = 15, y = 25;
    int* max = findMax(&x, &y);
    cout << *max;  // Should print: 25
    return 0;
}
```

---

### Task 3: Increment via Pointer
```cpp
// Write a function that increments a value by n using pointers
void incrementBy(int* value, int n) {
    // Your code here
}

// Test
int main() {
    int num = 10;
    incrementBy(&num, 5);
    cout << num;  // Should print: 15
    return 0;
}
```

---

## Solutions

### Section A Dry Runs

<details>
<summary>Problem 1 Solution</summary>

**Output:** `20 40 20`

Trace:
1. a = 15
2. ptr = &a
3. *ptr = 15 + 5 = 20 (a becomes 20)
4. b = 20 * 2 = 40
5. Print: 20 40 20
</details>

<details>
<summary>Problem 2 Solution</summary>

**Output:** `9 9 9`

Trace:
1. x = 3
2. p1 = &x, p2 = &x (both point to x)
3. *p1 = 7 → x = 7
4. *p2 = 7 + 2 = 9 → x = 9
5. Print: 9 9 9
</details>

<details>
<summary>Problem 3 Solution</summary>

**Output:** `8 12`

Trace:
1. m = 12, n = 8
2. a = &m, b = &n
3. temp = 12
4. *a = *b → m = 8
5. *b = temp → n = 12
6. Print: 8 12
</details>

<details>
<summary>Problem 4 Solution</summary>

**Output:** `20 15 15 15`

Trace:
1. x = 5, y = 10, z = 15
2. ptr = &x, *ptr = 20 → x = 20
3. ptr = &y, *ptr = 15 → y = 15
4. ptr = &z (z unchanged)
5. Print: 20 15 15 15
</details>

<details>
<summary>Problem 5 Solution</summary>

**Output:** `32 32`

Trace:
1. a = 4
2. p = &a
3. *p = 4 * 4 = 16 → a = 16
4. *p = 16 + 16 = 32 → a = 32
5. Print: 32 32
</details>

<details>
<summary>Problem 6 Solution</summary>

**Output:** `100 100 100 100`

Trace:
1. val = 100, all pointers point to val
2. *p3 = 50 → val = 50
3. *p1 = 50 + 50 = 100 → val = 100
4. All print 100
</details>

<details>
<summary>Problem 7 Solution</summary>

**Output:** `8 14`

Trace:
1. x = 6
2. (*ptr)++ → use 6, then x becomes 7
3. ++(*ptr) → x becomes 8, use 8
4. result = 6 + 8 = 14
5. Print: 8 14
</details>

<details>
<summary>Problem 8 Solution</summary>

**Output:** `3 5`

Trace:
1. a = 2, b = 3
2. *p = *q → a = 3
3. *q = *p → b = 3
4. p = q → p now points to b
5. *p = 5 → b = 5
6. Print: 3 5
</details>

---

### Section B MCQ Answers

1. **B) 12** - Step: x=10, x+=5=15, x-=3=12
2. **D)** - You can perform division on pointers (not allowed!)
3. **B) 1** - Array name decays to pointer to first element
4. **B)** - p contains garbage, dereferencing is undefined behavior
5. **B) 1** - Condition is true, outputs 1
6. **B)** - new int is valid; A) direct assignment of address not recommended; C) type error; D) syntax error
7. **B) 20** - q points to x, changes x to 20
8. **B) 8 8** - Pointer is 8 bytes, double is 8 bytes

---

### Section C Code Solutions

<details>
<summary>Task 1: Swap</summary>

```cpp
void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```
</details>

<details>
<summary>Task 2: Find Max</summary>

```cpp
int* findMax(int* a, int* b) {
    if (*a > *b)
        return a;
    else
        return b;
}
```
or one-liner:
```cpp
int* findMax(int* a, int* b) {
    return (*a > *b) ? a : b;
}
```
</details>

<details>
<summary>Task 3: Increment</summary>

```cpp
void incrementBy(int* value, int n) {
    *value += n;
}
```
</details>

---

## Performance Check

- [ ] Completed all dry runs with 100% accuracy
- [ ] Scored 7/8 or higher on MCQs
- [ ] Completed all code tasks
- [ ] Time taken: _______ minutes

**If < 90% accuracy**: Review Module 1 again before proceeding  
**If ≥ 90% accuracy**: You're ready for Module 2!

---

*🔥 Practice complete! Time to level up with Pointer Arithmetic.*
