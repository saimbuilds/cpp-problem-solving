# 🎯 DAY 1: ARRAYS & FUNCTIONS/RECURSION MASTERY
## 10-Hour Intensive Roadmap for FAST NUCES Finals

**Target:** Become Top of Batch  
**Timeline:** 10 Hours (Today)  
**Focus:** 1D Arrays, 2D Arrays, Multi-D Arrays, Functions, Recursion  
**Restrictions:** NO Pointers, NO Pointer-based Multi-dimensional Arrays

---

## 📋 TABLE OF CONTENTS
1. [Hour 1-2: 1D Arrays - Deep Dive](#hour-1-2-1d-arrays)
2. [Hour 3-4: 2D Arrays - Matrix Mastery](#hour-3-4-2d-arrays)
3. [Hour 4.5-5: Multi-Dimensional Arrays](#hour-45-5-multi-d-arrays)
4. [Hour 5.5-7: Functions - Complete Guide](#hour-55-7-functions)
5. [Hour 7.5-9.5: Recursion - Mind Bending](#hour-75-95-recursion)
6. [Hour 9.5-10: Integration & Hard Problems](#hour-95-10-integration)

---

# HOUR 1-2: 1D ARRAYS - DEEP DIVE

## 🧠 Core Concepts

### What is an Array?
- **Definition:** Contiguous memory block storing elements of same data type
- **Memory Layout:** Elements stored sequentially in RAM
- **Index:** 0-based indexing (first element at index 0)

### Declaration & Initialization

```cpp
// Method 1: Declaration with size
int arr[5];  // Uninitialized (garbage values)

// Method 2: Declaration with initialization
int arr[5] = {1, 2, 3, 4, 5};

// Method 3: Partial initialization
int arr[5] = {1, 2};  // {1, 2, 0, 0, 0} - rest are 0

// Method 4: Size inference
int arr[] = {1, 2, 3, 4, 5};  // Size = 5 (compiler calculates)

// Method 5: Zero initialization
int arr[100] = {0};  // All elements = 0

// Method 6: Character arrays (strings)
char name[20] = "FAST";  // {'F', 'A', 'S', 'T', '\0', ...}
```

### Memory Calculation
```cpp
int arr[10];
// Size in bytes = 10 * sizeof(int) = 10 * 4 = 40 bytes
// Address of arr[i] = base_address + (i * sizeof(int))
```

---

## 🔥 TRICKS & TIPS - DIMENSION INDEPENDENT

### Trick 1: Finding Array Size
```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);
// sizeof(arr) = total bytes
// sizeof(arr[0]) = bytes per element
```

### Trick 2: Reverse Traversal
```cpp
// Forward
for(int i = 0; i < n; i++) { }

// Backward
for(int i = n-1; i >= 0; i--) { }
```

### Trick 3: Two-Pointer Technique
```cpp
int left = 0, right = n - 1;
while(left < right) {
    // Process arr[left] and arr[right]
    left++;
    right--;
}
```

### Trick 4: Sliding Window
```cpp
// Fixed window of size k
for(int i = 0; i <= n - k; i++) {
    // Window: arr[i] to arr[i+k-1]
}
```

### Trick 5: Prefix Sum (CRITICAL!)
```cpp
int prefix[n];
prefix[0] = arr[0];
for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
// Sum from index L to R = prefix[R] - prefix[L-1]
```

### Trick 6: Frequency Array
```cpp
int freq[1001] = {0};  // For values 0-1000
for(int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
```

### Trick 7: Kadane's Algorithm (Maximum Subarray Sum)
```cpp
int maxSum = arr[0], currentSum = arr[0];
for(int i = 1; i < n; i++) {
    currentSum = max(arr[i], currentSum + arr[i]);
    maxSum = max(maxSum, currentSum);
}
```

---

## 💪 PRACTICE PROBLEMS - 1D ARRAYS

### Level 1: Warm-up (15 mins)

**Q1.1:** Write a program to find the second largest element in an array.
```cpp
// Input: {12, 35, 1, 10, 34, 1}
// Output: 34
```

**Q1.2:** Rotate array to the right by k positions.
```cpp
// Input: {1, 2, 3, 4, 5}, k = 2
// Output: {4, 5, 1, 2, 3}
```

**Q1.3:** Remove duplicates from sorted array (in-place).
```cpp
// Input: {1, 1, 2, 2, 3, 4, 4}
// Output: {1, 2, 3, 4} (return new length)
```

### Level 2: Intermediate (30 mins)

**Q2.1:** Find all pairs in array that sum to a target value.
```cpp
// Input: {1, 5, 7, -1, 5}, target = 6
// Output: (1, 5), (7, -1), (1, 5)
```

**Q2.2:** Find the longest consecutive sequence.
```cpp
// Input: {100, 4, 200, 1, 3, 2}
// Output: 4 (sequence: 1, 2, 3, 4)
```

**Q2.3:** Rearrange array: negatives on left, positives on right (maintain order).
```cpp
// Input: {-12, 11, -13, -5, 6, -7, 5}
// Output: {-12, -13, -5, -7, 11, 6, 5}
```

### Level 3: Advanced (45 mins)

**Q3.1:** Find the maximum product of three numbers.
```cpp
// Input: {-10, -10, 5, 2}
// Output: 500 (-10 * -10 * 5)
```

**Q3.2:** Trapping Rain Water
```cpp
// Input: {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
// Output: 6 units of water trapped
```

**Q3.3:** Stock Buy-Sell to Maximize Profit (Multiple Transactions)
```cpp
// Input: {7, 1, 5, 3, 6, 4}
// Output: 7 (buy at 1, sell at 5, buy at 3, sell at 6)
```

---

# HOUR 3-4: 2D ARRAYS - MATRIX MASTERY

## 🧠 Core Concepts

### Declaration & Initialization

```cpp
// Method 1: Static declaration
int matrix[3][4];  // 3 rows, 4 columns

// Method 2: With initialization
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Method 3: Partial initialization
int matrix[3][3] = {{1, 2}, {3}};
// Result:
// 1 2 0
// 3 0 0
// 0 0 0

// Method 4: Row-major order
int matrix[2][3] = {1, 2, 3, 4, 5, 6};
// Result:
// 1 2 3
// 4 5 6
```

### Memory Layout (Row-Major Order)
```
matrix[3][4] in memory:
[0][0] [0][1] [0][2] [0][3] [1][0] [1][1] [1][2] [1][3] [2][0] [2][1] [2][2] [2][3]

Address of matrix[i][j] = base + (i * cols + j) * sizeof(datatype)
```

---

## 🔥 TRICKS & TIPS - 2D ARRAYS

### Trick 1: Traversal Patterns

```cpp
// Row-wise traversal
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cout << matrix[i][j] << " ";
    }
}

// Column-wise traversal
for(int j = 0; j < cols; j++) {
    for(int i = 0; i < rows; i++) {
        cout << matrix[i][j] << " ";
    }
}

// Diagonal traversal (main diagonal)
for(int i = 0; i < n; i++) {
    cout << matrix[i][i] << " ";
}

// Anti-diagonal
for(int i = 0; i < n; i++) {
    cout << matrix[i][n-1-i] << " ";
}

// Spiral traversal (IMPORTANT!)
int top = 0, bottom = rows-1, left = 0, right = cols-1;
while(top <= bottom && left <= right) {
    // Right
    for(int i = left; i <= right; i++) cout << matrix[top][i] << " ";
    top++;
    
    // Down
    for(int i = top; i <= bottom; i++) cout << matrix[i][right] << " ";
    right--;
    
    // Left
    if(top <= bottom) {
        for(int i = right; i >= left; i--) cout << matrix[bottom][i] << " ";
        bottom--;
    }
    
    // Up
    if(left <= right) {
        for(int i = bottom; i >= top; i--) cout << matrix[i][left] << " ";
        left++;
    }
}
```

### Trick 2: Matrix Rotation (90° Clockwise)
```cpp
// Step 1: Transpose
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}

// Step 2: Reverse each row
for(int i = 0; i < n; i++) {
    reverse(matrix[i], matrix[i] + n);
}
```

### Trick 3: Boundary Elements
```cpp
// First row: matrix[0][j] where j = 0 to cols-1
// Last row: matrix[rows-1][j] where j = 0 to cols-1
// First col: matrix[i][0] where i = 0 to rows-1
// Last col: matrix[i][cols-1] where i = 0 to rows-1
```

### Trick 4: 4-Directional Movement
```cpp
int dx[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
int dy[] = {0, 0, -1, 1};

for(int dir = 0; dir < 4; dir++) {
    int newX = x + dx[dir];
    int newY = y + dy[dir];
    
    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
        // Valid neighbor
    }
}
```

### Trick 5: 8-Directional Movement
```cpp
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

### Trick 6: Wave Pattern
```cpp
// Column-wise wave
for(int j = 0; j < cols; j++) {
    if(j % 2 == 0) {
        for(int i = 0; i < rows; i++) cout << matrix[i][j] << " ";
    } else {
        for(int i = rows-1; i >= 0; i--) cout << matrix[i][j] << " ";
    }
}
```

---

## 💪 PRACTICE PROBLEMS - 2D ARRAYS

### Level 1: Warm-up (20 mins)

**Q1.1:** Find the sum of all boundary elements.
```cpp
// Input:
// 1 2 3
// 4 5 6
// 7 8 9
// Output: 1+2+3+6+9+8+7+4 = 40
```

**Q1.2:** Search for an element in a row-wise and column-wise sorted matrix.
```cpp
// Input:
// 10 20 30
// 15 25 35
// 27 29 37
// Target: 25
// Output: Found at (1, 1)
```

**Q1.3:** Transpose a matrix (in-place for square matrix).

### Level 2: Intermediate (40 mins)

**Q2.1:** Rotate matrix 90° counterclockwise.

**Q2.2:** Print matrix in spiral order.
```cpp
// Input:
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// Output: 1 2 3 4 8 12 11 10 9 5 6 7
```

**Q2.3:** Find the row with maximum number of 1s (matrix contains only 0s and 1s, each row is sorted).
```cpp
// Input:
// 0 0 1 1
// 0 1 1 1
// 0 0 0 1
// Output: Row 1 (has 3 ones)
```

### Level 3: Advanced (60 mins)

**Q3.1:** Set Matrix Zeroes
```cpp
// If matrix[i][j] = 0, set entire row i and column j to 0
// Do it in-place with O(1) extra space
// Input:
// 1 1 1
// 1 0 1
// 1 1 1
// Output:
// 1 0 1
// 0 0 0
// 1 0 1
```

**Q3.2:** Find the median in a row-wise sorted matrix.
```cpp
// Input:
// 1 3 5
// 2 6 9
// 3 6 9
// Output: 5
```

**Q3.3:** Count all possible paths from top-left to bottom-right (can only move right or down).
```cpp
// For a 3x3 matrix, output: 6 paths
```

---

# HOUR 4.5-5: MULTI-DIMENSIONAL ARRAYS

## 🧠 Core Concepts

### 3D Arrays
```cpp
// Declaration
int arr[2][3][4];  // 2 blocks, 3 rows, 4 columns

// Initialization
int arr[2][2][3] = {
    {
        {1, 2, 3},
        {4, 5, 6}
    },
    {
        {7, 8, 9},
        {10, 11, 12}
    }
};

// Accessing: arr[block][row][col]
cout << arr[0][1][2];  // Output: 6
```

### Visualization
```
Think of 3D array as:
- Multiple 2D matrices stacked together
- arr[i] = ith 2D matrix
- arr[i][j] = jth row of ith matrix
- arr[i][j][k] = kth element of jth row of ith matrix
```

### Memory Calculation
```cpp
int arr[2][3][4];
// Total elements = 2 * 3 * 4 = 24
// Total bytes = 24 * sizeof(int) = 96 bytes
// Address of arr[i][j][k] = base + ((i*3*4) + (j*4) + k) * sizeof(int)
```

---

## 🔥 UNIVERSAL TRICKS (Works for ANY Dimension!)

### Trick 1: Nested Loop Pattern
```cpp
// For N-dimensional array with sizes [d1][d2][d3]...[dN]
// Use N nested loops

// 1D: 1 loop
for(int i = 0; i < d1; i++) { }

// 2D: 2 loops
for(int i = 0; i < d1; i++) {
    for(int j = 0; j < d2; j++) { }
}

// 3D: 3 loops
for(int i = 0; i < d1; i++) {
    for(int j = 0; j < d2; j++) {
        for(int k = 0; k < d3; k++) { }
    }
}
```

### Trick 2: Dimension Reduction
```cpp
// To process N-D array, fix one dimension and work with (N-1)-D array

// Example: Sum all elements in 3D array
int sum = 0;
for(int i = 0; i < d1; i++) {
    // Now arr[i] is a 2D array
    for(int j = 0; j < d2; j++) {
        // Now arr[i][j] is a 1D array
        for(int k = 0; k < d3; k++) {
            sum += arr[i][j][k];
        }
    }
}
```

### Trick 3: Sizeof Trick (Universal)
```cpp
// Works for any dimension!
int arr[...];  // Any dimensional array
int totalElements = sizeof(arr) / sizeof(arr[0][0]...);  // Divide by base element
```

### Trick 4: Initialization Pattern
```cpp
// Zero initialization works for ANY dimension
int arr1D[100] = {0};
int arr2D[10][10] = {0};
int arr3D[5][5][5] = {0};
int arr4D[3][3][3][3] = {0};
```

---

## 💪 PRACTICE PROBLEMS - MULTI-D ARRAYS

### Level 1: 3D Arrays (20 mins)

**Q1.1:** Find the sum of all elements in a 3D array.

**Q1.2:** Find maximum element in a 3D array.

**Q1.3:** Count how many elements are greater than a given value in 3D array.

### Level 2: Advanced (30 mins)

**Q2.1:** Flatten a 3D array into 1D array.
```cpp
// Input: arr[2][2][2] = {{{1,2},{3,4}}, {{5,6},{7,8}}}
// Output: {1, 2, 3, 4, 5, 6, 7, 8}
```

**Q2.2:** Find the sum of each 2D matrix in a 3D array.
```cpp
// Input: arr[2][2][2]
// Output: Sum of arr[0][][] and arr[1][][]
```

---

# HOUR 5.5-7: FUNCTIONS - COMPLETE GUIDE

## 🧠 Core Concepts

### Function Anatomy
```cpp
return_type function_name(parameter_list) {
    // Function body
    return value;  // If return_type is not void
}
```

### Types of Functions

#### 1. No Parameters, No Return
```cpp
void greet() {
    cout << "Hello, FAST!" << endl;
}
```

#### 2. With Parameters, No Return
```cpp
void printSum(int a, int b) {
    cout << a + b << endl;
}
```

#### 3. No Parameters, With Return
```cpp
int getRandom() {
    return rand() % 100;
}
```

#### 4. With Parameters, With Return
```cpp
int add(int a, int b) {
    return a + b;
}
```

---

## 🔥 PARAMETER PASSING TECHNIQUES

### 1. Pass by Value
```cpp
void modify(int x) {
    x = 100;  // Changes local copy only
}

int main() {
    int num = 5;
    modify(num);
    cout << num;  // Output: 5 (unchanged)
}
```

### 2. Pass by Reference (using &)
```cpp
void modify(int &x) {
    x = 100;  // Changes original variable
}

int main() {
    int num = 5;
    modify(num);
    cout << num;  // Output: 100 (changed!)
}
```

### 3. Passing Arrays (CRITICAL!)
```cpp
// Arrays are ALWAYS passed by reference (address of first element)

// 1D Array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// 2D Array - MUST specify column size
void print2D(int arr[][4], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
    }
}

// Alternative: Using reference
void print2D_ref(int (&arr)[3][4]) {
    // Both dimensions fixed at compile time
}
```

### 4. Const Parameters (Prevent Modification)
```cpp
void display(const int arr[], int size) {
    // arr[0] = 10;  // ERROR! Cannot modify
    cout << arr[0];  // OK to read
}
```

---

## 🔥 ADVANCED FUNCTION CONCEPTS

### Function Overloading
```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

// Compiler chooses based on arguments
add(5, 10);        // Calls first
add(5.5, 10.2);    // Calls second
add(1, 2, 3);      // Calls third
```

### Default Parameters
```cpp
int power(int base, int exp = 2) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

power(5);      // 5^2 = 25
power(5, 3);   // 5^3 = 125
```

### Inline Functions
```cpp
inline int square(int x) {
    return x * x;
}
// Compiler replaces function call with actual code (faster for small functions)
```

---

## 🔥 FUNCTION TRICKS FOR ARRAYS

### Trick 1: Returning Multiple Values (using reference parameters)
```cpp
void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = maxVal = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal) minVal = arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
}

// Usage
int min, max;
findMinMax(arr, n, min, max);
```

### Trick 2: Function Returning Array Size
```cpp
template<size_t N>
int getSize(int (&arr)[N]) {
    return N;
}

int arr[] = {1, 2, 3, 4, 5};
cout << getSize(arr);  // Output: 5
```

### Trick 3: Generic Array Processing
```cpp
void processArray(int arr[], int size, int (*operation)(int)) {
    for(int i = 0; i < size; i++) {
        arr[i] = operation(arr[i]);
    }
}

int doubleValue(int x) { return x * 2; }
int square(int x) { return x * x; }

processArray(arr, n, doubleValue);  // Doubles all elements
processArray(arr, n, square);       // Squares all elements
```

---

## 💪 PRACTICE PROBLEMS - FUNCTIONS

### Level 1: Basic (20 mins)

**Q1.1:** Write a function to check if a number is prime.

**Q1.2:** Write a function to reverse an array in-place.

**Q1.3:** Write a function to find GCD of two numbers.

### Level 2: Intermediate (30 mins)

**Q2.1:** Write a function to merge two sorted arrays into a third sorted array.

**Q2.2:** Write a function to check if a matrix is symmetric.

**Q2.3:** Write overloaded functions to find maximum of 2, 3, and 4 numbers.

### Level 3: Advanced (40 mins)

**Q3.1:** Write a function to perform matrix multiplication.
```cpp
void multiply(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int c2);
```

**Q3.2:** Write a function to generate Pascal's Triangle up to n rows.

**Q3.3:** Write a function to check if a Sudoku board is valid.

---

# HOUR 7.5-9.5: RECURSION - MIND BENDING

## 🧠 Core Concepts

### What is Recursion?
- A function that calls itself
- Must have a **base case** (stopping condition)
- Must have a **recursive case** (progress toward base case)

### Recursion Anatomy
```cpp
return_type function(parameters) {
    // Base case
    if(stopping_condition) {
        return base_value;
    }
    
    // Recursive case
    return function(modified_parameters);
}
```

### Simple Example: Factorial
```cpp
int factorial(int n) {
    // Base case
    if(n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

// factorial(5) = 5 * factorial(4)
//              = 5 * 4 * factorial(3)
//              = 5 * 4 * 3 * factorial(2)
//              = 5 * 4 * 3 * 2 * factorial(1)
//              = 5 * 4 * 3 * 2 * 1
//              = 120
```

---

## 🔥 RECURSION PATTERNS

### Pattern 1: Linear Recursion
```cpp
// Sum of first n natural numbers
int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}
```

### Pattern 2: Binary Recursion
```cpp
// Fibonacci
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Two recursive calls
}
```

### Pattern 3: Tail Recursion (Optimizable)
```cpp
// Last operation is recursive call
int factorial(int n, int result = 1) {
    if(n == 0) return result;
    return factorial(n - 1, n * result);
}
```

### Pattern 4: Head Recursion
```cpp
// Recursive call is first operation
void print(int n) {
    if(n == 0) return;
    print(n - 1);
    cout << n << " ";  // Prints: 1 2 3 4 5
}
```

### Pattern 5: Tree Recursion
```cpp
// Multiple recursive calls creating tree structure
void generateSubsets(int arr[], int n, int index, int current[], int currSize) {
    if(index == n) {
        printArray(current, currSize);
        return;
    }
    
    // Exclude current element
    generateSubsets(arr, n, index+1, current, currSize);
    
    // Include current element
    current[currSize] = arr[index];
    generateSubsets(arr, n, index+1, current, currSize+1);
}
```

---

## 🔥 RECURSION WITH ARRAYS

### Example 1: Sum of Array
```cpp
int arraySum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n-1] + arraySum(arr, n-1);
}
```

### Example 2: Check if Sorted
```cpp
bool isSorted(int arr[], int n) {
    if(n == 1) return true;
    return (arr[n-1] >= arr[n-2]) && isSorted(arr, n-1);
}
```

### Example 3: Binary Search (Recursive)
```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if(left > right) return -1;  // Not found
    
    int mid = left + (right - left) / 2;
    
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return binarySearch(arr, left, mid-1, target);
    return binarySearch(arr, mid+1, right, target);
}
```

### Example 4: Reverse Array
```cpp
void reverseArray(int arr[], int start, int end) {
    if(start >= end) return;
    
    swap(arr[start], arr[end]);
    reverseArray(arr, start+1, end-1);
}
```

### Example 5: Print All Permutations
```cpp
void permute(int arr[], int start, int end) {
    if(start == end) {
        printArray(arr, end+1);
        return;
    }
    
    for(int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        permute(arr, start+1, end);
        swap(arr[start], arr[i]);  // Backtrack
    }
}
```

---

## 🔥 RECURSION TRICKS & OPTIMIZATION

### Trick 1: Memoization (Dynamic Programming)
```cpp
int memo[100];

