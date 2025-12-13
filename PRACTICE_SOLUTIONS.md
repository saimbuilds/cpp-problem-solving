# 🎯 PRACTICE PROBLEMS - COMPLETE SOLUTIONS

## Table of Contents
1. [1D Array Solutions](#1d-array-solutions)
2. [2D Array Solutions](#2d-array-solutions)
3. [Multi-D Array Solutions](#multi-d-array-solutions)
4. [Function Solutions](#function-solutions)
5. [Recursion Solutions](#recursion-solutions)
6. [Integration Solutions](#integration-solutions)

---

# 1D ARRAY SOLUTIONS

## Level 1 Solutions

### Q1.1: Second Largest Element
```cpp
#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n) {
    if(n < 2) return -1;  // Not enough elements
    
    int largest = INT_MIN, secondLargest = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Second Largest: " << findSecondLargest(arr, n) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

### Q1.2: Rotate Array Right by K
```cpp
#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;  // Handle k > n
    
    // Reverse entire array
    reverse(arr, 0, n-1);
    
    // Reverse first k elements
    reverse(arr, 0, k-1);
    
    // Reverse remaining elements
    reverse(arr, k, n-1);
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    
    cout << "Original: ";
    printArray(arr, n);
    
    rotateRight(arr, n, k);
    
    cout << "After rotating right by " << k << ": ";
    printArray(arr, n);
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

### Q1.3: Remove Duplicates from Sorted Array
```cpp
#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if(n == 0) return 0;
    
    int uniqueIndex = 0;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    
    return uniqueIndex + 1;  // New length
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int newLength = removeDuplicates(arr, n);
    
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNew length: " << newLength << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

## Level 2 Solutions

### Q2.1: Find All Pairs with Given Sum
```cpp
#include <iostream>
using namespace std;

void findPairs(int arr[], int n, int target) {
    cout << "Pairs with sum " << target << ":\n";
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }
}

// Optimized version using sorting (if allowed to modify array)
void findPairsOptimized(int arr[], int n, int target) {
    // Assuming array is sorted or we can sort it
    int left = 0, right = n - 1;
    
    cout << "Pairs with sum " << target << ":\n";
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(sum == target) {
            cout << "(" << arr[left] << ", " << arr[right] << ")\n";
            left++;
            right--;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    
    findPairs(arr, n, target);
    
    return 0;
}

// Time Complexity: O(n²) for brute force, O(n) for optimized (if sorted)
// Space Complexity: O(1)
```

### Q2.2: Longest Consecutive Sequence
```cpp
#include <iostream>
using namespace std;

int longestConsecutive(int arr[], int n) {
    if(n == 0) return 0;
    
    // Simple approach using frequency array (works for limited range)
    int minVal = arr[0], maxVal = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] < minVal) minVal = arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
    
    int range = maxVal - minVal + 1;
    bool* present = new bool[range]();
    
    for(int i = 0; i < n; i++) {
        present[arr[i] - minVal] = true;
    }
    
    int maxLength = 0, currentLength = 0;
    
    for(int i = 0; i < range; i++) {
        if(present[i]) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 0;
        }
    }
    
    delete[] present;
    return maxLength;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Longest consecutive sequence length: " << longestConsecutive(arr, n) << endl;
    
    return 0;
}

// Time Complexity: O(n + range)
// Space Complexity: O(range)
```

### Q2.3: Rearrange Array (Negatives Left, Positives Right)
```cpp
#include <iostream>
using namespace std;

void rearrange(int arr[], int n) {
    int temp[n];
    int index = 0;
    
    // First pass: add all negatives
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            temp[index++] = arr[i];
        }
    }
    
    // Second pass: add all positives
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) {
            temp[index++] = arr[i];
        }
    }
    
    // Copy back
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original: ";
    printArray(arr, n);
    
    rearrange(arr, n);
    
    cout << "Rearranged: ";
    printArray(arr, n);
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

## Level 3 Solutions

### Q3.1: Maximum Product of Three Numbers
```cpp
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxProductOfThree(int arr[], int n) {
    if(n < 3) return 0;
    
    // Sort the array
    sort(arr, arr + n);
    
    // Maximum product can be either:
    // 1. Product of three largest numbers
    // 2. Product of two smallest (most negative) and largest
    
    int product1 = arr[n-1] * arr[n-2] * arr[n-3];
    int product2 = arr[0] * arr[1] * arr[n-1];
    
    return max(product1, product2);
}

int main() {
    int arr[] = {-10, -10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Maximum product of three numbers: " << maxProductOfThree(arr, n) << endl;
    
    return 0;
}

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)
```

