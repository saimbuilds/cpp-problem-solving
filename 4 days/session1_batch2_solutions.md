# SESSION 1 - BATCH 2: SOLUTIONS
**Medium Difficulty Problems - Detailed Explanations**

---

## SOLUTION 1: Pointer Reassignment
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

**Output:**
```
10
20
```

**Explanation:**
- Initially `p` points to `x` (10)
- `p = &y` makes `p` point to `y` instead
- Now `*p` gives value of `y` (20)

**Key Insight:** Reassigning a pointer changes what it points to!

---

## SOLUTION 2: Multiple Modifications
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

**Output:**
```
100 200
```

**Explanation:**
- `p` points to `arr[1]`
- `*p = 100` changes `arr[1]` to 100
- `*(p + 1)` points to `arr[2]`, changes it to 200

**Before:** `{5, 10, 15, 20}`  
**After:** `{5, 100, 200, 20}`

---

## SOLUTION 3: Pointer Arithmetic Chain
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

**Output:**
```
6
```

**Explanation:**
- Initially `p` points to `arr[0]`
- `p = p + 3` → `p` points to `arr[3]` (8)
- `p = p - 1` → `p` points to `arr[2]` (6)

**Step-by-step:**
```
p → arr[0] (2)
p + 3 → arr[3] (8)
p - 1 → arr[2] (6)
```

---

## SOLUTION 4: Two Pointers Interaction
```cpp
int main() {
    int arr[5] = {11, 22, 33, 44, 55};
    int *p1 = arr + 1;
    int *p2 = arr + 3;
    
    cout << *p1 * *p2 << endl;
    
    return 0;
}
```

**Output:**
```
968
```

**Explanation:**
- `p1` points to `arr[1]` = 22
- `p2` points to `arr[3]` = 44
- `*p1 * *p2` = 22 × 44 = 968

---

## SOLUTION 5: Pointer Loop
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

**Output:**
```
1 2 3 
```

**Explanation:**
- **Iteration 1:** `p` → `arr[0]` (1), print 1, then `p++`
- **Iteration 2:** `p` → `arr[1]` (2), print 2, then `p++`
- **Iteration 3:** `p` → `arr[2]` (3), print 3, then `p++`

---

## SOLUTION 6: Dereferencing Before and After
```cpp
int main() {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr + 2;
    
    cout << *p++ << endl;
    cout << *p << endl;
    
    return 0;
}
```

**Output:**
```
30
40
```

**Explanation:**
- `*p++` is tricky! Postfix `++` has higher precedence
- It means: dereference `p` (get 30), THEN increment `p`
- So first line prints 30, then `p` moves to `arr[3]`
- Second line prints `*p` which is now 40

**CRITICAL:** `*p++` = dereference first, increment after  
**Compare:** `*++p` = increment first, dereference after

---

## SOLUTION 7: Pointer Difference
```cpp
int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p1 = arr + 1;
    int *p2 = arr + 4;
    
    cout << p2 - p1 << endl;
    
    return 0;
}
```

**Output:**
```
3
```

**Explanation:**
- `p1` points to `arr[1]`
- `p2` points to `arr[4]`
- `p2 - p1` gives the **number of elements** between them = 3

**Not bytes!** It's the number of elements (4 - 1 = 3)

---

## SOLUTION 8: Character String Pointer
```cpp
int main() {
    char str[] = "programming";
    char *p = str + 3;
    
    cout << p << endl;
    
    return 0;
}
```

**Output:**
```
gramming
```

**Explanation:**
- `str` = `"programming"`
- `p` points to `str[3]` which is 'g'
- `cout << p` prints from 'g' to null terminator
- So it prints "gramming"

**Remember:** `cout` with `char*` prints the entire string from that pointer!

---

## SOLUTION 9: Modifying Character Array
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

**Output:**
```
HellO
```

**Explanation:**
- `*p` points to `str[0]`, change 'h' to 'H'
- `*(p + 4)` points to `str[4]`, change 'o' to 'O'

**Before:** `"hello"`  
**After:** `"HellO"`

---

## SOLUTION 10: Nested Dereference
```cpp
int main() {
    int x = 100;
    int *p = &x;
    int **pp = &p;
    
    cout << **pp << endl;
    
    return 0;
}
```

**Output:**
```
100
```

**Explanation:**
- `p` points to `x`
- `pp` points to `p`
- `*pp` gives value of `p` (which is address of `x`)
- `**pp` gives value at that address (which is `x` = 100)

**Memory Chain:**
```
x: [100]
   ↑
p: [&x]
   ↑
pp: [&p]

**pp → *pp → x → 100
```

---

## SOLUTION 11: Pointer to Pointer Modification
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

**Output:**
```
75
```

**Explanation:**
- `**pp` refers to `x`
- `**pp = 75` changes `x` to 75

**Chain:** `pp` → `p` → `x`, so `**pp` = `x`

---

