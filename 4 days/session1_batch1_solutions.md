# SESSION 1 - BATCH 1: SOLUTIONS
**Easy Warmup Problems - Detailed Explanations**

---

## SOLUTION 1: Basic Pointer Declaration
```cpp
int main() {
    int x = 5;
    int *p = &x;
    
    cout << x << endl;
    cout << *p << endl;
    
    return 0;
}
```

**Output:**
```
5
5
```

**Explanation:**
- `x` is 5
- `p` stores the address of `x`
- `*p` dereferences `p`, giving us the value at that address, which is `x` (5)

**Memory Diagram:**
```
x: [5] at 0x1000
p: [0x1000] at 0x2000
```

---

## SOLUTION 2: Pointer Value Modification
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

**Output:**
```
20
20
```

**Explanation:**
- Initially `x = 10`
- `p` points to `x`
- `*p = 20` changes the value at the address `p` points to (which is `x`)
- So `x` becomes 20
- Both `x` and `*p` now show 20

**Key Insight:** Modifying `*p` modifies `x` because they refer to the same memory location!

---

## SOLUTION 3: Multiple Pointers
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

**Output:**
```
25
```

**Explanation:**
- Both `p` and `q` point to `x`
- When we change `*p` to 25, we're changing `x`
- Since `q` also points to `x`, `*q` also shows 25

**Memory Diagram:**
```
x: [25] at 0x1000
     ↑
     |
p: [0x1000]
q: [0x1000]
```

---

## SOLUTION 4: Pointer Arithmetic Basics
```cpp
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    
    cout << *p << endl;
    cout << *(p + 2) << endl;
    
    return 0;
}
```

**Output:**
```
10
30
```

**Explanation:**
- `p` points to `arr[0]` which is 10
- `p + 2` points to `arr[2]` which is 30
- `*(p + 2)` dereferences to get the value 30

**Memory Layout:**
```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
[10]    [20]    [30]    [40]    [50]
 ↑               ↑
 p              p+2
```

---

## SOLUTION 5: Pointer Increment
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

**Output:**
```
10
15
```

**Explanation:**
- Initially `p` points to `arr[0]` (5)
- First `p++` moves `p` to `arr[1]` (10)
- Second `p++` moves `p` to `arr[2]` (15)

**Step-by-step:**
```
Initial: p → arr[0] (5)
After p++: p → arr[1] (10) → prints 10
After p++: p → arr[2] (15) → prints 15
```

---

## SOLUTION 6: Array Indexing with Pointers
```cpp
int main() {
    int arr[4] = {100, 200, 300, 400};
    int *p = arr;
    
    cout << p[0] << endl;
    cout << p[2] << endl;
    
    return 0;
}
```

**Output:**
```
100
300
```

**Explanation:**
- `p` points to `arr[0]`
- `p[0]` is same as `*(p + 0)` which is `arr[0]` = 100
- `p[2]` is same as `*(p + 2)` which is `arr[2]` = 300

**Key Insight:** You can use array notation `[]` with pointers!

---

## SOLUTION 7: Pointer and Array Equivalence
```cpp
int main() {
    int arr[3] = {7, 14, 21};
    
    cout << arr[1] << endl;
    cout << *(arr + 1) << endl;
    
    return 0;
}
```

**Output:**
```
14
14
```

**Explanation:**
- `arr[1]` is the standard way to access the second element
- `*(arr + 1)` is the pointer arithmetic way
- Both are **exactly equivalent**!

**Key Insight:** `arr[i]` is just syntactic sugar for `*(arr + i)`

---

## SOLUTION 8: Two Pointers Same Array
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

**Output:**
```
2
8
```

**Explanation:**
- `p` points to `arr[0]` = 2
- `q` points to `arr[3]` = 8

**Memory Layout:**
```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
[2]     [4]     [6]     [8]     [10]
 ↑                       ↑
 p                       q
```

---

## SOLUTION 9: Pointer Arithmetic Expression
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

**Output:**
```
5
7
3
```

**Explanation:**
- `p = arr + 2` means `p` points to `arr[2]` = 5
- `*(p + 1)` points to `arr[3]` = 7
- `*(p - 1)` points to `arr[1]` = 3

**Memory Layout:**
```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]  arr[5]
[1]     [3]     [5]     [7]     [9]     [11]
         ↑       ↑       ↑
        p-1      p      p+1
```

