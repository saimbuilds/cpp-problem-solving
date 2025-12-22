# 🎯 PRACTICE DRILLS - CODE BY HAND

> **Time:** Use during tomorrow's study sessions  
> **Method:** Write on paper, then check answers  
> **Purpose:** Build muscle memory for exam

---

# DRILL SET 1: POINTER TRACING (30 min)

## Problem 1: Basic Pointers

**Code:**
```cpp
#include <iostream>
using namespace std;

void foo(int*& ref) {
    ref = new int(100);
}

void bar(int** ptr) {
    *ptr = new int(200);
}

int main() {
    int* p = nullptr;
    foo(p);
    cout << *p << endl;
    
    int* q = nullptr;
    bar(&q);
    cout << *q << endl;
    
    delete p;
    delete q;
    return 0;
}
```

**Questions:**
1. What prints?
2. Why does `foo` need `int*&` instead of `int*`?
3. What happens if you forget `delete p; delete q;`?

**Answers:**
```
1. Output:
   100
   200

2. `int*&` is a reference to pointer - allows modifying the pointer itself.
   `int*` would only modify a copy, `p` would stay nullptr in main.

3. Memory leak - the allocated ints (100, 200) remain in heap,
   but pointers are lost when function ends.
```

---

## Problem 2: Nullptr Edge Cases

**Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (char*)nullptr << endl;      // Line 1
    cout << (int*)23 << endl;            // Line 2
    
    char* str = nullptr;
    cout << str << endl;                 // Line 3
    
    int* p = nullptr;
    cout << p << endl;                   // Line 4
    
    return 0;
}
```

**Questions:**
1. What does line 1 print?
2. What does line 2 print?
3. What's the difference between line 3 and line 4?

**Answers:**
```
1. (nothing/empty) - char* is treated as C-string, nullptr = empty string
2. 0x17 or 23 in hex - int* prints as address
3. Line 3: empty (char* = string behavior)
   Line 4: 0x0 or (nil) - int* prints as address
