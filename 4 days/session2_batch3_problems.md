# SESSION 2 - BATCH 3: HARD RECURSION CHALLENGES
**Total Problems: 15 | Estimated Time: 50-70 minutes**

---

## PROBLEM 1: Complex Static (Past Paper Style)
```cpp
int get(int N=0) {
    static int x = 0;
    return x++;
}

int main() {
    const int N = 6;
    int nums[] = {1,2,3,4,5,6};
    int idx = 1;
    while (idx) {
        idx = get(get());
        if (idx >= N)
            break;
        cout << nums[idx] << endl;
    }
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2: Recursive with References (Past Paper)
```cpp
void find(int a, int& b, int& c, int d=4) {
    if(d < 1)
        return;
    cout << a << "," << b << "," << c << endl;
    c = a + 2 * b;
    int temp = b;
    b = a;
    a = 2 * temp;
    d % 2 ? find(b,a,c,d-1) : find(c,b,a,d-1);
}

int main() {
    int one=1, two=2, three=3;
    find(one, two, three);
    cout << one << "," << two << "," << three << endl;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3: Array Manipulation Recursive
```cpp
int WHAT(int A[], int N) {
    int ANS = 0;
    int S = 0;
    int E = N-1;
    for(S = 0, E = N-1; S < E; S++, E--)
        ANS += A[S] - A[E];
    return ANS;
}

int main() {
    int A[] = {1, 2, 3, 4, -5, 1, 3, 2, 1};
    cout << WHAT(A, 7);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4: Nested Recursion Complex
```cpp
int mystery(int n, int m) {
    if (n == 0)
        return m + 1;
    if (m == 0)
        return mystery(n - 1, 1);
    return mystery(n - 1, mystery(n, m - 1));
}

int main() {
    cout << mystery(2, 1);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5: Recursive Pattern Advanced
```cpp
void pattern(int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
        pattern(n - 1);
        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
}

int main() {
    pattern(3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6: Recursive Polynomial Evaluation
```cpp
void CalcPoly(int *ptr, int size, int x, int &value) {
    while (size-- > 0) {
        value += *(ptr + size) * pow(x, size);
    }
}

int main() {
    int arr[] = {2, 3, 1, 2};
    int output = 0, x = 4, size = 4;
    CalcPoly(arr, size, x, output);
    cout << output;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7: Mirror Array Check
```cpp
bool Mirror_TwoD(int arr[][4], int rows, int cols) {
    if (rows != cols)
        return false;
    for (int i = 0; i < rows; ++i) {
        if (arr[0][0] != arr[i][i])
            return false;
        for (int j = i + 1; j < cols; ++j) {
            if (arr[i][j] != arr[j][i])
                return false;
        }
    }
    return true;
}

int main() {
    int arr[4][4] = {{1,2,3,4}, {2,1,6,5}, {3,6,1,9}, {4,5,9,1}};
    cout << Mirror_TwoD(arr, 4, 4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8: Recursive String Reverse
```cpp
void reverseStr(char str[], int start, int end) {
    if (start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStr(str, start + 1, end - 1);
}

int main() {
    char str[] = "hello";
    reverseStr(str, 0, 4);
    cout << str;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9: Recursive Binary Search
```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    cout << binarySearch(arr, 0, 6, 7);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10: Recursive Maze Path Count
```cpp
int countPaths(int m, int n) {
    if (m == 1 || n == 1)
        return 1;
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

int main() {
    cout << countPaths(3, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11: Subset Sum
```cpp
bool subsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n-1] > sum)
        return subsetSum(arr, n-1, sum);
    return subsetSum(arr, n-1, sum) || subsetSum(arr, n-1, sum-arr[n-1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    cout << subsetSum(arr, 6, 9);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12: Josephus Problem
```cpp
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    cout << josephus(5, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13: Tower of Hanoi Print
```cpp
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    hanoi(2, 'A', 'C', 'B');
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14: Recursive Merge
```cpp
void merge(int arr[], int l, int m, int r) {
    // Assume merge is implemented correctly
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```
**How many recursive calls for array of size 8?**

---

## PROBLEM 15: Catalan Number
```cpp
int catalan(int n) {
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
    return res;
}

int main() {
    cout << catalan(4);
    return 0;
}
```
**What is the output?**

---

**Check:** `session2_batch3_solutions.md`