---

## SOLUTION 10: Character Pointer Basics
```cpp
int main() {
    char ch = 'A';
    char *p = &ch;
    
    cout << ch << endl;
    cout << *p << endl;
    
    return 0;
}
```

**Output:**
```
A
A
```

**Explanation:**
- `ch` is 'A'
- `p` points to `ch`
- `*p` dereferences to get 'A'

**Note:** Same concept as integer pointers, just with characters!

---

## SOLUTION 11: Character Array Pointer
```cpp
int main() {
    char str[] = "hello";
    char *p = str;
    
    cout << *p << endl;
    cout << *(p + 1) << endl;
    
    return 0;
}
```

**Output:**
```
h
e
```

**Explanation:**
- `str` is a character array: `['h', 'e', 'l', 'l', 'o', '\0']`
- `p` points to `str[0]` = 'h'
- `*(p + 1)` points to `str[1]` = 'e'

**Memory Layout:**
```
str[0]  str[1]  str[2]  str[3]  str[4]  str[5]
['h']   ['e']   ['l']   ['l']   ['o']   ['\0']
  ↑      ↑
  p     p+1
```

---

## SOLUTION 12: Modifying Through Pointer
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr + 1;
    
    *p = 99;
    
    cout << arr[1] << endl;
    
    return 0;
}
```

**Output:**
```
99
```

**Explanation:**
- `p` points to `arr[1]` (which is 20)
- `*p = 99` changes `arr[1]` to 99
- So `arr[1]` is now 99

**Before:** `arr = {10, 20, 30, 40}`  
**After:** `arr = {10, 99, 30, 40}`

---

## SOLUTION 13: Pointer Swap Values
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

**Output:**
```
10
5
```

**Explanation:**
This is a swap without temp variable!

**Step-by-step:**
1. Initially: `x = 5`, `y = 10`
2. `*a = *a + *b` → `x = 5 + 10 = 15`
3. `*b = *a - *b` → `y = 15 - 10 = 5`
4. `*a = *a - *b` → `x = 15 - 5 = 10`

**Final:** `x = 10`, `y = 5` (swapped!)

---

## SOLUTION 14: Pointer to First and Last
```cpp
int main() {
    int arr[5] = {11, 22, 33, 44, 55};
    int *first = arr;
    int *last = arr + 4;
    
    cout << *first + *last << endl;
    
    return 0;
}
```

**Output:**
```
66
```

**Explanation:**
- `first` points to `arr[0]` = 11
- `last` points to `arr[4]` = 55
- `*first + *last` = 11 + 55 = 66

---

## SOLUTION 15: Character Pointer Arithmetic
```cpp
int main() {
    char str[] = "world";
    char *p = str + 2;
    
    cout << *p << endl;
    
    return 0;
}
```

**Output:**
```
r
```

**Explanation:**
- `str` = `['w', 'o', 'r', 'l', 'd', '\0']`
- `p = str + 2` points to `str[2]` = 'r'
- `*p` gives 'r'

**Memory Layout:**
```
str[0]  str[1]  str[2]  str[3]  str[4]  str[5]
['w']   ['o']   ['r']   ['l']   ['d']   ['\0']
                 ↑
                 p
```

---

## 🎯 KEY TAKEAWAYS FROM BATCH 1

1. **Pointers store addresses** - Use `&` to get address, `*` to get value
2. **Modifying `*p` modifies the original variable** - They share the same memory
3. **Pointer arithmetic** - `p + i` moves `i` elements forward
4. **Array name is a pointer** - `arr` is same as `&arr[0]`
5. **`arr[i]` = `*(arr + i)`** - Two ways to access same element
6. **Multiple pointers can point to same location** - Changes through one affect all

---

## 📊 HOW DID YOU DO?

- **15/15 correct:** EXCELLENT! You've got the basics down! 🔥
- **12-14 correct:** GOOD! Review the ones you missed
- **9-11 correct:** OKAY! You need more practice on basics
- **< 9 correct:** Go back to theory, then retry these problems

---

## ✅ NEXT STEP

**Ready for medium difficulty?**

Open `session1_batch2_problems.md` for 20 medium-level pointer problems!

**Not ready yet?**
- Review the theory again
- Retry the problems you got wrong
- Draw more memory diagrams

**Remember:** Mastery comes from repetition! 💪
