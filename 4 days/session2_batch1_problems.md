# SESSION 2 - BATCH 1: EASY RECURSION WARMUP
**Total Problems: 15 | Estimated Time: 30-40 minutes**

> **Instructions:** 
> - Draw call stacks for each problem
> - Trace step-by-step
> - Check solutions only after attempting ALL

---

## PROBLEM 1
```cpp
void func(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    func(n - 1);
}

int main() {
    func(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2
```cpp
int mystery(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * mystery(n - 1);
}

int main() {
    cout << mystery(4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3
```cpp
int calculate(int n) {
    if (n == 0)
        return 0;
    return n + calculate(n - 1);
}

int main() {
    cout << calculate(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4
```cpp
void process(int n) {
    if (n == 0)
        return;
    process(n - 1);
    cout << n << " ";
}

int main() {
    process(4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5
```cpp
int compute(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * compute(base, exp - 1);
}

int main() {
    cout << compute(2, 3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6
```cpp
int func(int n) {
    if (n == 0)
        return 0;
    return 1 + func(n / 10);
}

int main() {
    cout << func(12345);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7
```cpp
int mystery(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + mystery(n / 10);
}

int main() {
    cout << mystery(123);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8
```cpp
int seq(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return seq(n - 1) + seq(n - 2);
}

int main() {
    cout << seq(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9
```cpp
void display(int n) {
    if (n == 0)
        return;
    cout << "*";
    display(n - 1);
}

int main() {
    display(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10
```cpp
int process(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n-1] + process(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    cout << process(arr, 4);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11
```cpp
void func(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    func(n - 1);
}

int main() {
    func(3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12
```cpp
int calculate(int n) {
    if (n == 1)
        return 1;
    return n * calculate(n - 1);
}

int main() {
    cout << calculate(5);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13
```cpp
void show(int n) {
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
        cout << "*";
    cout << endl;
    show(n - 1);
}

int main() {
    show(3);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14
```cpp
int mystery(int a, int b) {
    if (b == 0)
        return a;
    return mystery(b, a % b);
}

int main() {
    cout << mystery(48, 18);
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15
```cpp
int find(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int temp = find(arr, n - 1);
    return (arr[n-1] > temp) ? arr[n-1] : temp;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    cout << find(arr, 5);
    return 0;
}
```
**What is the output?**

---

## ✅ CHECKPOINT

**Before checking solutions:**
1. Did you draw call stacks?
2. Did you trace each recursive call?
3. Did you identify base cases?

**Proceed to `session2_batch1_solutions.md`**
