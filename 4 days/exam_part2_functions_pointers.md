# PART 2: FUNCTIONS + POINTERS MIX
**20 Problems | Time: 1.5 hours | Fall 2023 Level**

---

## PROBLEM 1
```cpp
void func(int x, int& y, int* z) {
    x = x + 10;
    y = y + 10;
    *z = *z + 10;
}

int main() {
    int a = 5, b = 10, c = 15;
    func(a, b, &c);
    cout << a << " " << b << " " << c;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
void mystery(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    mystery(&x, &y);
    cout << x << " " << y;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
void process(int& x, int& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

int main() {
    int a = 15, b = 25;
    process(a, b);
    cout << a << " " << b;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
void func(int arr[], int n, int val = 5) {
    for (int i = 0; i < n; i++)
        arr[i] += val;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    func(arr, 4);
    func(arr, 2, 10);
    cout << arr[0] + arr[3];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int* mystery(int* arr, int n) {
    int* result = new int[n];
    for (int i = 0; i < n; i++)
        result[i] = arr[i] * 2;
    return result;
}

int main() {
    int arr[] = {5, 10, 15};
    int* p = mystery(arr, 3);
    cout << p[0] + p[2];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
void func(int** p, int n) {
    for (int i = 0; i < n; i++)
        (*p)[i] = (*p)[i] * (*p)[i];
}

int main() {
    int arr[] = {2, 3, 4};
    int* ptr = arr;
    func(&ptr, 3);
    cout << arr[0] + arr[2];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
void process(int* arr, int n, int& sum, int& prod) {
    sum = 0;
    prod = 1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prod *= arr[i];
    }
}

int main() {
    int arr[] = {2, 3, 4};
    int s, p;
    process(arr, 3, s, p);
    cout << s << " " << p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int func(int a, int b = 10, int c = 20) {
    return a + b + c;
}

int main() {
    cout << func(5) << " ";
    cout << func(5, 15) << " ";
    cout << func(5, 15, 25);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
void mystery(int* p, int* q, int n) {
    for (int i = 0; i < n; i++) {
        int temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    mystery(a, b, 3);
    cout << a[0] + b[2];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
void func(int& x) {
    x = x * 2;
}

void func(int* x) {
    *x = *x * 3;
}

int main() {
    int a = 5;
    func(a);
    func(&a);
    cout << a;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int* create(int n, int start = 0, int step = 1) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = start + i * step;
    return arr;
}

int main() {
    int* p = create(5, 10, 2);
    cout << p[0] + p[4];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
void process(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i][j] + i + j;
}

int main() {
    int** m = new int*[2];
    m[0] = new int[2]{1, 2};
    m[1] = new int[2]{3, 4};
    
    process(m, 2, 2);
    cout << m[0][0] + m[1][1];
    
    delete[] m[0];
    delete[] m[1];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
void func(int* arr, int n) {
    int* temp = arr;
    for (int i = 0; i < n / 2; i++) {
        int t = temp[i];
        temp[i] = temp[n - 1 - i];
        temp[n - 1 - i] = t;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    func(arr, 5);
    cout << arr[0] + arr[4];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int mystery(int* a, int* b, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    cout << mystery(a, b, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
void func(int& a, int& b, int& c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;
    func(x, y, z);
    func(x, y, z);
    cout << x << " " << y << " " << z;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 16
```cpp
int* mystery(int* arr, int n, int k) {
    int* result = new int[n];
    for (int i = 0; i < n; i++)
        result[i] = (arr[i] > k) ? arr[i] : 0;
    return result;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    int* p = mystery(arr, 5, 5);
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += p[i];
    cout << sum;
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17
```cpp
void process(int* arr, int n, int* &result) {
    result = new int[n];
    for (int i = 0; i < n; i++)
        result[i] = arr[i] + 10;
}

int main() {
    int arr[] = {5, 10, 15};
    int* p = nullptr;
    process(arr, 3, p);
    cout << p[0] + p[2];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18
```cpp
void func(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j] = arr[i][j] * (i + 1);
}

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    func(arr, 2);
    cout << arr[0][0] + arr[1][2];
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19
```cpp
int mystery(int* arr, int n, int& max, int& min) {
    max = arr[0];
    min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    return max - min;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int mx, mn;
    int range = mystery(arr, 5, mx, mn);
    cout << range << " " << mx + mn;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20 (KILLER)
```cpp
void transform(int** matrix, int n, int& trace) {
    trace = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                trace += matrix[i][j];
            matrix[i][j] = matrix[i][j] + i - j;
        }
    }
}

int main() {
    int** m = new int*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new int[3];
        for (int j = 0; j < 3; j++)
            m[i][j] = i * 3 + j + 1;
    }
    
    int tr;
    transform(m, 3, tr);
    cout << tr << " " << m[1][1];
    
    for (int i = 0; i < 3; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `exam_part2_solutions.md`

**10 min break, then Part 3!**
