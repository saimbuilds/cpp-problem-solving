# 🧠 ULTIMATE CRAMABLE CHEAT SHEET 🧠
## Every Pattern You Need to Memorize

> **Purpose:** Cramable code patterns for exam  
> **Method:** Read → Trace → Write from memory  
> **Time:** Study this for 60 min tonight

---

# 📊 2D ARRAY OPERATIONS

## 1. TRANSPOSE (Swap Rows ↔ Columns)

### Pattern: In-Place Transpose (Square Matrix)
```cpp
void transpose(int arr[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {  // j = i+1 to avoid double swap
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}
```

**Key Points:**
- `j starts at i+1` (not 0) - only swap upper triangle
- Works only for square matrices (n×n)
- Changes array in-place

**Example:**
```
Input:          Output:
1 2 3           1 4 7
4 5 6     →     2 5 8
7 8 9           3 6 9
```

---

## 2. MATRIX ROTATION

### A. Rotate 90° Clockwise
**Pattern:** Transpose + Reverse Each Row
```cpp
void rotate90Clockwise(int arr[][MAX], int n) {
    // Step 1: Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while(left < right) {
            swap(arr[i][left], arr[i][right]);
            left++;
            right--;
        }
    }
}
```

**Example:**
```
Input:          Transpose:      Reverse Rows:
1 2 3           1 4 7           7 4 1
4 5 6     →     2 5 8     →     8 5 2
7 8 9           3 6 9           9 6 3
```

---

### B. Rotate 90° Counter-Clockwise
**Pattern:** Transpose + Reverse Each Column
```cpp
void rotate90CounterClockwise(int arr[][MAX], int n) {
    // Step 1: Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    // Step 2: Reverse each column
    for(int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while(top < bottom) {
            swap(arr[top][j], arr[bottom][j]);
            top++;
            bottom--;
        }
    }
}
```

---

### C. Rotate 180°
**Pattern:** Reverse All Rows + Reverse Each Row
```cpp
void rotate180(int arr[][MAX], int n) {
    // Reverse the order of rows
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n; j++) {
            swap(arr[i][j], arr[n-1-i][j]);
        }
    }
    
    // Reverse each row
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while(left < right) {
            swap(arr[i][left], arr[i][right]);
            left++;
            right--;
        }
    }
}
```

---

## 3. DIAGONAL TRAVERSALS

### A. Main Diagonal (Top-Left to Bottom-Right)
```cpp
void printMainDiagonal(int arr[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i][i] << " ";  // Row index = Column index
    }
}
```

**Example:** `1 5 9` from:
```
1 2 3
4 5 6
7 8 9
```

---

### B. Anti-Diagonal (Top-Right to Bottom-Left)
```cpp
void printAntiDiagonal(int arr[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i][n-1-i] << " ";
    }
}
```

**Example:** `3 5 7` from above matrix

---

### C. All Diagonals (Row-wise)
**Pattern:** Start from first row, then first column
```cpp
void printAllDiagonals(int arr[][MAX], int rows, int cols) {
    // Diagonals starting from first row
    for(int start_col = 0; start_col < cols; start_col++) {
        int i = 0, j = start_col;
        while(i < rows && j < cols) {
            cout << arr[i][j] << " ";
            i++;
            j++;
        }
        cout << endl;
    }
    
    // Diagonals starting from first column (skip [0][0])
    for(int start_row = 1; start_row < rows; start_row++) {
        int i = start_row, j = 0;
        while(i < rows && j < cols) {
            cout << arr[i][j] << " ";
            i++;
            j++;
        }
        cout << endl;
    }
}
```

---

## 4. SPIRAL TRAVERSAL (Matrix)

**THE BIG ONE - HIGH PROBABILITY**

### 4-Boundary Algorithm
```cpp
void printSpiral(int arr[][MAX], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while(top <= bottom && left <= right) {
        // Print top row (left to right)
        for(int i = left; i <= right; i++) {
            cout << arr[top][i] << " ";
        }
        top++;
        
        // Print right column (top to bottom)
        for(int i = top; i <= bottom; i++) {
            cout << arr[i][right] << " ";
        }
        right--;
        
        // Print bottom row (right to left) - if still valid
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        
        // Print left column (bottom to top) - if still valid
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}
```

**Example:**
```
Matrix:          Spiral Output:
1  2  3  4       1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
5  6  7  8
9  10 11 12
13 14 15 16
```

**Tracing Tips:**
- Draw arrows showing direction
- Update boundaries after each side
- Check `top <= bottom` and `left <= right` before bottom/left traversals

---

## 5. MATRIX MULTIPLICATION

**Pattern:** Row × Column
```cpp
void multiply(int A[][MAX], int B[][MAX], int result[][MAX], 
              int r1, int c1, int r2, int c2) {
    // c1 must equal r2 for multiplication to work
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;  // Initialize
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

**Example:** A(2×3) × B(3×2) = C(2×2)
```
A =          B =          C =
1 2 3        1 4          22 28
4 5 6        2 5          49 64
             3 6