### Q3.2: Trapping Rain Water
```cpp
#include <iostream>
using namespace std;

int trapRainWater(int height[], int n) {
    if(n <= 2) return 0;
    
    int leftMax[n], rightMax[n];
    
    // Fill leftMax array
    leftMax[0] = height[0];
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }
    
    // Fill rightMax array
    rightMax[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    
    // Calculate trapped water
    int totalWater = 0;
    for(int i = 0; i < n; i++) {
        int waterLevel = min(leftMax[i], rightMax[i]);
        totalWater += waterLevel - height[i];
    }
    
    return totalWater;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);
    
    cout << "Total water trapped: " << trapRainWater(height, n) << " units" << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

### Q3.3: Stock Buy-Sell Multiple Transactions
```cpp
#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) {
    int totalProfit = 0;
    
    for(int i = 1; i < n; i++) {
        // If price increased, we could have bought yesterday and sold today
        if(prices[i] > prices[i-1]) {
            totalProfit += prices[i] - prices[i-1];
        }
    }
    
    return totalProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    
    cout << "Maximum profit: " << maxProfit(prices, n) << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

---

# 2D ARRAY SOLUTIONS

## Level 1 Solutions

### Q1.1: Sum of Boundary Elements
```cpp
#include <iostream>
using namespace std;

int boundarySum(int matrix[][10], int rows, int cols) {
    int sum = 0;
    
    // First row
    for(int j = 0; j < cols; j++) {
        sum += matrix[0][j];
    }
    
    // Last row
    for(int j = 0; j < cols; j++) {
        sum += matrix[rows-1][j];
    }
    
    // First column (excluding corners already counted)
    for(int i = 1; i < rows-1; i++) {
        sum += matrix[i][0];
    }
    
    // Last column (excluding corners already counted)
    for(int i = 1; i < rows-1; i++) {
        sum += matrix[i][cols-1];
    }
    
    return sum;
}

int main() {
    int matrix[3][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Sum of boundary elements: " << boundarySum(matrix, 3, 3) << endl;
    
    return 0;
}

// Time Complexity: O(rows + cols)
// Space Complexity: O(1)
```

### Q1.2: Search in Row-wise and Column-wise Sorted Matrix
```cpp
#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][10], int rows, int cols, int target) {
    // Start from top-right corner
    int i = 0, j = cols - 1;
    
    while(i < rows && j >= 0) {
        if(matrix[i][j] == target) {
            cout << "Found at (" << i << ", " << j << ")" << endl;
            return true;
        } else if(matrix[i][j] > target) {
            j--;  // Move left
        } else {
            i++;  // Move down
        }
    }
    
    return false;
}

int main() {
    int matrix[3][10] = {
        {10, 20, 30},
        {15, 25, 35},
        {27, 29, 37}
    };
    
    int target = 25;
    
    if(!searchMatrix(matrix, 3, 3, target)) {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

// Time Complexity: O(rows + cols)
// Space Complexity: O(1)
```

### Q1.3: Transpose Matrix
```cpp
#include <iostream>
using namespace std;

void transpose(int matrix[][10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix:\n";
    printMatrix(matrix, 3, 3);
    
    transpose(matrix, 3);
    
    cout << "\nTransposed Matrix:\n";
    printMatrix(matrix, 3, 3);
    
    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
```

## Level 2 Solutions

### Q2.1: Rotate Matrix 90° Counterclockwise
```cpp
#include <iostream>
using namespace std;

void rotateCounterClockwise(int matrix[][10], int n) {
    // Step 1: Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each column
    for(int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while(top < bottom) {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}

void printMatrix(int matrix[][10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original:\n";
    printMatrix(matrix, 3);
    
    rotateCounterClockwise(matrix, 3);
    
    cout << "\nRotated 90° Counterclockwise:\n";
    printMatrix(matrix, 3);
    
    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
```

### Q2.2: Spiral Order Traversal
```cpp
#include <iostream>
using namespace std;

void spiralOrder(int matrix[][10], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while(top <= bottom && left <= right) {
        // Traverse right
        for(int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        
        // Traverse down
        for(int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        // Traverse left (if still have rows)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        
        // Traverse up (if still have columns)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int matrix[3][10] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "Spiral Order: ";
    spiralOrder(matrix, 3, 4);
    
    return 0;
}

// Time Complexity: O(rows * cols)
// Space Complexity: O(1)
```

