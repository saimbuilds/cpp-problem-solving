# ⚡ ULTRA-QUICK REFERENCE CARD
## For Last-Minute Cramming

> Print this, fold it, keep in pocket

---

## 🎯 POINTER RULES (30 sec)

```
int*      → pointer to int (1D array, single var)
int**     → pointer to pointer (2D array)
int&      → reference (can't reassign, no null)
int*&     → reference to pointer (modify pointer)

nullptr cast:
(char*)nullptr  → prints nothing (C-string)
(int*)nullptr   → prints 0x0 (address)
```

---

## 📊 2D ARRAY QUICK FORMULAS (1 min)

| Operation | Formula |
|-----------|---------|
| **Transpose** | `swap(arr[i][j], arr[j][i])` where j=i+1 to n |
| **Rotate 90° CW** | Transpose + reverse rows |
| **Rotate 90° CCW** | Transpose + reverse cols |
| **Main Diagonal** | `arr[i][i]` |
| **Anti-Diagonal** | `arr[i][n-1-i]` |
| **Spiral** | 4 boundaries: top, bottom, left, right |

---

## 🔁 RECURSION BASE CASES (30 sec)

```cpp
Factorial:   if(n <= 1) return 1;
Fibonacci:   if(n <= 1) return n;
Pell:        if(n <= 1) return n; // then 2*P(n-1)+P(n-2)
Array:       if(n == 0) return 0;
String:      if(left >= right) return;
```

---

## 💾 MEMORY ALLOCATION (30 sec)

```cpp
// 1D
int* arr = new int[n];
delete[] arr;

// 2D
int** mat = new int*[rows];
for(i=0; i<rows; i++) mat[i] = new int[cols];

// DEALLOCATION (reverse!)
for(i=0; i<rows; i++) delete[] mat[i];
delete[] mat;
```

---

## 🎲 FAMOUS ALGORITHMS (1 min)

### Reverse Array
```cpp
left=0, right=n-1
while(left < right) { swap(arr[left++], arr[right--]); }
```

### Remove Duplicates (Sorted)
```cpp
unique=0
for(i=1; i<n; i++)
  if(arr[i] != arr[unique]) arr[++unique] = arr[i]
return unique+1
```

### Palindrome
```cpp
left=0, right=n-1
while(left < right)
  if(str[left++] != str[right--]) return false
return true
```

---

## 🔢 LOOP BOUNDS (15 sec)

```cpp
for(i=0; i<n; i++)    // 0 to n-1 ✅
for(i=0; i<=n; i++)   // 0 to n ⚠️ (extra iteration)
for(i=1; i<=n; i++)   // 1 to n ✅
```

---

## 🎮 PROJECT QUICK HITS (45 sec)

**Parallel Arrays:**
```cpp
float x[MAX], y[MAX], speed[MAX];
// Same index = same entity
```

**AABB Collision:**
```cpp
x1 < x2+w2 && x1+w1 > x2 && y1 < y2+h2 && y1+h1 > y2
```

**Grid ↔ Pixel:**
```cpp
gridPos = pixelPos / cellSize
pixelPos = gridPos * cellSize
```

**Diagonal Check:**
```cpp
if(row - col == 1) // diagonal pattern
```

---

## ⚠️ COMMON TRAPS (30 sec)

- ❌ `arr[n]` → should be `arr[n-1]` (last element)
- ❌ Forgetting `delete[]` after `new[]`
- ❌ `j=0` in transpose → should be `j=i+1`
- ❌ Writing in rough work area (won't be marked)
- ❌ No base case in recursion = infinite loop

---

## 🎯 IN-EXAM STRATEGY (30 sec)

**First 5 min:**
1. Read all questions
2. Mark: ✅ easy, ⚠️ medium, ❌ hard
3. Plan time allocation

**Attack order:**
1. All ✅ questions
2. All ⚠️ questions  
3. All ❌ questions
4. Review (last 20 min)

**If stuck:** Skip, come back. Partial credit > 0.

---

## 💪 CONFIDENCE MANTRAS (15 sec)

- You built a 4765-line game
- You know patterns, not just syntax
- Partial credit exists
- Neatness = free marks
- You've got this! 🚀

---

**TOTAL READ TIME: ~5 MINUTES**

**USE THIS:** In exam hall before paper arrives
