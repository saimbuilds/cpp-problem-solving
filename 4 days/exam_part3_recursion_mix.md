# PART 3: RECURSION MIX (EASY-MEDIUM ONLY)
**20 Problems | Time: 2 hours | Fall 2023 Level**

> **Note:** Only easy-medium recursion - no crazy nested stuff!

---

## PROBLEM 1
```cpp
int func(int *arr, int n) {
    if (n == 0)
        return 0;
    return *arr + func(arr + 1, n - 1);
}

int main() {
    int arr[] = {10, 20, 30, 40};
    cout << func(arr, 4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
void process(int& x, int n) {
    if (n == 0)
        return;
    x += n;
    process(x, n - 1);
}

int main() {
    int x = 0;
    process(x, 4);
    cout << x;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
int mystery(int *arr, int n) {
    if (n == 1)
        return *arr;
    int temp = mystery(arr + 1, n - 1);
    return (*arr > temp) ? *arr : temp;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    cout << mystery(arr, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
void func(int *arr, int n) {
    if (n == 0)
        return;
    *arr = *arr * 2;
    func(arr + 1, n - 1);
}

int main() {
    int *arr = new int[4]{1, 2, 3, 4};
    func(arr, 4);
    cout << arr[0] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int calculate(int n) {
    static int count = 0;
    if (n == 0)
        return count;
    count++;
    return calculate(n - 1);
}

int main() {
    cout << calculate(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
void mystery(int *start, int *end) {
    if (start >= end)
        return;
    int temp = *start;
    *start = *end;
    *end = temp;
    mystery(start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    mystery(arr, arr + 4);
    cout << arr[0] + arr[4];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
int func(int *arr, int n, int k) {
    if (n == 0)
        return 0;
    if (*arr > k)
        return 1 + func(arr + 1, n - 1, k);
    return func(arr + 1, n - 1, k);
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    cout << func(arr, 5, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
void process(int *arr, int n, int& sum) {
    if (n == 0) {
        sum = 0;
        return;
    }
    process(arr + 1, n - 1, sum);
    sum += *arr;
}

int main() {
    int arr[] = {5, 10, 15, 20};
    int sum = 0;
    process(arr, 4, sum);
    cout << sum;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
int mystery(int n, int m) {
    if (n == 0)
        return m;
    if (m == 0)
        return mystery(n - 1, 1);
    return mystery(n, m - 1) + 1;
}

int main() {
    cout << mystery(2, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
void func(int *arr, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    int temp = arr[left];
    arr[left] = arr[mid];
    arr[mid] = temp;
    func(arr, left + 1, right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    func(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int calculate(int *arr, int n) {
    if (n == 0)
        return 1;
    return *arr * calculate(arr + 1, n - 1);
}

int main() {
    int *arr = new int[3]{2, 3, 4};
    cout << calculate(arr, 3);
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
void mystery(int& a, int& b, int n) {
    if (n == 0)
        return;
    int temp = a;
    a = b;
    b = temp + b;
    mystery(a, b, n - 1);
}

int main() {
    int x = 1, y = 1;
    mystery(x, y, 5);
    cout << x << " " << y;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
int func(int *arr, int n, int *max) {
    if (n == 0) {
        *max = arr[0];
        return 0;
    }
    func(arr, n - 1, max);
    if (arr[n] > *max)
        *max = arr[n];
    return *max;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int max;
    func(arr, 4, &max);
    cout << max;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
void process(int **p, int n) {
    if (n == 0)
        return;
    **p = **p + 1;
    process(p, n - 1);
}

int main() {
    int x = 10;
    int *ptr = &x;
    int **pptr = &ptr;
    process(pptr, 5);
    cout << x;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
int mystery(int *arr, int n, int idx = 0) {
    if (idx >= n)
        return 0;
    if (arr[idx] % 2 == 0)
        return arr[idx] + mystery(arr, n, idx + 1);
    return mystery(arr, n, idx + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << mystery(arr, 6);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 16
```cpp
void func(int *arr, int n, int val) {
    if (n == 0)
        return;
    if (*arr % 2 == 0)
        *arr += val;
    func(arr + 1, n - 1, val);
}

int main() {
    int *arr = new int[5]{1, 2, 3, 4, 5};
    func(arr, 5, 10);
    cout << arr[1] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17
```cpp
int calculate(int n, int& result) {
    if (n == 0) {
        result = 0;
        return 0;
    }
    calculate(n - 1, result);
    result += n * n;
    return result;
}

int main() {
    int res = 0;
    calculate(4, res);
    cout << res;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18
```cpp
void mystery(int *arr, int *brr, int n) {
    if (n == 0)
        return;
    *brr = *arr * 2;
    mystery(arr + 1, brr + 1, n - 1);
}

int main() {
    int a[] = {1, 2, 3, 4};
    int *b = new int[4];
    mystery(a, b, 4);
    cout << b[0] + b[3];
    delete[] b;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19
```cpp
int func(int *arr, int n, int target) {
    if (n == 0)
        return 0;
    if (*arr == target)
        return 1 + func(arr + 1, n - 1, target);
    return func(arr + 1, n - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 4};
    cout << func(arr, 6, 2);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20 (KILLER)
```cpp
void transform(int *arr, int n, int& prod) {
    if (n == 0) {
        prod = 1;
        return;
    }
    transform(arr + 1, n - 1, prod);
    prod *= *arr;
}

int main() {
    int *arr = new int[4]{2, 3, 4, 5};
    int prod = 0;
    transform(arr, 4, prod);
    cout << prod;
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `exam_part3_solutions.md`

**10 min break, then FINAL PART 4!**
