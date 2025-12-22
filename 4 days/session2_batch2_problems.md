# SESSION 2 - BATCH 2: MEDIUM RECURSION PROBLEMS
**Total Problems: 20 | Estimated Time: 50-60 minutes**

---

## PROBLEM 1
```cpp
int func() {
    static int x = 0;
    x++;
    return x;
}

int main() {
    cout << func() << endl;
    cout << func() << endl;
    cout << func() << endl;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
int mystery(int n) {
    static int x = 0;
    if (n == 0)
        return x;
    x++;
    return mystery(n - 1);
}

int main() {
    cout << mystery(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
int compute(int n) {
    if (n <= 2)
        return n;
    return 2 * compute(n-1) + compute(n-2);
}

int main() {
    cout << compute(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
void process(int n, int& result) {
    if (n == 0)
        return;
    result += n;
    process(n - 1, result);
}

int main() {
    int result = 0;
    process(4, result);
    cout << result;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
void func(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    func(n - 1);
    cout << n << " ";
}

int main() {
    func(3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
int transform(int n, int rev = 0) {
    if (n == 0)
        return rev;
    return transform(n / 10, rev * 10 + n % 10);
}

int main() {
    cout << transform(1234);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
void convert(int n) {
    if (n == 0)
        return;
    convert(n / 2);
    cout << n % 2;
}

int main() {
    convert(13);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int calculate(int n) {
    if (n == 1)
        return 1;
    return 2 * calculate(n - 1) + 1;
}

int main() {
    cout << calculate(3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
void display(int arr[], int n) {
    if (n == 0)
        return;
    cout << arr[n-1] << " ";
    display(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    display(arr, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
int sequence(int n) {
    if (n <= 1)
        return 1;
    return sequence(n - 1) + sequence(n - 2);
}

int main() {
    cout << sequence(6);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int mystery(int n) {
    if (n <= 1)
        return 1;
    return n + mystery(n - 2);
}

int main() {
    cout << mystery(7);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
bool check(int arr[], int start, int end) {
    if (start >= end)
        return true;
    if (arr[start] != arr[end])
        return false;
    return check(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    cout << check(arr, 0, 4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13: Sum Even Positions
```cpp
int sumEven(int arr[], int n, int i = 0) {
    if (i >= n)
        return 0;
    if (i % 2 == 0)
        return arr[i] + sumEven(arr, n, i + 1);
    return sumEven(arr, n, i + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    cout << sumEven(arr, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14: Tribonacci
```cpp
int trib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return trib(n-1) + trib(n-2) + trib(n-3);
}

int main() {
    cout << trib(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15: Print Triangle
```cpp
void triangle(int n, int current = 1) {
    if (current > n)
        return;
    for (int i = 0; i < current; i++)
        cout << "*";
    cout << endl;
    triangle(n, current + 1);
}

int main() {
    triangle(4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 16: Multiply by Recursion
```cpp
int multiply(int a, int b) {
    if (b == 0)
        return 0;
    if (b == 1)
        return a;
    return a + multiply(a, b - 1);
}

int main() {
    cout << multiply(5, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17: Count Occurrences
```cpp
int countOccur(int arr[], int n, int target) {
    if (n == 0)
        return 0;
    if (arr[n-1] == target)
        return 1 + countOccur(arr, n-1, target);
    return countOccur(arr, n-1, target);
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 4};
    cout << countOccur(arr, 6, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18: String Length
```cpp
int strLen(char str[], int i = 0) {
    if (str[i] == '\0')
        return 0;
    return 1 + strLen(str, i + 1);
}

int main() {
    char str[] = "hello";
    cout << strLen(str);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19: Ackermann Function
```cpp
int ack(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

int main() {
    cout << ack(2, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20: Array Product
```cpp
int arrayProduct(int arr[], int n) {
    if (n == 0)
        return 1;
    return arr[n-1] * arrayProduct(arr, n-1);
}

int main() {
    int arr[] = {2, 3, 4};
    cout << arrayProduct(arr, 3);
    return 0;
}
```
**What is the output?**

---

**Check:** `session2_batch2_solutions.md`
# SESSION 2 - BATCH 2: REMAINING PROBLEMS (13-20) - FIXED

## PROBLEM 13
```cpp
int process(int arr[], int n, int i = 0) {
    if (i >= n)
        return 0;
    if (i % 2 == 0)
        return arr[i] + process(arr, n, i + 1);
    return process(arr, n, i + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    cout << process(arr, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int seq(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return seq(n-1) + seq(n-2) + seq(n-3);
}

int main() {
    cout << seq(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
void display(int n, int current = 1) {
    if (current > n)
        return;
    for (int i = 0; i < current; i++)
        cout << "*";
    cout << endl;
    display(n, current + 1);
}

int main() {
    display(4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 16
```cpp
int compute(int a, int b) {
    if (b == 0)
        return 0;
    if (b == 1)
        return a;
    return a + compute(a, b - 1);
}

int main() {
    cout << compute(5, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17
```cpp
int find(int arr[], int n, int target) {
    if (n == 0)
        return 0;
    if (arr[n-1] == target)
        return 1 + find(arr, n-1, target);
    return find(arr, n-1, target);
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 4};
    cout << find(arr, 6, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18
```cpp
int measure(char str[], int i = 0) {
    if (str[i] == '\0')
        return 0;
    return 1 + measure(str, i + 1);
}

int main() {
    char str[] = "hello";
    cout << measure(str);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19
```cpp
int mystery(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return mystery(m - 1, 1);
    return mystery(m - 1, mystery(m, n - 1));
}

int main() {
    cout << mystery(2, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20
```cpp
int calculate(int arr[], int n) {
    if (n == 0)
        return 1;
    return arr[n-1] * calculate(arr, n-1);
}

int main() {
    int arr[] = {2, 3, 4};
    cout << calculate(arr, 3);
    return 0;
}
```
**What is the output?**

---

**Check:** `session2_batch2_solutions.md`