int fib(int n) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];  // Already calculated
    
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

// Initialize: fill(memo, memo+100, -1);
```

### Trick 2: Recursion Tree Visualization
```
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1) → 1
│   │   │   └── fib(0) → 0
│   │   └── fib(1) → 1
│   └── fib(2)
│       ├── fib(1) → 1
│       └── fib(0) → 0
└── fib(3)
    ├── fib(2)
    │   ├── fib(1) → 1
    │   └── fib(0) → 0
    └── fib(1) → 1
```

### Trick 3: Converting Loop to Recursion
```cpp
// Loop version
int sum = 0;
for(int i = 1; i <= n; i++) {
    sum += i;
}

// Recursive version
int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n-1);
}
```

### Trick 4: Multiple Base Cases
```cpp
int fib(int n) {
    if(n == 0) return 0;  // Base case 1
    if(n == 1) return 1;  // Base case 2
    return fib(n-1) + fib(n-2);
}
```

---

## 💪 PRACTICE PROBLEMS - RECURSION

### Level 1: Basic (25 mins)

**Q1.1:** Write a recursive function to calculate x^n.

**Q1.2:** Write a recursive function to print numbers from 1 to n.

**Q1.3:** Write a recursive function to find the sum of digits of a number.
```cpp
// Input: 1234
// Output: 10
```

**Q1.4:** Write a recursive function to check if a string is palindrome.

### Level 2: Intermediate (40 mins)

**Q2.1:** Tower of Hanoi
```cpp
// Move n disks from source to destination using auxiliary peg
void towerOfHanoi(int n, char source, char dest, char aux);
```

**Q2.2:** Generate all binary strings of length n.
```cpp
// Input: n = 3
// Output: 000, 001, 010, 011, 100, 101, 110, 111
```

**Q2.3:** Find all subsets of an array (Power Set).
```cpp
// Input: {1, 2, 3}
// Output: {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
```

**Q2.4:** Recursive Bubble Sort

### Level 3: Advanced (55 mins)

**Q3.1:** N-Queens Problem
```cpp
// Place N queens on N×N chessboard such that no two queens attack each other
```

**Q3.2:** Rat in a Maze
```cpp
// Find path from (0,0) to (n-1,n-1) in a maze (1 = path, 0 = wall)
```

**Q3.3:** Sudoku Solver
```cpp
// Solve a 9×9 Sudoku puzzle using backtracking
```

**Q3.4:** Word Break Problem
```cpp
// Given a string and dictionary, check if string can be segmented into words
// Input: "leetcode", dict = {"leet", "code"}
// Output: true
```

**Q3.5:** Generate all valid parentheses combinations
```cpp
// Input: n = 3
// Output: ((())), (()()), (())(), ()(()), ()()()
```

---

# HOUR 9.5-10: INTEGRATION & HARD PROBLEMS

## 🔥 COMBINED CHALLENGES

### Problem 1: Matrix Path Sum (Recursion + 2D Array)
```cpp
// Find maximum path sum from top-left to bottom-right
// Can only move right or down
int maxPathSum(int matrix[][MAX], int i, int j, int rows, int cols) {
    if(i == rows-1 && j == cols-1) return matrix[i][j];
    if(i >= rows || j >= cols) return INT_MIN;
    
    int right = maxPathSum(matrix, i, j+1, rows, cols);
    int down = maxPathSum(matrix, i+1, j, rows, cols);
    
    return matrix[i][j] + max(right, down);
}
```

### Problem 2: Longest Increasing Subsequence (Recursion + Arrays)
```cpp
// Find length of longest increasing subsequence
int lis(int arr[], int n, int prev, int curr) {
    if(curr == n) return 0;
    
    int exclude = lis(arr, n, prev, curr+1);
    
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]) {
        include = 1 + lis(arr, n, curr, curr+1);
    }
    
    return max(include, exclude);
}
```

### Problem 3: Matrix Chain Multiplication
```cpp
// Find minimum number of multiplications needed
int matrixChain(int dims[], int i, int j) {
    if(i == j) return 0;
    
    int minOps = INT_MAX;
    for(int k = i; k < j; k++) {
        int ops = matrixChain(dims, i, k) +
                  matrixChain(dims, k+1, j) +
                  dims[i-1] * dims[k] * dims[j];
        minOps = min(minOps, ops);
    }
    return minOps;
}
```

### Problem 4: Flood Fill (Recursion + 2D Array)
```cpp
void floodFill(int image[][MAX], int sr, int sc, int newColor, int oldColor, int rows, int cols) {
    if(sr < 0 || sr >= rows || sc < 0 || sc >= cols) return;
    if(image[sr][sc] != oldColor) return;
    
    image[sr][sc] = newColor;
    
    floodFill(image, sr-1, sc, newColor, oldColor, rows, cols);  // Up
    floodFill(image, sr+1, sc, newColor, oldColor, rows, cols);  // Down
    floodFill(image, sr, sc-1, newColor, oldColor, rows, cols);  // Left
    floodFill(image, sr, sc+1, newColor, oldColor, rows, cols);  // Right
}
```

### Problem 5: Combination Sum
```cpp
// Find all combinations that sum to target
void combinationSum(int arr[], int n, int target, int current[], int currSize, int start) {
    if(target == 0) {
        printArray(current, currSize);
        return;
    }
    if(target < 0) return;
    
    for(int i = start; i < n; i++) {
        current[currSize] = arr[i];
        combinationSum(arr, n, target - arr[i], current, currSize+1, i);
    }
}
```

---

## 📚 FINAL TIPS FOR EXAM

### 1. Time Complexity Awareness
```
- Single loop: O(n)
- Nested loops: O(n²)
- Binary search: O(log n)
- Recursion: Analyze recursion tree
  - Linear: O(n)
  - Binary (like fib): O(2^n)
  - With memoization: O(n)
