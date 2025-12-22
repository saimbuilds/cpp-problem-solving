# SESSION 3 - BATCH 2: MEDIUM FUSION PROBLEMS
**Total: 15 problems | Time: 45-60 minutes**

---

## PROBLEM 1
```cpp
void process(int *arr, int n) {
    if (n == 0)
        return;
    *arr = *arr * 2;
    process(arr + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    process(arr, 4);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
int mystery(int *arr, int n) {
    if (n == 1)
        return *arr;
    int temp = mystery(arr + 1, n - 1);
    return (*arr < temp) ? *arr : temp;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    cout << mystery(arr, 5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
void func(int *start, int *end) {
    if (start >= end)
        return;
    *start = *start + *end;
    *end = *start - *end;
    *start = *start - *end;
    func(start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    func(arr, arr + 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
void transform(int& x, int& y, int n) {
    if (n == 0)
        return;
    int temp = x;
    x = y;
    y = temp + y;
    transform(x, y, n - 1);
}

int main() {
    int a = 1, b = 1;
    transform(a, b, 5);
    cout << a << " " << b;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int calculate(int *p, int n, int& sum) {
    if (n == 0)
        return sum;
    sum += *p;
    return calculate(p + 1, n - 1, sum);
}

int main() {
    int arr[] = {10, 20, 30};
    int sum = 0;
    calculate(arr, 3, sum);
    cout << sum;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
void mystery(int *arr, int n, int val) {
    if (n == 0)
        return;
    if (*arr % 2 == 0)
        *arr += val;
    mystery(arr + 1, n - 1, val);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    mystery(arr, 5, 10);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
int process(int *arr, int *brr, int n) {
    if (n == 0)
        return 0;
    return (*arr * *brr) + process(arr + 1, brr + 1, n - 1);
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    cout << process(a, b, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
void func(char *str, int n) {
    if (n <= 0)
        return;
    cout << *str;
    func(str + 1, n - 1);
}

int main() {
    char str[] = "hello";
    func(str + 1, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
void modify(int *p, int& count) {
    if (*p == 0)
        return;
    count++;
    (*p)--;
    modify(p, count);
}

int main() {
    int x = 5;
    int count = 0;
    modify(&x, count);
    cout << x << " " << count;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
int search(int *arr, int n, int target, int idx = 0) {
    if (idx >= n)
        return -1;
    if (arr[idx] == target)
        return idx;
    return search(arr, n, target, idx + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    cout << search(arr, 5, 30);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
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
    process(pptr, 3);
    cout << x;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
void func(int *arr, int n, int *max) {
    if (n == 0)
        return;
    if (*arr > *max)
        *max = *arr;
    func(arr + 1, n - 1, max);
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    int max = arr[0];
    func(arr, 5, &max);
    cout << max;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
void mystery(int& a, int& b) {
    if (a == 0 || b == 0)
        return;
    if (a > b) {
        a = a - b;
        mystery(a, b);
    } else {
        b = b - a;
        mystery(a, b);
    }
}

int main() {
    int x = 48, y = 18;
    mystery(x, y);
    cout << x << " " << y;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int calculate(int *arr, int n, int k) {
    if (n == 0)
        return 0;
    if (*arr > k)
        return 1 + calculate(arr + 1, n - 1, k);
    return calculate(arr + 1, n - 1, k);
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    cout << calculate(arr, 6, 4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
void transform(int *p, int n, int& prod) {
    if (n == 0) {
        prod = 1;
        return;
    }
    transform(p + 1, n - 1, prod);
    prod *= *p;
}

int main() {
    int arr[] = {2, 3, 4};
    int prod = 0;
    transform(arr, 3, prod);
    cout << prod;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `session3_batch2_solutions.md`
