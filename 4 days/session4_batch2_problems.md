# SESSION 4 - BATCH 2: INTEGRATION PROBLEMS
**Total: 15 problems | Time: 50-60 minutes**

> **Focus:** Dynamic memory + pointers + recursion

---

## PROBLEM 1
```cpp
int process(int *arr, int n) {
    if (n == 0)
        return 0;
    return arr[n-1] + process(arr, n-1);
}

int main() {
    int *arr = new int[4]{10, 20, 30, 40};
    cout << process(arr, 4);
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
int* func(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i * i;
    return arr;
}

int mystery(int *arr, int n) {
    if (n == 0)
        return 0;
    return arr[n-1] * arr[n-1] + mystery(arr, n-1);
}

int main() {
    int *p = func(3);
    cout << mystery(p, 3);
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
void modify(int *arr, int n) {
    if (n == 0)
        return;
    *arr = *arr * 2;
    modify(arr + 1, n - 1);
}

int main() {
    int *arr = new int[4]{1, 2, 3, 4};
    modify(arr, 4);
    cout << arr[0] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
int** create(int rows, int cols) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (i + 1) * (j + 1);
    }
    return matrix;
}

int main() {
    int **m = create(3, 3);
    cout << m[1][1] + m[2][2];
    
    for (int i = 0; i < 3; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
void transform(int *p, int n, int& sum) {
    if (n == 0) {
        sum = 0;
        return;
    }
    transform(p + 1, n - 1, sum);
    sum += *p;
}

int main() {
    int *arr = new int[5]{5, 10, 15, 20, 25};
    int sum = 0;
    transform(arr, 5, sum);
    cout << sum;
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
int* mystery(int *arr, int n) {
    int *result = new int[n];
    for (int i = 0; i < n; i++)
        result[i] = arr[n-1-i];
    return result;
}

int main() {
    int *arr = new int[4]{10, 20, 30, 40};
    int *rev = mystery(arr, 4);
    cout << rev[0] + rev[3];
    delete[] arr;
    delete[] rev;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
void process(int **p, int n) {
    for (int i = 0; i < n; i++)
        (*p)[i] = (*p)[i] + 10;
}

int main() {
    int *arr = new int[3]{5, 10, 15};
    process(&arr, 3);
    cout << arr[0] + arr[2];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int calculate(int *arr, int n, int k) {
    if (n == 0)
        return 0;
    if (*arr > k)
        return *arr + calculate(arr + 1, n - 1, k);
    return calculate(arr + 1, n - 1, k);
}

int main() {
    int *arr = new int[5]{3, 7, 2, 9, 4};
    cout << calculate(arr, 5, 5);
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
int* func(int n) {
    if (n == 0)
        return nullptr;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    return arr;
}

int main() {
    int *p = func(4);
    if (p != nullptr) {
        cout << p[0] * p[3];
        delete[] p;
    }
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
void modify(int *arr, int n, int val) {
    if (n == 0)
        return;
    if (*arr % 2 == 0)
        *arr += val;
    modify(arr + 1, n - 1, val);
}

int main() {
    int *arr = new int[5]{1, 2, 3, 4, 5};
    modify(arr, 5, 10);
    cout << arr[1] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int** create(int n) {
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            matrix[i][j] = i + j;
    }
    return matrix;
}

int sum(int **matrix, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += matrix[i][i];
    return total;
}

int main() {
    int **m = create(4);
    cout << sum(m, 4);
    
    for (int i = 0; i < 4; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
int* merge(int *a, int *b, int n) {
    int *result = new int[n * 2];
    for (int i = 0; i < n; i++) {
        result[i * 2] = a[i];
        result[i * 2 + 1] = b[i];
    }
    return result;
}

int main() {
    int *a = new int[3]{1, 2, 3};
    int *b = new int[3]{4, 5, 6};
    int *c = merge(a, b, 3);
    cout << c[0] + c[5];
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
void process(int *arr, int left, int right) {
    if (left >= right)
        return;
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    process(arr, left + 1, right - 1);
}

int main() {
    int *arr = new int[5]{10, 20, 30, 40, 50};
    process(arr, 0, 4);
    cout << arr[0] + arr[4];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int* func(int n, int start) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = start + i * 2;
    return arr;
}

int calculate(int *arr, int n) {
    if (n == 0)
        return 0;
    return arr[n-1] + calculate(arr, n-1);
}

int main() {
    int *p = func(5, 10);
    cout << calculate(p, 5);
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
int** mystery(int n) {
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            matrix[i][j] = (i == j) ? 1 : 0;
    }
    return matrix;
}

int main() {
    int **m = mystery(5);
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += m[i][i];
    cout << sum;
    
    for (int i = 0; i < 5; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `session4_batch2_solutions.md`

**SESSION 4 COMPLETE! 30 dynamic memory problems mastered! 🎉**
