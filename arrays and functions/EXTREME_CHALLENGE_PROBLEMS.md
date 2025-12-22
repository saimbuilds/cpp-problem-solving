# 🔥 EXTREME CHALLENGE PROBLEMS
## MIT-Level Difficulty for FAST NUCES Top Performers

**Warning:** These problems are EXTREMELY difficult. Attempt only after mastering basics.  
**Purpose:** Prepare you for the hardest questions your professors can throw at you.

---

## 🎯 PROBLEM SET 1: ARRAYS - NIGHTMARE MODE

### Problem 1: Maximum Sum Rectangle in 2D Array
**Difficulty:** ⭐⭐⭐⭐⭐

Find the maximum sum rectangle in a 2D array (can contain negative numbers).

```cpp
// Input:
// 1   2  -1  -4  -20
// -8  -3   4   2    1
// 3   8  10   1    3
// -4 -1   1   7   -6

// Output: Maximum sum = 29
// Rectangle: rows 1-2, cols 1-3
```

**Hint:** Use Kadane's algorithm for each column combination.

**Solution:**
```cpp
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int kadane(int arr[], int n, int &start, int &end) {
    int maxSum = INT_MIN, currentSum = 0;
    int tempStart = 0;
    start = end = 0;
    
    for(int i = 0; i < n; i++) {
        currentSum += arr[i];
        
        if(currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
        
        if(currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    
    return maxSum;
}

void maxSumRectangle(int matrix[][MAX], int rows, int cols) {
    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;
    
    // Fix left column
    for(int left = 0; left < cols; left++) {
        int temp[rows] = {0};
        
        // Extend to right column
        for(int right = left; right < cols; right++) {
            // Add current column to temp
            for(int i = 0; i < rows; i++) {
                temp[i] += matrix[i][right];
            }
            
            // Find max sum in this column range
            int start, end;
            int sum = kadane(temp, rows, start, end);
            
            if(sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = end;
            }
        }
    }
    
    cout << "Maximum sum: " << maxSum << endl;
    cout << "Rectangle: rows " << finalTop << "-" << finalBottom;
    cout << ", cols " << finalLeft << "-" << finalRight << endl;
}

int main() {
    int matrix[4][MAX] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    
    maxSumRectangle(matrix, 4, 5);
    
    return 0;
}

// Time Complexity: O(cols² * rows)
// Space Complexity: O(rows)
```

---

### Problem 2: Longest Increasing Path in Matrix
**Difficulty:** ⭐⭐⭐⭐⭐

Find the length of the longest increasing path in a matrix. You can move in 4 directions.

```cpp
// Input:
// 9 9 4
// 6 6 8
// 2 1 1

// Output: 4
// Path: 1 → 2 → 6 → 9
```

**Solution:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int matrix[][MAX], int rows, int cols, int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    
    int maxPath = 1;
    
    for(int dir = 0; dir < 4; dir++) {
        int newI = i + dx[dir];
        int newJ = j + dy[dir];
        
        if(newI >= 0 && newI < rows && newJ >= 0 && newJ < cols &&
           matrix[newI][newJ] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + dfs(matrix, rows, cols, newI, newJ));
        }
    }
    
    dp[i][j] = maxPath;
    return maxPath;
}

int longestIncreasingPath(int matrix[][MAX], int rows, int cols) {
    memset(dp, -1, sizeof(dp));
    int result = 0;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result = max(result, dfs(matrix, rows, cols, i, j));
        }
    }
    
    return result;
}

int main() {
    int matrix[3][MAX] = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    
    cout << "Longest increasing path: " << longestIncreasingPath(matrix, 3, 3) << endl;
    
    return 0;
}