C[0][0] = 1*1 + 2*2 + 3*3 = 1+4+9 = 14  (WRONG - check calc)
C[0][0] = 1*1 + 2*2 + 3*3 = 14
Actually: C[0][0] = 1*1 + 2*2 + 3*3 = 1 + 4 + 9 = 14
```

**Key Formula:** `C[i][j] = Σ (A[i][k] * B[k][j])` for k = 0 to c1-1

---

# 🔁 1D ARRAY FAMOUS QUESTIONS

## 1. REVERSE ARRAY

### Two-Pointer Technique
```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while(left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
```

**Example:** `[1,2,3,4,5]` → `[5,4,3,2,1]`

---

## 2. REMOVE DUPLICATES

### A. From Sorted Array (In-Place)
```cpp
int removeDuplicates(int arr[], int n) {
    if(n == 0) return 0;
    
    int unique_index = 0;  // Index for unique elements
    
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[unique_index]) {
            unique_index++;
            arr[unique_index] = arr[i];
        }
    }
    
    return unique_index + 1;  // New length
}
```

**Example:** `[1,1,2,2,3]` → `[1,2,3,_,_]` returns 3

---

### B. From Unsorted Array
```cpp
int removeDuplicatesUnsorted(int arr[], int n) {
    int unique_count = 0;
    
    for(int i = 0; i < n; i++) {
        bool isDuplicate = false;
        
        // Check if already exists in unique part
        for(int j = 0; j < unique_count; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        
        if(!isDuplicate) {
            arr[unique_count] = arr[i];
            unique_count++;
        }
    }
    
    return unique_count;
}
```

---

## 3. PALINDROME CHECK

### String/Array Version
```cpp
bool isPalindrome(char str[], int n) {
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
```

**Example:** `"racecar"` → true, `"hello"` → false

---

## 4. PELL NUMBERS

**Definition:** P(0)=0, P(1)=1, P(n) = 2*P(n-1) + P(n-2)  
**Sequence:** 0, 1, 2, 5, 12, 29, 70...

### A. Recursive
```cpp
int pell(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return 2 * pell(n-1) + pell(n-2);
}
```

---

### B. Iterative (More Efficient)
```cpp
int pellIterative(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int prev2 = 0, prev1 = 1;
    int current;
    
    for(int i = 2; i <= n; i++) {
        current = 2 * prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
```

---

### C. With Memoization (DP)
```cpp
int memo[100];

int pellMemo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];  // Already computed
    
    memo[n] = 2 * pellMemo(n-1) + pellMemo(n-2);
    return memo[n];
}

// Initialize: for(int i=0; i<100; i++) memo[i] = -1;
```

---

## 5. FIBONACCI VARIATIONS

### A. Standard Recursive
```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Sequence:** 0, 1, 1, 2, 3, 5, 8, 13, 21...

---

### B. Iterative
```cpp
int fibIterative(int n) {
    if(n <= 1) return n;
    
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```

---

### C. Print Series
```cpp
void printFibSeries(int n) {
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    
    for(int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}
```

---

# 🔄 RECURSION PATTERNS

## Pattern 1: Single Base Case

### Factorial
```cpp
int factorial(int n) {
    if(n == 0 || n == 1) return 1;  // Base case
    return n * factorial(n - 1);    // Recursive case
}
```

---

### Sum of N Natural Numbers
```cpp
int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}
```

---

## Pattern 2: Multiple Base Cases

### Fibonacci
```cpp
int fib(int n) {
    if(n == 0) return 0;  // Base 1
    if(n == 1) return 1;  // Base 2
    return fib(n-1) + fib(n-2);
}
```

---

## Pattern 3: Array Recursion

### Sum of Array
```cpp
int arraySum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n-1] + arraySum(arr, n-1);
}
```

---

### Find Max in Array
```cpp
int findMax(int arr[], int n) {
    if(n == 1) return arr[0];
    
    int maxRest = findMax(arr, n-1);
    return (arr[n-1] > maxRest) ? arr[n-1] : maxRest;
}
```

---

## Pattern 4: Pointer/Reference Recursion

### With Reference (Modify Original)
```cpp
void doubleValues(int arr[], int n, int index = 0) {
    if(index == n) return;  // Base case
    arr[index] *= 2;
    doubleValues(arr, n, index + 1);
}
```

---

### With Pointer
```cpp
void incrementByPointer(int* p, int n) {
    if(n == 0) return;
    (*p)++;  // Increment value at pointer
    incrementByPointer(p + 1, n - 1);  // Move to next
}
```

---

## Pattern 5: Binary Recursion

### Power Calculation (a^n)
```cpp
int power(int a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    
    // Optimize: a^n = (a^(n/2))^2 if n is even
    if(n % 2 == 0) {
        int half = power(a, n/2);
        return half * half;
    }
    return a * power(a, n-1);
}
```

---

### GCD (Greatest Common Divisor)
**Euclidean Algorithm**
```cpp
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
```

**Example:** `gcd(48, 18)` = 6

---

## Pattern 6: Tower of Hanoi Logic

**DON'T memorize full code, just the logic:**

- **Base:** If 1 disk, move directly from source to destination
- **Recursive:**
  1. Move n-1 disks from source to auxiliary (using dest)
  2. Move largest disk from source to destination
  3. Move n-1 disks from auxiliary to destination (using source)

**Function calls:** Moves = 2^n - 1

---

# 📝 PATTERN PRINTING

## Pattern 1: Right Triangle
```cpp
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
```
Output (n=4):
```
*
* *
* * *
* * * *
```

---

## Pattern 2: Inverted Right Triangle
```cpp
for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

---

## Pattern 3: Number Pyramid
```cpp
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
        cout << j << " ";
    }
    cout << endl;
}
```
Output (n=4):
```
1
1 2
1 2 3
1 2 3 4
```

---

## Pattern 4: Diamond
```cpp
// Upper half
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n-i; j++) cout << " ";
    for(int j = 1; j <= 2*i-1; j++) cout << "*";
    cout << endl;
}