```

### 2. Common Mistakes to Avoid
- **Array out of bounds:** Always check `i < n`
- **Infinite recursion:** Always have base case
- **Integer overflow:** Use `long long` for large products
- **Uninitialized arrays:** Always initialize
- **Wrong array size in functions:** Pass size as parameter

### 3. Debugging Techniques
```cpp
// Print array for debugging
void debug(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Print recursion depth
void recursive(int n, int depth = 0) {
    cout << "Depth: " << depth << ", n: " << n << endl;
    if(n == 0) return;
    recursive(n-1, depth+1);
}
```

### 4. Quick Reference Card

```cpp
// Array declaration
int arr[SIZE];
int arr[ROWS][COLS];
int arr[D1][D2][D3];

// Array size
int size = sizeof(arr) / sizeof(arr[0]);

// Pass to function
void func(int arr[], int size);
void func(int arr[][COLS], int rows);

// Recursion template
returnType func(params) {
    if(baseCase) return baseValue;
    return recursiveCase;
}

// Common algorithms
- Binary Search: O(log n)
- Bubble Sort: O(n²)
- Merge Sort: O(n log n)
- Quick Sort: O(n log n) average
```

---

## 🎯 STUDY SCHEDULE BREAKDOWN

### Hour 1-2: 1D Arrays
- [ ] Read concepts (20 min)
- [ ] Practice Level 1 (15 min)
- [ ] Practice Level 2 (30 min)
- [ ] Practice Level 3 (45 min)
- [ ] Review (10 min)

### Hour 3-4: 2D Arrays
- [ ] Read concepts (20 min)
- [ ] Practice Level 1 (20 min)
- [ ] Practice Level 2 (40 min)
- [ ] Practice Level 3 (60 min)
- [ ] Review (20 min)

### Hour 4.5-5: Multi-D Arrays
- [ ] Read concepts (15 min)
- [ ] Practice problems (30 min)
- [ ] Review (5 min)

### Hour 5.5-7: Functions
- [ ] Read concepts (30 min)
- [ ] Practice Level 1 (20 min)
- [ ] Practice Level 2 (30 min)
- [ ] Practice Level 3 (40 min)

### Hour 7.5-9.5: Recursion
- [ ] Read concepts (30 min)
- [ ] Practice Level 1 (25 min)
- [ ] Practice Level 2 (40 min)
- [ ] Practice Level 3 (55 min)
- [ ] Review (10 min)

### Hour 9.5-10: Integration
- [ ] Solve combined problems (30 min)

---

## 🏆 FINAL MOTIVATION

You're preparing for FAST NUCES finals - one of the toughest CS programs in Pakistan. The competition is fierce, but you have:
- **10 focused hours today**
- **This comprehensive guide**
- **The determination to be #1**

Remember:
1. **Understand, don't memorize** - Focus on WHY, not just HOW
2. **Practice actively** - Write code, don't just read
3. **Debug your mistakes** - Every error is a learning opportunity
4. **Time yourself** - Simulate exam conditions
5. **Take short breaks** - 5 min every hour

**You've got this! Tomorrow: Pointers. Monday-Friday: Beast mode practice. Finals: Domination! 🚀**

---

*"The expert in anything was once a beginner who refused to give up."*

**NOW GO CODE AND CONQUER! 💪**