## SOLUTION 12: Array Sum with Pointers
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

**Output:**
```
100
```

**Explanation:**
- Loop adds: `arr[0] + arr[1] + arr[2] + arr[3]`
- = 10 + 20 + 30 + 40 = 100

---

## SOLUTION 13: Pointer Comparison
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

**Output:**
```
Equal
```

**Explanation:**
- Both `p1` and `p2` point to `arr[2]`
- They have the **same address**
- So `p1 == p2` is true

---

## SOLUTION 14: Complex Pointer Expression
```cpp
int main() {
    int arr[5] = {3, 6, 9, 12, 15};
    int *p = arr + 1;
    
    cout << *(p + 2) - *p << endl;
    
    return 0;
}
```

**Output:**
```
6
```

**Explanation:**
- `p` points to `arr[1]` = 6
- `*(p + 2)` points to `arr[3]` = 12
- `*(p + 2) - *p` = 12 - 6 = 6

---

## SOLUTION 15: Pointer with Pre-increment
```cpp
int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p = arr;
    
    cout << *++p << endl;
    cout << *p << endl;
    
    return 0;
}
```

**Output:**
```
10
10
```

**Explanation:**
- `*++p` increments `p` FIRST (to `arr[1]`), then dereferences
- So first line prints 10
- `p` is now at `arr[1]`, so second line also prints 10

**CRITICAL:** `*++p` = increment first, dereference after  
**Compare:** `*p++` = dereference first, increment after

---

## SOLUTION 16: 2D Array Pointer Basics
```cpp
int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    cout << arr[0][1] << endl;
    cout << *(*(arr + 0) + 1) << endl;
    
    return 0;
}
```

**Output:**
```
2
2
```

**Explanation:**
- `arr[0][1]` is standard notation = 2
- `*(*(arr + 0) + 1)` is pointer notation:
  - `arr + 0` → pointer to row 0
  - `*(arr + 0)` → pointer to first element of row 0
  - `*(arr + 0) + 1` → pointer to second element of row 0
  - `*(*(arr + 0) + 1)` → value at that position = 2

**Both are equivalent!**

---

## SOLUTION 17: 2D Array Row Pointer
```cpp
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *p = arr[1];
    
    cout << *p << endl;
    cout << *(p + 2) << endl;
    
    return 0;
}
```

**Output:**
```
4
6
```

**Explanation:**
- `arr[1]` gives pointer to row 1: `{4, 5, 6}`
- `*p` gives first element = 4
- `*(p + 2)` gives third element = 6

---

## SOLUTION 18: Character Pointer Increment
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

**Output:**
```
code
```

**Explanation:**
- Loop prints each character until null terminator
- **Iteration 1:** `*p` = 'c', print, `p++`
- **Iteration 2:** `*p` = 'o', print, `p++`
- **Iteration 3:** `*p` = 'd', print, `p++`
- **Iteration 4:** `*p` = 'e', print, `p++`
- **Iteration 5:** `*p` = '\0', exit loop

---

## SOLUTION 19: Pointer Array Modification
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

**Output:**
```
4 12 20
```

**Explanation:**
- Loop doubles each element:
  - `arr[0]`: 2 × 2 = 4
  - `arr[1]`: 4 × 2 = 8
  - `arr[2]`: 6 × 2 = 12
  - `arr[3]`: 8 × 2 = 16
  - `arr[4]`: 10 × 2 = 20

**Final array:** `{4, 8, 12, 16, 20}`

---

## SOLUTION 20: Mixed Pointer Operations
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

**Output:**
```
20 20 40
```

**Explanation:**
**Step-by-step:**
1. `*p = *q` → `x = y` → `x = 20`
2. `q = &z` → `q` now points to `z`
3. `*q = 40` → `z = 40`

**Final:** `x = 20`, `y = 20` (unchanged from step 1), `z = 40`

---

## 🎯 KEY TAKEAWAYS FROM BATCH 2

1. **`*p++` vs `*++p`** - Postfix increments after, prefix increments before
2. **Pointer reassignment** - Changes what pointer points to
3. **Pointer difference** - Gives number of elements, not bytes
4. **`cout` with `char*`** - Prints entire string from that pointer
5. **Pointer to pointer** - `**pp` accesses the original value
6. **2D arrays** - `arr[i][j]` = `*(*(arr + i) + j)`

---

## 📊 HOW DID YOU DO?

- **18-20 correct:** EXCELLENT! You're crushing it! 🔥
- **15-17 correct:** VERY GOOD! Minor review needed
- **12-14 correct:** GOOD! Review tricky concepts
- **< 12 correct:** Review theory and retry

---

## ✅ NEXT STEP

**Ready for HARD problems?**

Open `session1_batch3_problems.md` for 15 challenging pointer problems!

These will include:
- Complex 2D array manipulation
- Nested pointer operations
- Tricky pointer arithmetic
- Past paper style questions

**Take a 5-minute break first! You've earned it! 💪**
