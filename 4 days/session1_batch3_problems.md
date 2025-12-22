# SESSION 1 - BATCH 3: HARD CHALLENGE PROBLEMS
**Total Problems: 15 | Estimated Time: 50-70 minutes**

> **Instructions:** 
> - These are HARD - expect to struggle!
> - Take your time, draw diagrams
> - These are past paper style questions
> - Don't peek at solutions until you've tried HARD

---

## PROBLEM 1: Complex 2D Array Pointer (Past Paper Style)
```cpp
int main() {
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int *p = arr[1];
    
    cout << *(p + 3) << endl;
    cout << *(p - 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 2: Pointer Arithmetic with 2D Arrays
```cpp
int main() {
    int arr[2][3] = {{10, 20, 30}, {40, 50, 60}};
    
    cout << *(*(arr + 1) + 2) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 3: Character Array Pointer Manipulation (Past Paper Style)
```cpp
int main() {
    char c[3][10] = {"hello", "world", "test"};
    char *p = c[1];
    
    cout << p << endl;
    cout << *(p + 2) << endl;
    cout << p + 3 << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 4: Nested Pointer Arithmetic
```cpp
int main() {
    int x = 5;
    int *p = &x;
    int **pp = &p;
    
    **pp = **pp + 10;
    
    cout << x << " " << *p << " " << **pp << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 5: Complex Pointer Expression (Past Paper Style)
```cpp
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p1 = arr + 1;
    int *p2 = arr + 3;
    
    cout << *p1 * *p2 << endl;
    cout << *(p1 + 1) + *(p2 - 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 6: Tricky Increment/Decrement
```cpp
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr + 2;
    
    cout << *p++ << endl;
    cout << *++p << endl;
    cout << *p << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 7: Pointer Function Pattern (Past Paper Style)
```cpp
int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    int *p = arr;
    int sum = 0;
    
    while (p < arr + 5) {
        sum += *p;
        p += 2;
    }
    
    cout << sum << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 8: 2D Array Row Manipulation
```cpp
int main() {
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int *p1 = arr[0];
    int *p2 = arr[2];
    
    cout << *(p1 + 2) + *(p2 + 1) << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 9: Pointer Swap (Past Paper Style)
```cpp
int main() {
    int x = 100, y = 200;
    int *a = &x, *b = &y;
    int *temp;
    
    temp = a;
    a = b;
    b = temp;
    
    cout << *a << " " << *b << endl;
    cout << x << " " << y << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 10: Complex Character Pointer (Past Paper Style)
```cpp
int main() {
    char str[] = "programming";
    char *p = str + 3;
    
    *p = 'G';
    *(p + 4) = 'A';
    
    cout << str << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 11: Pointer Array Traversal
```cpp
int main() {
    int arr[6] = {5, 10, 15, 20, 25, 30};
    int *p = arr + 5;
    
    for (int i = 0; i < 3; i++) {
        cout << *p << " ";
        p -= 2;
    }
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 12: Mixed Pointer Operations (Past Paper Style)
```cpp
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    
    *(p + 2) = *(p + 1) + *(p + 3);
    
    cout << arr[2] << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 13: Pointer to Pointer Chain
```cpp
int main() {
    int x = 10;
    int *p = &x;
    int **pp = &p;
    int ***ppp = &pp;
    
    ***ppp = 50;
    
    cout << x << " " << *p << " " << **pp << endl;
    
    return 0;
}
```
**What is the output?**

---

## PROBLEM 14: Complex 2D Pointer (Past Paper Style)
```cpp
int main() {
    int arr[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int *p = arr[0] + 3;
    
    cout << *p << endl;
    cout << *(p + 1) << endl;
    
    return 0;
}
```
**What is the output?**
**Hint:** Think about memory layout!

---

## PROBLEM 15: Ultimate Pointer Challenge (Past Paper Style)
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr + 1;
    int *q = arr + 3;
    
    *p = *q;
    q--;
    *q = *p + 10;
    
    cout << arr[1] << " " << arr[2] << " " << arr[3] << endl;
    
    return 0;
}
```
**What is the output?**

---

## ✅ CHECKPOINT

**Before checking solutions:**
1. Did you attempt ALL 15 problems?
2. Did you draw memory diagrams?
3. Did you trace step-by-step?
4. Did you struggle? (Good! That's learning!)

**If YES, proceed to `session1_batch3_solutions.md`**

---

## 🔥 THESE ARE HARD!

**If you're stuck:**
- Draw the memory layout
- Trace line by line
- Remember: 2D arrays are stored row-by-row
- `*p++` vs `*++p` - be careful!
- Pointer arithmetic: `p + i` moves `i` elements

**Don't give up!** These are the types of questions that will appear on your exam!

**After solutions, you'll have completed SESSION 1! 🎉**

Take a break, then move to SESSION 2 (Recursion)!
