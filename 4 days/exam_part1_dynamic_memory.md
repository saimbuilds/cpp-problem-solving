# PART 1: DYNAMIC MEMORY MASTERY
**20 Problems | Time: 1.5 hours | Fall 2023 Level**

---

## PROBLEM 1
```cpp
int main() {
    int *p = new int(50);
    int *q = p;
    delete p;
    *q = 100;  // What happens?
    cout << *q;
    return 0;
}
```
**What is the output? Is there an error?**

---

## PROBLEM 2
```cpp
int* func(int n) {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}

int main() {
    int *p = func(5);
    cout << p[0];
    return 0;
}
```
**What is the output? Is this safe?**

---

## PROBLEM 3
```cpp
int main() {
    int **arr = new int*[3];
    for (int i = 0; i < 3; i++)
        arr[i] = new int[3];
    
    arr[0][0] = 10;
    arr[1][1] = 20;
    arr[2][2] = 30;
    
    delete[] arr;  // Is this correct?
    
    return 0;
}
```
**Is there a memory leak? If yes, how much memory is leaked?**

---

## PROBLEM 4
```cpp
int* mystery(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i * i;
    return arr;
}

int main() {
    int *p = mystery(5);
    int *q = mystery(3);
    cout << p[4] + q[2];
    delete[] p;
    delete[] q;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int main() {
    int *arr = new int[5]{10, 20, 30, 40, 50};
    int *p = arr + 2;
    delete[] arr;
    cout << *p;  // What happens?
    return 0;
}
```
**What is the output? Is this safe?**

---

## PROBLEM 6
```cpp
void func(int **p, int n) {
    *p = new int[n];
    for (int i = 0; i < n; i++)
        (*p)[i] = i + 1;
}

int main() {
    int *arr = nullptr;
    func(&arr, 4);
    cout << arr[0] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
int main() {
    int *p = new int[3];
    p[0] = 5;
    p[1] = 10;
    p[2] = 15;
    
    p = new int[2];  // What happens to old array?
    p[0] = 100;
    p[1] = 200;
    
    cout << p[0] + p[1];
    delete[] p;
    return 0;
}
```
**What is the output? Is there a memory leak?**

---

## PROBLEM 8
```cpp
int** create(int rows, int cols) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j + 1;
    }
    return matrix;
}

int main() {
    int **m = create(2, 3);
    cout << m[0][2] + m[1][1];
    
    for (int i = 0; i < 2; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
int main() {
    int *arr = new int[4];
    int *p = arr;
    
    for (int i = 0; i < 4; i++)
        *(p++) = i * 2;
    
    cout << arr[0] << " " << arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
void process(int *&p, int n) {
    delete[] p;
    p = new int[n];
    for (int i = 0; i < n; i++)
        p[i] = n - i;
}

int main() {
    int *arr = new int[3]{1, 2, 3};
    process(arr, 5);
    cout << arr[0] + arr[4];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int main() {
    int **p = new int*[2];
    p[0] = new int(10);
    p[1] = new int(20);
    
    cout << *p[0] + *p[1];
    
    delete p[0];
    delete p[1];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
int* func() {
    int *arr = new int[3];
    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    return arr + 1;
}

int main() {
    int *p = func();
    cout << *p << " " << *(p + 1);
    // How to properly delete?
    return 0;
}
```
**What is the output? How to fix memory leak?**

---

## PROBLEM 13
```cpp
int main() {
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * (i + 1);
    
    int *p = arr + 2;
    int *q = arr + 4;
    
    cout << *p + *q;
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
void mystery(int **arr, int n) {
    for (int i = 0; i < n; i++)
        (*arr)[i] = (*arr)[i] * 2;
}

int main() {
    int *arr = new int[4]{1, 2, 3, 4};
    mystery(&arr, 4);
    cout << arr[0] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
int main() {
    int **matrix = new int*[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
        for (int j = 0; j < 3; j++)
            matrix[i][j] = i + j;
    }
    
    int *p = matrix[1];
    cout << p[0] + p[2];
    
    for (int i = 0; i < 3; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 16
```cpp
int* create(int n, int start) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = start + i * 3;
    return arr;
}

int main() {
    int *p = create(4, 10);
    int *q = p + 1;
    cout << *q + *(q + 2);
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17
```cpp
int main() {
    int *p = new int[3];
    int *q = new int[3];
    
    p[0] = 5; p[1] = 10; p[2] = 15;
    q[0] = 2; q[1] = 4; q[2] = 6;
    
    int *temp = p;
    p = q;
    q = temp;
    
    cout << p[0] + q[2];
    
    delete[] p;
    delete[] q;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18
```cpp
void func(int *arr, int n) {
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[n - 1 - i];
    
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    
    delete[] temp;
}

int main() {
    int *arr = new int[4]{10, 20, 30, 40};
    func(arr, 4);
    cout << arr[0] + arr[3];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19
```cpp
int main() {
    int **arr = new int*[2];
    arr[0] = new int[3]{1, 2, 3};
    arr[1] = new int[3]{4, 5, 6};
    
    int *p = arr[0] + 2;
    int *q = arr[1];
    
    cout << *p + *q;
    
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20 (KILLER)
```cpp
int** mystery(int n) {
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == j)
                matrix[i][j] = i + j + 1;
            else
                matrix[i][j] = 0;
        }
    }
    return matrix;
}

int main() {
    int **m = mystery(4);
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += m[i][i];
    
    cout << sum;
    
    for (int i = 0; i < 4; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `exam_part1_solutions.md`

**Take 10 min break, then Part 2!**
