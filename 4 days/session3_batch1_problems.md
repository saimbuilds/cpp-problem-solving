# SESSION 3 - BATCH 1: EASY FUSION PROBLEMS
**Total: 12 problems | Time: 30-40 minutes**

## PROBLEM 1
```cpp
void modify(int *p) {
    *p = *p + 10;
}

int main() {
    int x = 5;
    modify(&x);
    cout << x;
    return 0;
}
```
**Output?**

## PROBLEM 2
```cpp
int sumArray(int *arr, int n) {
    if (n == 0)
        return 0;
    return *arr + sumArray(arr + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    cout << sumArray(arr, 4);
    return 0;
}
```
**Output?**

## PROBLEM 3
```cpp
void printArray(int *arr, int n) {
    if (n == 0)
        return;
    cout << *arr << " ";
    printArray(arr + 1, n - 1);
}

int main() {
    int arr[] = {5, 10, 15};
    printArray(arr, 3);
    return 0;
}
```
**Output?**

## PROBLEM 4
```cpp
void modify(int& x, int n) {
    if (n == 0)
        return;
    x += n;
    modify(x, n - 1);
}

int main() {
    int x = 0;
    modify(x, 3);
    cout << x;
    return 0;
}
```
**Output?**

## PROBLEM 5
```cpp
int findMax(int *arr, int n) {
    if (n == 1)
        return *arr;
    int maxRest = findMax(arr + 1, n - 1);
    return (*arr > maxRest) ? *arr : maxRest;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    cout << findMax(arr, 5);
    return 0;
}
```
**Output?**

## PROBLEM 6
```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    cout << x << " " << y;
    return 0;
}
```
**Output?**

## PROBLEM 7
```cpp
void increment(int *p, int n) {
    if (n == 0)
        return;
    (*p)++;
    increment(p, n - 1);
}

int main() {
    int x = 5;
    increment(&x, 3);
    cout << x;
    return 0;
}
```
**Output?**

## PROBLEM 8
```cpp
int countEven(int *arr, int n) {
    if (n == 0)
        return 0;
    if (*arr % 2 == 0)
        return 1 + countEven(arr + 1, n - 1);
    return countEven(arr + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << countEven(arr, 6);
    return 0;
}
```
**Output?**

## PROBLEM 9
```cpp
void reverseArray(int *start, int *end) {
    if (start >= end)
        return;
    int temp = *start;
    *start = *end;
    *end = temp;
    reverseArray(start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, arr + 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**Output?**

## PROBLEM 10
```cpp
void doubleValues(int *arr, int n) {
    if (n == 0)
        return;
    *arr *= 2;
    doubleValues(arr + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3};
    doubleValues(arr, 3);
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**Output?**

## PROBLEM 11
```cpp
int productArray(int *arr, int n) {
    if (n == 0)
        return 1;
    return (*arr) * productArray(arr + 1, n - 1);
}

int main() {
    int arr[] = {2, 3, 4};
    cout << productArray(arr, 3);
    return 0;
}
```
**Output?**

## PROBLEM 12
```cpp
void addToAll(int *arr, int n, int val) {
    if (n == 0)
        return;
    *arr += val;
    addToAll(arr + 1, n - 1, val);
}

int main() {
    int arr[] = {1, 2, 3};
    addToAll(arr, 3, 10);
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    return 0;
}
```
**Output?**

**Solutions:** `session3_batch1_solutions.md`
