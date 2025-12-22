# SESSION 4 - BATCH 1: DYNAMIC MEMORY PROBLEMS
**Total: 15 problems | Time: 40-50 minutes**

> **Focus:** new/delete, memory leaks, dynamic arrays

---

## PROBLEM 1
```cpp
int main() {
    int *p = new int;
    *p = 100;
    cout << *p << endl;
    delete p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
int main() {
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i * 10;
    cout << arr[2] << " " << arr[4];
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
int main() {
    int *p = new int(50);
    int *q = p;
    *q = 75;
    cout << *p;
    delete p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
int main() {
    int *arr = new int[4]{10, 20, 30, 40};
    int *p = arr + 2;
    cout << *p << " " << *(p + 1);
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int* func(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    return arr;
}

int main() {
    int *p = func(5);
    cout << p[0] << " " << p[4];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
int main() {
    int **arr = new int*[3];
    for (int i = 0; i < 3; i++)
        arr[i] = new int[3];
    
    arr[0][0] = 1;
    arr[1][1] = 5;
    arr[2][2] = 9;
    
    cout << arr[0][0] + arr[1][1] + arr[2][2];
    
    for (int i = 0; i < 3; i++)
        delete[] arr[i];
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
    
    int *q = p;
    q++;
    cout << *q;
    
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int* mystery(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = (i + 1) * (i + 1);
    return arr;
}

int main() {
    int *p = mystery(4);
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += p[i];
    cout << sum;
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
int main() {
    int *p = new int(10);
    int *q = new int(20);
    *p = *p + *q;
    cout << *p;
    delete p;
    delete q;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
int main() {
    int **matrix = new int*[2];
    for (int i = 0; i < 2; i++)
        matrix[i] = new int[2];
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    
    cout << matrix[0][1] + matrix[1][0];
    
    for (int i = 0; i < 2; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
int* create(int size, int val) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = val;
    return arr;
}

int main() {
    int *p = create(5, 7);
    cout << p[0] + p[4];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
int main() {
    int *arr = new int[6];
    for (int i = 0; i < 6; i++)
        arr[i] = i * 2;
    
    int *p = arr + 3;
    cout << *p << " " << *(p - 1);
    
    delete[] arr;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
int main() {
    int **p = new int*[2];
    p[0] = new int(100);
    p[1] = new int(200);
    
    cout << *p[0] + *p[1];
    
    delete p[0];
    delete p[1];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int* func() {
    int *arr = new int[3]{5, 10, 15};
    return arr;
}

int main() {
    int *p = func();
    p[1] = p[1] * 2;
    cout << p[0] + p[1] + p[2];
    delete[] p;
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
int main() {
    int *p = new int[4];
    for (int i = 0; i < 4; i++)
        p[i] = (i + 1) * 3;
    
    int *q = p + 1;
    cout << *q + *(q + 2);
    
    delete[] p;
    return 0;
}
```
**What is the output?**

---

**Solutions:** `session4_batch1_solutions.md`
