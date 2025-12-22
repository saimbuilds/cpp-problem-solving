# SESSION 1 - BATCH 1: EASY WARMUP PROBLEMS
**Total Problems: 15 | Estimated Time: 30-40 minutes**

> **Instructions:** 
> - Attempt ALL problems WITHOUT looking at solutions
> - Write your answers on paper or in a separate file
> - Draw memory diagrams when helpful
> - After attempting all, check `session1_batch1_solutions.md`

---

## PROBLEM 1: Basic Pointer Declaration
```cpp
int main() {
    int x = 5;
    int *p = &x;
    
    cout << x << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2: Pointer Value Modification
```cpp
int main() {
    int x = 10;
    int *p = &x;
    
    *p = 20;
    
    cout << x << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3: Multiple Pointers
```cpp
int main() {
    int x = 15;
    int *p = &x;
    int *q = &x;
    
    *p = 25;
    
    cout << *q << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4: Pointer Arithmetic Basics
```cpp
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    
    cout << *p << endl;
    cout << *(p + 2) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5: Pointer Increment
```cpp
int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p = arr;
    
    p++;
    cout << *p << endl;
    
    p++;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6: Array Indexing with Pointers
```cpp
int main() {
    int arr[4] = {100, 200, 300, 400};
    int *p = arr;
    
    cout << p[0] << endl;
    cout << p[2] << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7: Pointer and Array Equivalence
```cpp
int main() {
    int arr[3] = {7, 14, 21};
    
    cout << arr[1] << endl;
    cout << *(arr + 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8: Two Pointers Same Array
```cpp
int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    int *p = arr;
    int *q = arr + 3;
    
    cout << *p << endl;
    cout << *q << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9: Pointer Arithmetic Expression
```cpp
int main() {
    int arr[6] = {1, 3, 5, 7, 9, 11};
    int *p = arr + 2;
    
    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << *(p - 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10: Character Pointer Basics
```cpp
int main() {
    char ch = 'A';
    char *p = &ch;
    
    cout << ch << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11: Character Array Pointer
```cpp
int main() {
    char str[] = "hello";
    char *p = str;
    
    cout << *p << endl;
    cout << *(p + 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12: Modifying Through Pointer
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr + 1;
    
    *p = 99;
    
    cout << arr[1] << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13: Pointer Swap Values
```cpp
int main() {
    int x = 5, y = 10;
    int *a = &x;
    int *b = &y;
    
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    
    cout << x << endl;
    cout << y << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14: Pointer to First and Last
```cpp
int main() {
    int arr[5] = {11, 22, 33, 44, 55};
    int *first = arr;
    int *last = arr + 4;
    
    cout << *first + *last << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15: Character Pointer Arithmetic
```cpp
int main() {
    char str[] = "world";
    char *p = str + 2;
    
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## ✅ CHECKPOINT

**Before checking solutions, ask yourself:**
1. Did I attempt ALL 15 problems?
2. Did I write down my answers?
3. Did I draw memory diagrams for confusing ones?

**If YES to all three, proceed to `session1_batch1_solutions.md`**

**If NO, go back and complete them! No shortcuts! 💪**

---

**Next:** After checking solutions, move to `session1_batch2_problems.md` for medium difficulty!