// Time Complexity: O(rows * cols)
// Space Complexity: O(rows * cols)
```

---

### Problem 3: Count Inversions in Array
**Difficulty:** ⭐⭐⭐⭐

Count the number of inversions in an array. An inversion is a pair (i, j) where i < j but arr[i] > arr[j].

```cpp
// Input: {2, 4, 1, 3, 5}
// Output: 3
// Inversions: (2,1), (4,1), (4,3)
```

**Solution using Merge Sort:**
```cpp
#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // All remaining elements in left are greater
        }
    }
    
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return invCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    
    return invCount;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Number of inversions: " << countInversions(arr, n) << endl;
    
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
```

---

## 🎯 PROBLEM SET 2: RECURSION - HELL MODE

### Problem 4: Generate All Valid Parentheses
**Difficulty:** ⭐⭐⭐⭐⭐

Generate all combinations of n pairs of valid parentheses.

```cpp
// Input: n = 3
// Output: ((())), (()()), (())(), ()(()), ()()()
```

**Solution:**
```cpp
#include <iostream>
using namespace std;

void generateParentheses(int n, int open, int close, char current[], int index) {
    // Base case: generated n pairs
    if(close == n) {
        current[index] = '\0';
        cout << current << endl;
        return;
    }
    
    // Add opening bracket if we haven't used all
    if(open < n) {
        current[index] = '(';
        generateParentheses(n, open + 1, close, current, index + 1);
    }
    
    // Add closing bracket if it doesn't exceed opening
    if(close < open) {
        current[index] = ')';
        generateParentheses(n, open, close + 1, current, index + 1);
    }
}

int main() {
    int n = 3;
    char current[2 * n + 1];
    
    cout << "All valid parentheses combinations for n = " << n << ":\n";
    generateParentheses(n, 0, 0, current, 0);
    
    return 0;
}

// Time Complexity: O(4^n / √n) - Catalan number
// Space Complexity: O(n)
```

---

### Problem 5: Word Break Problem
**Difficulty:** ⭐⭐⭐⭐⭐

Check if a string can be segmented into words from a dictionary.

```cpp
// Input: "leetcode", dict = {"leet", "code"}
// Output: true

// Input: "applepenapple", dict = {"apple", "pen"}
// Output: true

// Input: "catsandog", dict = {"cats", "dog", "sand", "and", "cat"}
// Output: false
```

**Solution:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

bool isInDictionary(char word[], char dict[][20], int dictSize) {
    for(int i = 0; i < dictSize; i++) {
        if(strcmp(word, dict[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool wordBreak(char str[], int start, char dict[][20], int dictSize, int memo[]) {
    int len = strlen(str);
    
    // Base case: reached end of string
    if(start == len) return true;
    
    // Check memoization
    if(memo[start] != -1) return memo[start];
    
    // Try all possible substrings starting from 'start'
    char temp[100];
    for(int end = start; end < len; end++) {
        // Extract substring
        int k = 0;
        for(int i = start; i <= end; i++) {
            temp[k++] = str[i];
        }
        temp[k] = '\0';
        
        // If substring is in dictionary, check remaining string
        if(isInDictionary(temp, dict, dictSize)) {
            if(wordBreak(str, end + 1, dict, dictSize, memo)) {
                memo[start] = 1;
                return true;
            }
        }
    }
    
    memo[start] = 0;
    return false;
}

int main() {
    char str[] = "leetcode";
    char dict[10][20] = {"leet", "code"};
    int dictSize = 2;
    
    int memo[100];
    for(int i = 0; i < 100; i++) memo[i] = -1;
    
    if(wordBreak(str, 0, dict, dictSize, memo)) {
        cout << "String can be segmented" << endl;
    } else {
        cout << "String cannot be segmented" << endl;
    }
    
    return 0;
}

// Time Complexity: O(n² * m) where n = string length, m = dict size
// Space Complexity: O(n)
```

---

### Problem 6: N-Queens Problem (Complete Solution)
**Difficulty:** ⭐⭐⭐⭐⭐

Place N queens on N×N chessboard such that no two queens attack each other.

