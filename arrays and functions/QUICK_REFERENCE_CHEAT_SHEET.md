# 🚀 QUICK REFERENCE CHEAT SHEET
## Arrays, Functions & Recursion - FAST NUCES Finals

---

## 📌 ARRAY DECLARATIONS

```cpp
// 1D Array
int arr[10];                          // Uninitialized
int arr[5] = {1, 2, 3, 4, 5};        // Initialized
int arr[] = {1, 2, 3};               // Size inferred (3)
int arr[10] = {0};                   // All zeros

// 2D Array
int matrix[3][4];                     // 3 rows, 4 columns
int matrix[2][3] = {{1,2,3}, {4,5,6}};
int matrix[3][3] = {0};              // All zeros

// 3D Array
int arr[2][3][4];                     // 2 blocks, 3 rows, 4 cols
```

---

## 🔥 ESSENTIAL ARRAY TRICKS

### Get Array Size
```cpp
int size = sizeof(arr) / sizeof(arr[0]);
```

### Reverse Array (Two Pointer)
```cpp
int left = 0, right = n-1;
while(left < right) {
    swap(arr[left++], arr[right--]);
}
```

### Find Min/Max
```cpp
int minVal = arr[0], maxVal = arr[0];
for(int i = 1; i < n; i++) {
    minVal = min(minVal, arr[i]);
    maxVal = max(maxVal, arr[i]);
}
```

### Prefix Sum
```cpp
prefix[0] = arr[0];
for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
// Sum from L to R = prefix[R] - prefix[L-1]
```

### Frequency Count
```cpp
int freq[1001] = {0};
for(int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
```

### Kadane's Algorithm (Max Subarray Sum)
```cpp
int maxSum = arr[0], currentSum = arr[0];
for(int i = 1; i < n; i++) {
    currentSum = max(arr[i], currentSum + arr[i]);
    maxSum = max(maxSum, currentSum);
}
```

---

## 🎯 2D ARRAY PATTERNS

### Row-wise Traversal
```cpp
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        // Process matrix[i][j]
    }
}
```

### Column-wise Traversal
```cpp
for(int j = 0; j < cols; j++) {
    for(int i = 0; i < rows; i++) {
        // Process matrix[i][j]
    }
}
```

### Diagonal Traversal
```cpp
// Main diagonal
for(int i = 0; i < n; i++) {
    cout << matrix[i][i];
}

// Anti-diagonal
for(int i = 0; i < n; i++) {
    cout << matrix[i][n-1-i];
}
```

### Spiral Traversal
```cpp
int top = 0, bottom = rows-1, left = 0, right = cols-1;
while(top <= bottom && left <= right) {
    // Right
    for(int i = left; i <= right; i++) cout << matrix[top][i];
    top++;
    
    // Down
    for(int i = top; i <= bottom; i++) cout << matrix[i][right];
    right--;
    
    // Left
    if(top <= bottom) {
        for(int i = right; i >= left; i--) cout << matrix[bottom][i];
        bottom--;
    }
    
    // Up
    if(left <= right) {
        for(int i = bottom; i >= top; i--) cout << matrix[i][left];
        left++;
    }
}
```

### Rotate 90° Clockwise
```cpp
// Step 1: Transpose
for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
        swap(matrix[i][j], matrix[j][i]);

// Step 2: Reverse each row
for(int i = 0; i < n; i++)
    reverse(matrix[i], matrix[i] + n);
```

### 4-Direction Movement
```cpp
int dx[] = {-1, 1, 0, 0};   // Up, Down, Left, Right
int dy[] = {0, 0, -1, 1};

for(int dir = 0; dir < 4; dir++) {
    int newX = x + dx[dir];
    int newY = y + dy[dir];
    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
        // Valid neighbor
    }
}
```

---

## 💡 FUNCTION TEMPLATES

### Basic Function
```cpp
return_type functionName(parameters) {
    // code
    return value;
}
```

### Pass by Value
```cpp
void modify(int x) {
    x = 100;  // Doesn't affect original
}
```

### Pass by Reference
```cpp
void modify(int &x) {
    x = 100;  // Changes original
}
```

### Array as Parameter (1D)
```cpp
void processArray(int arr[], int size) {
    // arr is passed by reference automatically
}
```

### Array as Parameter (2D)
```cpp
void process2D(int arr[][COLS], int rows) {
    // Must specify column size
}
```

### Function Overloading
```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
```

### Default Parameters
```cpp
int power(int base, int exp = 2) {
    // exp defaults to 2 if not provided
}
```

---

## 🌀 RECURSION PATTERNS

### Basic Template
```cpp
returnType recursive(parameters) {
    // Base case
    if(stopping_condition) {
        return base_value;
    }
    
    // Recursive case
    return recursive(modified_parameters);
}
```

### Linear Recursion
```cpp
int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}
```