### Q2.3: Row with Maximum 1s
```cpp
#include <iostream>
using namespace std;

int rowWithMax1s(int matrix[][10], int rows, int cols) {
    int maxRow = -1;
    int j = cols - 1;
    
    for(int i = 0; i < rows; i++) {
        // Move left while we see 1s
        while(j >= 0 && matrix[i][j] == 1) {
            j--;
            maxRow = i;
        }
    }
    
    return maxRow;
}

int main() {
    int matrix[3][10] = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    
    int result = rowWithMax1s(matrix, 3, 4);
    
    if(result != -1) {
        cout << "Row with maximum 1s: " << result << endl;
    } else {
        cout << "No 1s found" << endl;
    }
    
    return 0;
}

// Time Complexity: O(rows + cols)
// Space Complexity: O(1)
```

## Level 3 Solutions

### Q3.1: Set Matrix Zeroes
```cpp
#include <iostream>
using namespace std;

void setZeroes(int matrix[][10], int rows, int cols) {
    bool firstRowZero = false, firstColZero = false;
    
    // Check if first row has zero
    for(int j = 0; j < cols; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    
    // Check if first column has zero
    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    // Use first row and column as markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Set zeros based on markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Handle first row
    if(firstRowZero) {
        for(int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    
    // Handle first column
    if(firstColZero) {
        for(int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][10] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original:\n";
    printMatrix(matrix, 3, 3);
    
    setZeroes(matrix, 3, 3);
    
    cout << "\nAfter setting zeroes:\n";
    printMatrix(matrix, 3, 3);
    
    return 0;
}

// Time Complexity: O(rows * cols)
// Space Complexity: O(1)
```

### Q3.2: Find Median in Row-wise Sorted Matrix
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int countLessEqual(int matrix[][10], int rows, int cols, int target) {
    int count = 0;
    for(int i = 0; i < rows; i++) {
        // Binary search in each row
        int left = 0, right = cols - 1, pos = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[i][mid] <= target) {
                pos = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        count += pos;
    }
    return count;
}

int findMedian(int matrix[][10], int rows, int cols) {
    int minVal = matrix[0][0], maxVal = matrix[0][0];
    
    // Find min and max
    for(int i = 0; i < rows; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][cols-1]);
    }
    
    int desired = (rows * cols + 1) / 2;
    
    while(minVal < maxVal) {
        int mid = minVal + (maxVal - minVal) / 2;
        int count = countLessEqual(matrix, rows, cols, mid);
        
        if(count < desired) {
            minVal = mid + 1;
        } else {
            maxVal = mid;
        }
    }
    
    return minVal;
}

int main() {
    int matrix[3][10] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    
    cout << "Median: " << findMedian(matrix, 3, 3) << endl;
    
    return 0;
}

// Time Complexity: O(rows * cols * log(max-min))
// Space Complexity: O(1)
```

### Q3.3: Count Paths in Matrix
```cpp
#include <iostream>
using namespace std;

int countPaths(int rows, int cols) {
    int dp[rows][cols];
    
    // Initialize first row and column
    for(int i = 0; i < rows; i++) {
        dp[i][0] = 1;
    }
    for(int j = 0; j < cols; j++) {
        dp[0][j] = 1;
    }
    
    // Fill the table
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[rows-1][cols-1];
}

int main() {
    int rows = 3, cols = 3;
    
    cout << "Number of paths in " << rows << "x" << cols << " matrix: ";
    cout << countPaths(rows, cols) << endl;
    
    return 0;
}

// Time Complexity: O(rows * cols)
// Space Complexity: O(rows * cols)
```

---

# RECURSION SOLUTIONS

## Level 1 Solutions

### Q1.1: Power Function
```cpp
#include <iostream>
using namespace std;

int power(int x, int n) {
    // Base case
    if(n == 0) return 1;
    
    // Recursive case
    return x * power(x, n - 1);
}

