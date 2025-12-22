# SESSION 1 - BATCH 2: MEDIUM DIFFICULTY PROBLEMS
**Total Problems: 20 | Estimated Time: 45-60 minutes**

> **Instructions:** 
> - These are MEDIUM difficulty - expect to think harder!
> - Draw memory diagrams for complex ones
> - Trace step-by-step for multi-line code
> - Check solutions only after attempting ALL problems

---

## PROBLEM 1: Pointer Reassignment
```cpp
int main() {
    int x = 10, y = 20;
    int *p = &x;
    
    cout << *p << endl;
    
    p = &y;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2: Multiple Modifications
```cpp
int main() {
    int arr[4] = {5, 10, 15, 20};
    int *p = arr + 1;
    
    *p = 100;
    *(p + 1) = 200;
    
    cout << arr[1] << " " << arr[2] << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3: Pointer Arithmetic Chain
```cpp
int main() {
    int arr[6] = {2, 4, 6, 8, 10, 12};
    int *p = arr;
    
    p = p + 3;
    p = p - 1;
    
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4: Two Pointers Interaction
```cpp
int main() {
    int arr[5] = {11, 22, 33, 44, 55};
    int *p1 = arr + 1;
    int *p2 = arr + 3;
    
    cout << *p1 * *p2 << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5: Pointer Loop
```cpp
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    
    for (int i = 0; i < 3; i++) {
        cout << *p << " ";
        p++;
    }
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6: Dereferencing Before and After
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr + 2;
    
    cout << *p++ << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**
**Hint:** `*p++` is tricky! Postfix `++` has higher precedence.

---

## PROBLEM 7: Pointer Difference
```cpp
int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p1 = arr + 1;
    int *p2 = arr + 4;
    
    cout << p2 - p1 << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8: Character String Pointer
```cpp
int main() {
    char str[] = "programming";
    char *p = str + 3;
    
    cout << p << endl;
    
    return 0;
}
```
**What is the output?**
**Remember:** `cout << p` prints the entire string from `p`!

---

## PROBLEM 9: Modifying Character Array
```cpp
int main() {
    char str[] = "hello";
    char *p = str;
    
    *p = 'H';
    *(p + 4) = 'O';
    
    cout << str << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10: Nested Dereference
```cpp
int main() {
    int x = 100;
    int *p = &x;
    int **pp = &p;
    
    cout << **pp << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11: Pointer to Pointer Modification
```cpp
int main() {
    int x = 50;
    int *p = &x;
    int **pp = &p;
    
    **pp = 75;
    
    cout << x << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12: Array Sum with Pointers
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr;
    int sum = 0;
    
    for (int i = 0; i < 4; i++) {
        sum += *(p + i);
    }
    
    cout << sum << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13: Pointer Comparison
```cpp
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = arr + 2;
    int *p2 = arr + 2;
    
    if (p1 == p2)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14: Complex Pointer Expression
```cpp
int main() {
    int arr[5] = {3, 6, 9, 12, 15};
    int *p = arr + 1;
    
    cout << *(p + 2) - *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 15: Pointer with Pre-increment
```cpp
int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p = arr;
    
    cout << *++p << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**
**Hint:** `*++p` increments `p` FIRST, then dereferences.

---

## PROBLEM 16: 2D Array Pointer Basics
```cpp
int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    cout << arr[0][1] << endl;
    cout << *(*(arr + 0) + 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 17: 2D Array Row Pointer
```cpp
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *p = arr[1];
    
    cout << *p << endl;
    cout << *(p + 2) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 18: Character Pointer Increment
```cpp
int main() {
    char str[] = "code";
    char *p = str;
    
    while (*p != '\0') {
        cout << *p;
        p++;
    }
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 19: Pointer Array Modification
```cpp
int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    int *p = arr;
    
    for (int i = 0; i < 5; i++) {
        *p = *p * 2;
        p++;
    }
    
    cout << arr[0] << " " << arr[2] << " " << arr[4] << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 20: Mixed Pointer Operations
```cpp
int main() {
    int x = 10, y = 20, z = 30;
    int *p = &x;
    int *q = &y;
    
    *p = *q;
    q = &z;
    *q = 40;
    
    cout << x << " " << y << " " << z << endl;
    
    return 0;
}
```
**What is the output?**

---

## ✅ CHECKPOINT

**Before checking solutions:**
1. Did you attempt ALL 20 problems?
2. Did you draw memory diagrams for confusing ones?
3. Did you trace step-by-step for multi-line problems?
4. Did you pay attention to `*p++` vs `*++p`?

**If YES, proceed to `session1_batch2_solutions.md`**

---

**Feeling stuck?**
- Review the theory on pointer arithmetic
- Draw memory diagrams
- Trace line by line
- Don't give up! These are MEDIUM difficulty for a reason!

**Next:** After solutions, move to `session1_batch3_problems.md` for HARD challenges! 🔥