### Binary Recursion
```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

### Tail Recursion
```cpp
int factorial(int n, int result = 1) {
    if(n == 0) return result;
    return factorial(n - 1, n * result);
}
```

### Array Recursion
```cpp
int arraySum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n-1] + arraySum(arr, n-1);
}
```

### Binary Search (Recursive)
```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if(left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return binarySearch(arr, left, mid-1, target);
    return binarySearch(arr, mid+1, right, target);
}
```

### Backtracking Template
```cpp
void backtrack(parameters) {
    if(base_case) {
        // Process solution
        return;
    }
    
    for(each choice) {
        // Make choice
        backtrack(modified_parameters);
        // Undo choice (backtrack)
    }
}
```

### Memoization (DP)
```cpp
int memo[MAX];
// Initialize: fill(memo, memo+MAX, -1);

int solve(int n) {
    if(base_case) return base_value;
    if(memo[n] != -1) return memo[n];
    
    memo[n] = /* recursive calculation */;
    return memo[n];
}
```

---

## ⚡ COMMON ALGORITHMS

### Bubble Sort
```cpp
for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
// Time: O(n²), Space: O(1)
```

### Selection Sort
```cpp
for(int i = 0; i < n-1; i++) {
    int minIdx = i;
    for(int j = i+1; j < n; j++) {
        if(arr[j] < arr[minIdx]) {
            minIdx = j;
        }
    }
    swap(arr[i], arr[minIdx]);
}
// Time: O(n²), Space: O(1)
```

### Binary Search
```cpp
int left = 0, right = n - 1;
while(left <= right) {
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
// Time: O(log n), Space: O(1)
```

### Two Pointer Technique
```cpp
int left = 0, right = n - 1;
while(left < right) {
    if(condition) {
        // Process
        left++;
        right--;
    } else if(another_condition) {
        left++;
    } else {
        right--;
    }
}
```

---

## 📊 TIME COMPLEXITY QUICK GUIDE

| Operation | Complexity |
|-----------|-----------|
| Single loop | O(n) |
| Nested loops (2 levels) | O(n²) |
| Nested loops (3 levels) | O(n³) |
| Binary search | O(log n) |
| Linear recursion | O(n) |
| Binary recursion (fib) | O(2^n) |
| Divide & conquer | O(n log n) |

---

## 🎯 COMMON MISTAKES TO AVOID

1. **Array Index Out of Bounds**
   ```cpp
   // WRONG
   for(int i = 0; i <= n; i++)  // Should be i < n
   
   // RIGHT
   for(int i = 0; i < n; i++)
   ```

2. **Infinite Recursion**
   ```cpp
   // WRONG - No base case
   int factorial(int n) {
       return n * factorial(n-1);
   }
   
   // RIGHT
   int factorial(int n) {
       if(n <= 1) return 1;  // Base case!
       return n * factorial(n-1);
   }
   ```

3. **Uninitialized Arrays**
   ```cpp
   // WRONG
   int arr[100];  // Garbage values
   
   // RIGHT
   int arr[100] = {0};  // All zeros
   ```

4. **Wrong 2D Array Parameter**
   ```cpp
   // WRONG
   void func(int arr[][], int rows, int cols)
   
   // RIGHT
   void func(int arr[][MAX_COLS], int rows)
   ```

5. **Integer Overflow**
   ```cpp
   // WRONG - May overflow
   int product = arr[0] * arr[1] * arr[2];
   
   // RIGHT
   long long product = (long long)arr[0] * arr[1] * arr[2];
   ```

---

## 🔧 DEBUGGING TIPS

### Print Array
```cpp
void debug(int arr[], int n) {
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

### Print Matrix
```cpp
void debug(int matrix[][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
```

### Trace Recursion
```cpp
void recursive(int n, int depth = 0) {
    cout << "Depth: " << depth << ", n: " << n << endl;
    if(n == 0) return;
    recursive(n-1, depth+1);
}
```

---

## 💪 EXAM DAY CHECKLIST

- [ ] Read problem carefully (2x)
- [ ] Identify input/output format
- [ ] Think of edge cases (empty array, single element, etc.)
- [ ] Plan approach before coding
- [ ] Write clean, readable code
- [ ] Test with sample inputs
- [ ] Check for off-by-one errors
- [ ] Verify base cases in recursion
- [ ] Check array bounds
- [ ] Review time/space complexity

---

## 🎓 MUST-KNOW PROBLEMS

### Arrays
1. Second largest element
2. Rotate array
3. Kadane's algorithm
4. Two sum problem
5. Trapping rain water

### 2D Arrays
1. Spiral traversal
2. Matrix rotation
3. Search in sorted matrix
4. Set matrix zeroes
5. Transpose matrix

### Recursion
1. Factorial
2. Fibonacci
3. Tower of Hanoi
4. Generate subsets
5. N-Queens

---

## 🚀 FINAL TIPS

1. **Practice writing code on paper** - Exams often don't allow computers
2. **Time yourself** - Simulate exam conditions
3. **Understand, don't memorize** - Focus on logic
4. **Start with brute force** - Optimize later
5. **Test edge cases** - Empty, single element, all same, etc.

---

**Remember: You're preparing for FAST NUCES - one of the toughest programs. You've got this! 💪**

**Print this cheat sheet and keep it handy during practice! 📄**