// Optimized version (O(log n))
int powerOptimized(int x, int n) {
    if(n == 0) return 1;
    
    int half = powerOptimized(x, n / 2);
    
    if(n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main() {
    cout << "5^3 = " << power(5, 3) << endl;
    cout << "2^10 = " << powerOptimized(2, 10) << endl;
    
    return 0;
}

// Time Complexity: O(n) for basic, O(log n) for optimized
// Space Complexity: O(n) for basic, O(log n) for optimized (recursion stack)
```

### Q1.2: Print Numbers 1 to N
```cpp
#include <iostream>
using namespace std;

void printNumbers(int n) {
    // Base case
    if(n == 0) return;
    
    // Recursive case
    printNumbers(n - 1);
    cout << n << " ";
}

int main() {
    printNumbers(10);
    cout << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack)
```

### Q1.3: Sum of Digits
```cpp
#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Base case
    if(n == 0) return 0;
    
    // Recursive case
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    cout << "Sum of digits of 1234: " << sumOfDigits(1234) << endl;
    
    return 0;
}

// Time Complexity: O(log n) where n is the number (number of digits)
// Space Complexity: O(log n)
```

### Q1.4: Check Palindrome
```cpp
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[], int start, int end) {
    // Base case
    if(start >= end) return true;
    
    // Check if characters match
    if(str[start] != str[end]) return false;
    
    // Recursive case
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str1[] = "racecar";
    char str2[] = "hello";
    
    cout << str1 << " is " << (isPalindrome(str1, 0, strlen(str1)-1) ? "palindrome" : "not palindrome") << endl;
    cout << str2 << " is " << (isPalindrome(str2, 0, strlen(str2)-1) ? "palindrome" : "not palindrome") << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

## Level 2 Solutions

### Q2.1: Tower of Hanoi
```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char aux) {
    // Base case
    if(n == 1) {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, aux, dest);
    
    // Move nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, dest, source);
}

int main() {
    int n = 3;
    cout << "Tower of Hanoi with " << n << " disks:\n";
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
```

### Q2.2: Generate Binary Strings
```cpp
#include <iostream>
using namespace std;

void generateBinary(int n, char str[], int index) {
    // Base case
    if(index == n) {
        str[n] = '\0';
        cout << str << endl;
        return;
    }
    
    // Try 0
    str[index] = '0';
    generateBinary(n, str, index + 1);
    
    // Try 1
    str[index] = '1';
    generateBinary(n, str, index + 1);
}

int main() {
    int n = 3;
    char str[n + 1];
    
    cout << "All binary strings of length " << n << ":\n";
    generateBinary(n, str, 0);
    
    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
```

### Q2.3: Generate All Subsets
```cpp
#include <iostream>
using namespace std;

void printSubset(int current[], int size) {
    cout << "{ ";
    for(int i = 0; i < size; i++) {
        cout << current[i] << " ";
    }
    cout << "}" << endl;
}

void generateSubsets(int arr[], int n, int index, int current[], int currSize) {
    // Base case
    if(index == n) {
        printSubset(current, currSize);
        return;
    }
    
    // Exclude current element
    generateSubsets(arr, n, index + 1, current, currSize);
    
    // Include current element
    current[currSize] = arr[index];
    generateSubsets(arr, n, index + 1, current, currSize + 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int current[n];
    
    cout << "All subsets:\n";
    generateSubsets(arr, n, 0, current, 0);
    
    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
```

### Q2.4: Recursive Bubble Sort
```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // Base case
    if(n == 1) return;
    
    // One pass of bubble sort
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    // Recursive call for remaining array
    bubbleSort(arr, n - 1);
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(n)
```

---

# INTEGRATION SOLUTIONS

### Flood Fill Algorithm
```cpp
#include <iostream>
using namespace std;

const int MAX = 100;

void floodFill(int image[][MAX], int sr, int sc, int newColor, int oldColor, int rows, int cols) {
    // Boundary check
    if(sr < 0 || sr >= rows || sc < 0 || sc >= cols) return;
    
    // Color check
    if(image[sr][sc] != oldColor) return;
    
    // Already filled
    if(image[sr][sc] == newColor) return;
    
    // Fill current cell
    image[sr][sc] = newColor;
    
    // Recursively fill 4 directions
    floodFill(image, sr - 1, sc, newColor, oldColor, rows, cols);  // Up
    floodFill(image, sr + 1, sc, newColor, oldColor, rows, cols);  // Down
    floodFill(image, sr, sc - 1, newColor, oldColor, rows, cols);  // Left
    floodFill(image, sr, sc + 1, newColor, oldColor, rows, cols);  // Right
}

void printImage(int image[][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int image[MAX][MAX] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int rows = 3, cols = 3;
    
    cout << "Original image:\n";
    printImage(image, rows, cols);
    
    int sr = 1, sc = 1, newColor = 2;
    floodFill(image, sr, sc, newColor, image[sr][sc], rows, cols);
    
    cout << "\nAfter flood fill:\n";
    printImage(image, rows, cols);
    
    return 0;
}

// Time Complexity: O(rows * cols)
// Space Complexity: O(rows * cols) in worst case (recursion stack)
```

---

**🎯 PRACTICE STRATEGY:**
1. **Understand the problem** - Read carefully
2. **Plan your approach** - Think before coding
3. **Write the code** - Implement step by step
4. **Test with examples** - Verify correctness
5. **Optimize** - Improve time/space complexity
6. **Review** - Learn from mistakes

**Good luck with your finals! You've got this! 🚀**