// Lower half
for(int i = n-1; i >= 1; i--) {
    for(int j = 1; j <= n-i; j++) cout << " ";
    for(int j = 1; j <= 2*i-1; j++) cout << "*";
    cout << endl;
}
```

---

# 🎯 POINTER CHEAT CODES

## Decision Tree: When to Use What

### Single Pointer (`int*`)
**Use when:**
- Need to modify a single variable through function
- Allocating 1D dynamic array
- Passing array to function

```cpp
int* p = new int;      // Single int
int* arr = new int[n]; // 1D array
```

---

### Double Pointer (`int**`)
**Use when:**
- 2D dynamic array
- Pointer to pointer (modify pointer itself)

```cpp
int** matrix = new int*[rows];
for(int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
}
```

---

### Triple Pointer (`int***`)
**Use when:**
- 3D dynamic array (rare in basic exams)

```cpp
int*** cube = new int**[x];
for(int i = 0; i < x; i++) {
    cube[i] = new int*[y];
    for(int j = 0; j < y; j++) {
        cube[i][j] = new int[z];
    }
}
```

---

## Reference vs Pointer

| Feature | Reference (`int&`) | Pointer (`int*`) |
|---------|-------------------|------------------|
| Reassignable | ❌ No | ✅ Yes |
| Must Initialize | ✅ Yes | ❌ No |
| Null Value | ❌ No | ✅ Yes (nullptr) |
| Syntax | `var` | `*var` |
| Address | `&var` (implicit) | `var` |

**Example:**
```cpp
void foo(int*& ref) { }   // Reference to pointer
void bar(int*&& ref) { }  // Rvalue reference to pointer (C++11)
```

---

## Nullptr Casting

```cpp
cout << (char*)nullptr << endl;   // Prints: (nothing)
cout << (int*)23 << endl;         // Prints: 0000000000000017 (address as hex)
```

**Why?** 
- `char*` expects C-string, nullptr = empty
- `int*` prints as address

---

# 🚨 EXAM TRACING PATTERNS

## Pattern: Track Everything

### Example Code:
```cpp
void foo(int*& ref) { }
void bar(int*&& ref) { }

int main() {
    foo(nullptr);  // What happens?
    bar(nullptr);
}
```

**Tracing Table:**
| Line | Variable | Value | Notes |
|------|----------|-------|-------|
| 5 | `nullptr` | 0x0 | Null pointer |
| 5 | Error? | ❌ Can't bind non-const lvalue ref to rvalue | `int*&` needs lvalue |
| 6 | OK | ✅ Rvalue reference accepts temporary | `int*&&` works |

---

## Common Nullptr Behaviors

```cpp
int* p = nullptr;
foo(p);              // OK if foo(int*&)

int* p = nullptr;
foo(nullptr);        // ERROR if foo(int*&) - can't bind to rvalue
```

**Solution:** Make parameter `const int*&` or use rvalue ref `int*&&`

---

# 💾 DYNAMIC MEMORY PATTERNS

## 1D Array
``cpp
int* arr = new int[n];
// Use arr[i]
delete[] arr;  // MUST use delete[]
```

## 2D Array
```cpp
int** matrix = new int*[rows];
for(int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
}

// DEALLOCATION (reverse order!)
for(int i = 0; i < rows; i++) {
    delete[] matrix[i];  // Delete columns first
}
delete[] matrix;  // Delete rows last
```

---

## Deallocation Order Rule
**Always delete in REVERSE of allocation order!**

Allocation: rows → columns  
Deallocation: columns → rows

---

# ✅ QUICK SYNTAX CHECKS

## Loop Bounds (Common Traps)
```cpp
for(int i = 0; i < n; i++)    // 0 to n-1 (n elements)
for(int i = 0; i <= n; i++)   // 0 to n (n+1 elements) - CAREFUL!
for(int i = 1; i <= n; i++)   // 1 to n (n elements)
```

## Array Index Last Element
```cpp
int arr[n];
arr[n-1]  // Last element (NOT arr[n])
```

## String Length
```cpp
char str[] = "hello";  // Length = 5, but str[5] = '\0'
```

---

**END OF ULTIMATE CHEAT SHEET**

**NOW:** Practice writing 3 patterns from memory!