```

---

# DRILL SET 2: 2D ARRAY OPERATIONS (60 min)

## Problem 3: Matrix Transpose

**Task:** Write transpose on paper, trace for:
```
Input:
1 2 3
4 5 6
7 8 9
```

**Your code here (write on paper):**
```cpp
void transpose(int arr[][3], int n) {
    // YOUR CODE
}
```

**Answer:**
```cpp
void transpose(int arr[][3], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {  // Start j at i+1
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

// Output:
// 1 4 7
// 2 5 8
// 3 6 9
```

---

## Problem 4: Rotate 90° Clockwise

**Task:** Write algorithm, trace for:
```
Input:
1 2
3 4
```

**Algorithm (write steps):**
```
1. _________________
2. _________________
```

**Answer:**
```
1. Transpose matrix
2. Reverse each row

After transpose:
1 3
2 4

After reverse rows:
3 1
4 2
```

---

## Problem 5: Spiral Traversal

**Task:** Trace spiral for this matrix, write output:
```
1  2  3
4  5  6
7  8  9
```

**Trace (draw arrows on paper):**

**Output:** `___________________`

**Answer:**
```
Output: 1 2 3 6 9 8 7 4 5

Path:
→ → →
      ↓
      ↓
← ← ←
  ↓
```

---

# DRILL SET 3: RECURSION (45 min)

## Problem 6: Fibonacci Trace

**Code:**
```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Task:** Draw recursion tree for `fib(4)`

**Your tree (draw on paper):**

**Answer:**
```
                fib(4)
              /        \
          fib(3)      fib(2)
         /     \      /    \
     fib(2)  fib(1) fib(1) fib(0)
     /   \     |      |      |
  fib(1) fib(0) 1     1      0
    |      |
    1      0

Steps:
fib(4) = fib(3) + fib(2)
       = (fib(2) + fib(1)) + (fib(1) + fib(0))
       = ((fib(1) + fib(0)) + 1) + (1 + 0)
       = ((1 + 0) + 1) + 1
       = 3
```

---

## Problem 7: Array Sum Recursion

**Task:** Write recursive function to sum array

**Your code:**
```cpp
int arraySum(int arr[], int n) {
    // YOUR CODE
}
```

**Answer:**
```cpp
int arraySum(int arr[], int n) {
    if(n == 0) return 0;            // Base case
    return arr[n-1] + arraySum(arr, n-1);  // Recursive
}

// Trace for arr = [1,2,3], n=3:
// arraySum([1,2,3], 3) = 3 + arraySum([1,2,3], 2)
//                       = 3 + (2 + arraySum([1,2,3], 1))
//                       = 3 + (2 + (1 + arraySum([1,2,3], 0)))
//                       = 3 + (2 + (1 + 0))
//                       = 6
```

---

## Problem 8: Power Function

**Task:** Write `power(2, 5)` using recursion

**Your code:**
```cpp
int power(int base, int exp) {
    // YOUR CODE
}
```

**Answer:**
```cpp
int power(int base, int exp) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    return base * power(base, exp - 1);
}

// Optimized version:
int powerFast(int base, int exp) {
    if(exp == 0) return 1;
    if(exp % 2 == 0) {
        int half = powerFast(base, exp/2);
        return half * half;
    }
    return base * powerFast(base, exp-1);
}
```

---

# DRILL SET 4: FAMOUS ALGORITHMS (45 min)

## Problem 9: Remove Duplicates (Sorted Array)

**Input:** `[1, 1, 2, 2, 3, 4, 4, 5]`

**Task:** Write function, trace algorithm

**Your code:**
```cpp
int removeDuplicates(int arr[], int n) {
    // YOUR CODE
}
```

**Answer:**
```cpp
int removeDuplicates(int arr[], int n) {
    if(n == 0) return 0;
    
    int unique = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[unique]) {
            unique++;
            arr[unique] = arr[i];
        }
    }
    return unique + 1;
}

// Trace:
// i=1: arr[1]=1, arr[0]=1 → same, skip
// i=2: arr[2]=2, arr[0]=1 → diff, unique=1, arr[1]=2
// i=3: arr[3]=2, arr[1]=2 → same, skip
// i=4: arr[4]=3, arr[1]=2 → diff, unique=2, arr[2]=3
// i=5: arr[5]=4, arr[2]=3 → diff, unique=3, arr[3]=4
// i=6: arr[6]=4, arr[3]=4 → same, skip
// i=7: arr[7]=5, arr[3]=4 → diff, unique=4, arr[4]=5

// Result: [1, 2, 3, 4, 5, _, _, _], return 5
```

---

## Problem 10: Palindrome Check

**Input:** `"racecar"`

**Task:** Write function (both iterative and recursive)

**Your code:**
```cpp
// Iterative
bool isPalindromeIter(char str[], int n) {
    // YOUR CODE
}

// Recursive
bool isPalindromeRec(char str[], int left, int right) {
    // YOUR CODE
}
```

**Answers:**
```cpp
// Iterative
bool isPalindromeIter(char str[], int n) {
    int left = 0, right = n - 1;
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Recursive
bool isPalindromeRec(char str[], int left, int right) {
    if(left >= right) return true;  // Base: crossed or met
    if(str[left] != str[right]) return false;
    return isPalindromeRec(str, left + 1, right - 1);
}

// Call: isPalindromeRec(str, 0, strlen(str)-1)
```

---

# DRILL SET 5: DYNAMIC MEMORY (30 min)

## Problem 11: 2D Array Allocation

**Task:** Write code to allocate 3×4 matrix, initialize to 0, then deallocate

**Your code:**
```cpp
int main() {
    int rows = 3, cols = 4;
    
    // ALLOCATE
    
    // INITIALIZE
    
    // DEALLOCATE
    
    return 0;
}
```

**Answer:**
```cpp
int main() {
    int rows = 3, cols = 4;
    
    // Allocate
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Initialize to 0
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Deallocate (reverse order!)
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];  // Delete columns first
    }
    delete[] matrix;  // Delete rows last
    
    return 0;
}
```

---

## Problem 12: Memory Leak Detection

**Code:**
```cpp
void processData(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    // Function ends
}

int main() {
    processData(100);
    processData(200);
    return 0;
}
```

**Questions:**
1. Is there a memory leak?
2. How much memory is leaked?
3. How to fix?

**Answers:**
```
1. YES - arr is never deleted

2. 100 ints + 200 ints = 300 * sizeof(int) = 1200 bytes (if int=4 bytes)

3. Fix:
void processData(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    delete[] arr;  // ADD THIS
}
```

---

# DRILL SET 6: MIXED CONCEPTS (60 min)

## Problem 13: Pell Numbers - All 3 Versions

**Task:** Write recursive, iterative, and memoized versions

**Formula:** P(0)=0, P(1)=1, P(n) = 2*P(n-1) + P(n-2)

**Your code (all 3):**

**Answers:**
```cpp
// 1. Recursive
int pellRec(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return 2 * pellRec(n-1) + pellRec(n-2);
}

// 2. Iterative
int pellIter(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int prev2 = 0, prev1 = 1, curr;
    for(int i = 2; i <= n; i++) {
        curr = 2 * prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// 3. Memoized
int memo[100];
int pellMemo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];
    
    memo[n] = 2 * pellMemo(n-1) + pellMemo(n-2);
    return memo[n];
}
// Initialize: for(int i=0; i<100; i++) memo[i] = -1;
```

---

## Problem 14: Diagonal Sum

**Task:** Find sum of main diagonal and anti-diagonal

**Matrix:**
```
1 2 3
4 5 6
7 8 9
```

**Your code:**
```cpp
void diagonalSums(int arr[][3], int n) {
    // YOUR CODE
}
```

**Answer:**
```cpp
void diagonalSums(int arr[][3], int n) {
    int mainSum = 0, antiSum = 0;
    
    for(int i = 0; i < n; i++) {
        mainSum += arr[i][i];           // Main diagonal
        antiSum += arr[i][n-1-i];       // Anti-diagonal
    }
    
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Anti-diagonal sum: " << antiSum << endl;
}

// For given matrix:
// Main: 1 + 5 + 9 = 15
// Anti: 3 + 5 + 7 = 15
```

---

## Problem 15: Reverse Array Recursively

**Task:** Reverse array using recursion

**Input:** `[1, 2, 3, 4, 5]`

**Your code:**
```cpp
void reverseRec(int arr[], int left, int right) {
    // YOUR CODE
}
```

**Answer:**
```cpp
void reverseRec(int arr[], int left, int right) {
    if(left >= right) return;  // Base case
    
    // Swap left and right
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    
    // Recurse on inner elements
    reverseRec(arr, left + 1, right - 1);
}

// Call: reverseRec(arr, 0, n-1);

// Trace for [1,2,3,4,5]:
// Call 1: swap arr[0]<->arr[4] → [5,2,3,4,1], recurse(1, 3)
// Call 2: swap arr[1]<->arr[3] → [5,4,3,2,1], recurse(2, 2)
// Call 3: left==right, return
// Result: [5,4,3,2,1]
```

---

# ⏱️ PRACTICE SCHEDULE

## Use These During Study Sessions

**Session 1 (8:30-9:30 AM):**
- Drill Set 2: All matrix operations
- Write code on paper, trace by hand

**Session 2 (9:30-10:00 AM):**
- Drill Set 4: Famous algorithms
- Do remove duplicates & palindrome from memory

**Session 3 (10:30-11:00 AM):**
- Drill Set 3: Recursion
- Draw recursion trees for Fibonacci & Pell

**Session 4 (11:00-11:30 AM):**
- Drill Set 1: Pointer tracing
- Focus on nullptr behaviors

**Session 5 (11:30-12:00 PM):**
- Drill Set 6: Mixed problems
- Time yourself: 10 min per problem

---

# ✅ SELF-CHECK

After each drill:
- [ ] Did you write code on paper (not just read)?
- [ ] Did you trace the algorithm step-by-step?
- [ ] Can you explain the logic out loud?
- [ ] Can you write it again from memory?

**If any answer is NO:** Redo that drill!

---

**PRACTICE = CONFIDENCE**

**NOW GO DRILL!** 💪