**Solution:**
```cpp
#include <iostream>
using namespace std;

const int MAX = 20;

bool isSafe(int board[][MAX], int row, int col, int n) {
    // Check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1) return false;
    }
    
    // Check upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) return false;
    }
    
    // Check upper right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1) return false;
    }
    
    return true;
}

void printBoard(int board[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueens(int board[][MAX], int row, int n) {
    // Base case: all queens placed
    if(row == n) {
        printBoard(board, n);
        return true;
    }
    
    bool foundSolution = false;
    
    // Try placing queen in each column
    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col, n)) {
            // Place queen
            board[row][col] = 1;
            
            // Recursively place remaining queens
            foundSolution = solveNQueens(board, row + 1, n) || foundSolution;
            
            // Backtrack
            board[row][col] = 0;
        }
    }
    
    return foundSolution;
}

int main() {
    int n = 4;
    int board[MAX][MAX] = {0};
    
    cout << "Solutions for " << n << "-Queens problem:\n\n";
    
    if(!solveNQueens(board, 0, n)) {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}

// Time Complexity: O(n!)
// Space Complexity: O(n²)
```

---

### Problem 7: Sudoku Solver
**Difficulty:** ⭐⭐⭐⭐⭐

Solve a 9×9 Sudoku puzzle using backtracking.

**Solution:**
```cpp
#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(int grid[][N], int row, int col, int num) {
    // Check row
    for(int x = 0; x < N; x++) {
        if(grid[row][x] == num) return false;
    }
    
    // Check column
    for(int x = 0; x < N; x++) {
        if(grid[x][col] == num) return false;
    }
    
    // Check 3×3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i + startRow][j + startCol] == num) return false;
        }
    }
    
    return true;
}

bool solveSudoku(int grid[][N]) {
    int row = -1, col = -1;
    bool isEmpty = false;
    
    // Find empty cell
    for(int i = 0; i < N && !isEmpty; i++) {
        for(int j = 0; j < N && !isEmpty; j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
            }
        }
    }
    
    // No empty cell, puzzle solved
    if(!isEmpty) return true;
    
    // Try digits 1-9
    for(int num = 1; num <= 9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            if(solveSudoku(grid)) {
                return true;
            }
            
            // Backtrack
            grid[row][col] = 0;
        }
    }
    
    return false;
}

void printGrid(int grid[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    if(solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}

// Time Complexity: O(9^(n*n)) worst case
// Space Complexity: O(n²)
```

---

### Problem 8: Rat in a Maze (All Paths)
**Difficulty:** ⭐⭐⭐⭐

Find all possible paths for a rat to reach from (0,0) to (n-1,n-1) in a maze.

**Solution:**
```cpp
#include <iostream>
using namespace std;

const int MAX = 10;

void printPath(int path[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int maze[][MAX], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

void solveMaze(int maze[][MAX], int x, int y, int path[][MAX], int n) {
    // Reached destination
    if(x == n-1 && y == n-1) {
        path[x][y] = 1;
        printPath(path, n);
        path[x][y] = 0;  // Backtrack for other paths
        return;
    }
    
    // Mark current cell
    path[x][y] = 1;
    
    // Move down
    if(isSafe(maze, x+1, y, n) && path[x+1][y] == 0) {
        solveMaze(maze, x+1, y, path, n);
    }
    
    // Move right
    if(isSafe(maze, x, y+1, n) && path[x][y+1] == 0) {
        solveMaze(maze, x, y+1, path, n);
    }
    
    // Move up
    if(isSafe(maze, x-1, y, n) && path[x-1][y] == 0) {
        solveMaze(maze, x-1, y, path, n);
    }
    
    // Move left
    if(isSafe(maze, x, y-1, n) && path[x][y-1] == 0) {
        solveMaze(maze, x, y-1, path, n);
    }
    
    // Backtrack
    path[x][y] = 0;
}

int main() {
    int maze[MAX][MAX] = {
        {1, 1, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };
    
    int path[MAX][MAX] = {0};
    int n = 4;
    
    cout << "All paths from (0,0) to (" << n-1 << "," << n-1 << "):\n\n";
    solveMaze(maze, 0, 0, path, n);
    
    return 0;
}

// Time Complexity: O(2^(n²))
// Space Complexity: O(n²)
```

