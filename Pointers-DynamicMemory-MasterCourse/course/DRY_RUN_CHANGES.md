# DRY RUN CHANGES - SUMMARY

## Changes Made

Fixed all dry run problems starting from dynamic memory allocation onwards to remove hint-giving function names that made problems too easy to solve.

---

## Files Modified

### 1. **Practice_04_Dynamic1D.md**
- **Problem 7**: `createArray` → `process`
  - Changed parameters: `size` → `n`, `arr` → `data`, `myArr` → `result`
  - Students must now trace what the function does without the hint
  
- **Problem 10**: `merge` → `func`
  - Changed parameters: `a1, s1, a2, s2` → `x, a, y, b`
  - Changed variables: `result` → `z`, `merged` → `result`
  - Eliminates obvious "merging" hint

---

### 2. **Practice_05_Dynamic2D.md**
- **Problem 8**: `createMatrix` → `func`
  - Changed variable: `mat` → `data`
  - Students can't immediately tell it creates a matrix
  
- **Problem 10**: `createAndFill` → `process`
  - Changed variable: `mat` → `data`
  - Removes hint about both creation and filling

---

### 3. **Practice_06_Advanced.md**
- **Problem 6**: `createMatrix` → `func`
  - No longer immediately obvious it creates a matrix
  
- **Problem 9**: `create` → `process`
  - Removed comment "// Identity matrix" to avoid hint
  - Students must trace to realize it creates identity matrix
  
- **Problem 10**: `merge` → `func`
  - Changed parameters: `sa, sb` → `sa, sb` (kept same for sorted array logic)
  - Changed variable: `merged` → `result`
  - Must trace the sorted merge logic

---

## Why These Changes Matter

### Before:
```cpp
int* merge(int* a1, int s1, int* a2, int s2) {
    // Function name tells you it merges
    // You can guess output without tracing
```

### After:
```cpp
int* func(int* x, int a, int* y, int b) {
    // Must actually trace the logic
    // No hints from name or parameters
```

---

## Impact

**Practice Set 4:** 2 problems fixed (Problems 7, 10)  
**Practice Set 5:** 2 problems fixed (Problems 8, 10)  
**Practice Set 6:** 3 problems fixed (Problems 6, 9, 10)  

**Total:** 7 dry run problems made significantly harder and more realistic for exam preparation.

---

## What Remains Unchanged

### Mock Exam - Section C (Code Writing)
- `createMatrix`, `transpose`, `deallocate` kept as-is
- **Reason:** These are function signatures students must implement
- Descriptive names are appropriate here - students write the code, not trace it

### Dry Run Problems Without Functions
- Problems 1-9 in earlier practice sets
- These don't have function names that give hints
- Already challenging as-is

---

## Student Experience Now

Students can NO LONGER:
- ❌ See `createArray` and assume it creates an array
- ❌ See `merge` and assume it merges arrays
- ❌ See `createMatrix` and know it's making a matrix
- ❌ Scan function names for quick answers

Students MUST:
- ✅ Trace code line by line
- ✅ Track pointer values manually
- ✅ Understand actual logic flow
- ✅ Work through the dry run properly

---

*Changes completed to ensure genuine dry run practice that builds real tracing skills.*
