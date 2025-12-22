# SESSION 3 - BATCH 3: KILLER FUSION PROBLEMS
**Total: 13 problems | Time: 50-70 minutes**

> **WARNING:** These are HARD! Past paper style!

---

## PROBLEM 1 (Past Paper Style)
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

## PROBLEM 2 (Past Paper Style)
```cpp
void mystery(int a, int& b, int& c, int d=4) {
    if(d < 1)
        return;
    cout << a << "," << b << "," << c << endl;
    c = a + 2 * b;
    int temp = b;
    b = a;
    a = 2 * temp;
    d % 2 ? mystery(b,a,c,d-1) : mystery(c,b,a,d-1);
}

int main() {
    int one=1, two=2, three=3;
    mystery(one, two, three);
    cout << one << "," << two << "," << three << endl;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
int process(int *arr, int *brr, int n) {
    if (n == 0)
        return 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += arr[i] - brr[n-1-i];
    }
    return result;
}

int main() {
    int A[] = {1, 2, 3, 4, -5, 1, 3};
    int B[] = {3, 1, -5, 4, 3, 2, 1};
    cout << process(A, B, 7);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
int func(int **arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j)
                sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    int r = 3, c = 3;
    int **matrix = new int*[r];
    for (int i = 0; i < r; i++)
        matrix[i] = new int[c];
    
    int val = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            matrix[i][j] = val++;
    
    cout << func(matrix, r, c);
    
    for (int i = 0; i < r; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
void transform(char *str, int n) {
    if (n <= 0)
        return;
    if (*str >= 'a' && *str <= 'z')
        *str = *str - 32;
    transform(str + 1, n - 1);
}

int main() {
    char str[] = "hello";
    transform(str, 5);
    cout << str;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
int mystery(int *p, int *q, int n) {
    if (n == 0)
        return 0;
    int diff = (*p > *q) ? (*p - *q) : (*q - *p);
    return diff + mystery(p + 1, q + 1, n - 1);
}

int main() {
    int a[] = {10, 20, 30};
    int b[] = {15, 18, 35};
    cout << mystery(a, b, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
void process(int& x, int& y, int& z) {
    if (x <= 0)
        return;
    int temp = x;
    x = y;
    y = z;
    z = temp + z;
    process(x, y, z);
}

int main() {
    int a = 3, b = 5, c = 7;
    process(a, b, c);
    cout << a << " " << b << " " << c;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int* create(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = (i + 1) * (i + 1);
    return arr;
}

int calculate(int *arr, int n) {
    if (n == 0)
        return 0;
    return arr[n-1] + calculate(arr, n-1);
}

int main() {
    int *p = create(4);
    cout << calculate(p, 4);
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
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

## PROBLEM 10
```cpp
int mystery(int *arr, int n, int& max, int& min) {
    if (n == 0) {
        max = arr[0];
        min = arr[0];
        return 0;
    }
    mystery(arr, n - 1, max, min);
    if (arr[n] > max) max = arr[n];
    if (arr[n] < min) min = arr[n];
    return max - min;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int max, min;
    cout << mystery(arr, 4, max, min);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
void process(int **p, int& val) {
    **p = **p * 2;
    val = **p;
}

int main() {
    int x = 5;
    int *ptr = &x;
    int **pptr = &ptr;
    int val = 0;
    process(pptr, val);
    cout << x << " " << val;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
int func(int *arr, int n, int k, int idx = 0) {
    if (idx >= n)
        return -1;
    if (idx > 0 && arr[idx] - arr[idx-1] == k)
        return idx;
    return func(arr, n, k, idx + 1);
}

int main() {
    int arr[] = {2, 5, 7, 10, 13};
    cout << func(arr, 5, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13 (Ultimate Challenge)
```cpp
void transform(int *p, int *q, int n) {
    if (n <= 0)
        return;
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
    transform(p + 1, q - 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    transform(arr, arr + 5, 3);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**What is the output?**

---

**Solutions:** `session3_batch3_solutions.md`

**SESSION 3 COMPLETE! 40 fusion problems done!**