---

## 🎯 PROBLEM SET 3: INTEGRATION NIGHTMARES

### Problem 9: Matrix Chain Multiplication
**Difficulty:** ⭐⭐⭐⭐⭐

Find the minimum number of multiplications needed to multiply a chain of matrices.

```cpp
// Input: dimensions[] = {40, 20, 30, 10, 30}
// Matrices: A1(40×20), A2(20×30), A3(30×10), A4(10×30)
// Output: 26000
```

**Solution:**
```cpp
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX];

int matrixChainMemo(int dims[], int i, int j) {
    if(i == j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int minOps = INT_MAX;
    
    for(int k = i; k < j; k++) {
        int ops = matrixChainMemo(dims, i, k) +
                  matrixChainMemo(dims, k+1, j) +
                  dims[i-1] * dims[k] * dims[j];
        
        minOps = min(minOps, ops);
    }
    
    dp[i][j] = minOps;
    return minOps;
}

int main() {
    int dims[] = {40, 20, 30, 10, 30};
    int n = sizeof(dims) / sizeof(dims[0]);
    
    memset(dp, -1, sizeof(dp));
    
    cout << "Minimum multiplications: " << matrixChainMemo(dims, 1, n-1) << endl;
    
    return 0;
}

// Time Complexity: O(n³)
// Space Complexity: O(n²)
```

---

### Problem 10: Longest Common Subsequence (3 Strings)
**Difficulty:** ⭐⭐⭐⭐⭐

Find the longest common subsequence among three strings.

**Solution:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int dp[100][100][100];

int lcs3(char* s1, char* s2, char* s3, int i, int j, int k) {
    if(i == 0 || j == 0 || k == 0) return 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
        dp[i][j][k] = 1 + lcs3(s1, s2, s3, i-1, j-1, k-1);
    } else {
        int a = lcs3(s1, s2, s3, i-1, j, k);
        int b = lcs3(s1, s2, s3, i, j-1, k);
        int c = lcs3(s1, s2, s3, i, j, k-1);
        dp[i][j][k] = max(a, max(b, c));
    }
    
    return dp[i][j][k];
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";
    char s3[] = "AGXGTAB";
    
    memset(dp, -1, sizeof(dp));
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    
    cout << "LCS of 3 strings: " << lcs3(s1, s2, s3, len1, len2, len3) << endl;
    
    return 0;
}

// Time Complexity: O(n * m * p)
// Space Complexity: O(n * m * p)
```

---

## 🏆 CHALLENGE YOURSELF

### Scoring System
- **Problem 1-3:** 10 points each
- **Problem 4-8:** 15 points each
- **Problem 9-10:** 20 points each

**Total:** 130 points

### Performance Levels
- **0-30:** Keep practicing basics
- **31-60:** Good progress, need more practice
- **61-90:** Strong understanding
- **91-110:** Excellent! Top 10% material
- **111-130:** LEGENDARY! Top 1% - You're ready to dominate!

---

## 💡 TIPS FOR SOLVING EXTREME PROBLEMS

1. **Break down the problem** - Understand what's being asked
2. **Start with brute force** - Get a working solution first
3. **Identify patterns** - Look for recursion, DP, greedy, etc.
4. **Optimize gradually** - Improve time/space complexity step by step
5. **Test edge cases** - Empty input, single element, all same, etc.
6. **Draw diagrams** - Visualize the problem
7. **Don't give up** - These are MEANT to be hard!

---

## 🚀 WHEN TO ATTEMPT THESE

- **After completing basic roadmap** (all 50 problems)
- **When you have 2-3 hours of focused time**
- **Day 6 before finals** (final practice)
- **When you want to challenge yourself**

---

**Remember: If you can solve even 5 of these 10 problems, you're in the top 5% of your batch!**

**FAST NUCES expects excellence. These problems will get you there! 💪**

**Good luck, future topper! 🏆**
