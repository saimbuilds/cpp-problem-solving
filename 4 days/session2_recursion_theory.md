# SESSION 2: RECURSION DOMINATION - THEORY & EXAMPLES
**Read Time: 15 minutes | Then dive into problems!**

---

## 🎯 What You'll Master in This Session

1. Recursive thinking and base cases
2. Tracing recursive calls (call stack)
3. Recursive patterns (factorial, fibonacci, etc.)
4. Recursion with arrays
5. Recursion with pointers/references
6. Common recursive patterns from past papers

---

## 📚 PART 1: WHAT IS RECURSION?

### **Definition:**
A function that calls itself to solve a problem by breaking it into smaller subproblems.

### **Two Essential Components:**
1. **Base Case** - When to stop recursing (prevents infinite loop)
2. **Recursive Case** - How to break problem into smaller version

### **Example 1: Simple Countdown**
```cpp
void countdown(int n) {
    if (n == 0) {              // BASE CASE
        cout << "Done!" << endl;
        return;
    }
    cout << n << " ";          // RECURSIVE CASE
    countdown(n - 1);          // Recursive call with smaller problem
}

int main() {
    countdown(3);
    return 0;
}
```

**Output:** `3 2 1 Done!`

**Call Stack Visualization:**
```
countdown(3) → prints 3 → calls countdown(2)
  countdown(2) → prints 2 → calls countdown(1)
    countdown(1) → prints 1 → calls countdown(0)
      countdown(0) → prints "Done!" → returns
    returns to countdown(1)
  returns to countdown(2)
returns to countdown(3)
```

---

## 📚 PART 2: CLASSIC RECURSIVE PATTERNS

### **Pattern 1: Factorial**
```cpp
int factorial(int n) {
    if (n == 0 || n == 1)      // BASE CASE
        return 1;
    return n * factorial(n - 1); // RECURSIVE CASE
}

// factorial(5) = 5 * factorial(4)
//              = 5 * 4 * factorial(3)
//              = 5 * 4 * 3 * factorial(2)
//              = 5 * 4 * 3 * 2 * factorial(1)
//              = 5 * 4 * 3 * 2 * 1
//              = 120
```

**Call Stack:**
```
factorial(5) → 5 * factorial(4)
  factorial(4) → 4 * factorial(3)
    factorial(3) → 3 * factorial(2)
      factorial(2) → 2 * factorial(1)
        factorial(1) → returns 1
      returns 2 * 1 = 2
    returns 3 * 2 = 6
  returns 4 * 6 = 24
returns 5 * 24 = 120
```

---

### **Pattern 2: Fibonacci**
```cpp
int fibonacci(int n) {
    if (n == 0) return 0;      // BASE CASE 1
    if (n == 1) return 1;      // BASE CASE 2
    return fibonacci(n - 1) + fibonacci(n - 2); // RECURSIVE CASE
}

// fibonacci(5) = fibonacci(4) + fibonacci(3)
//              = (fib(3) + fib(2)) + (fib(2) + fib(1))
//              = ...
//              = 5
```

**Sequence:** 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

---

### **Pattern 3: Sum of Digits**
```cpp
int sumDigits(int n) {
    if (n == 0)                // BASE CASE
        return 0;
    return (n % 10) + sumDigits(n / 10); // RECURSIVE CASE
}

// sumDigits(1234) = 4 + sumDigits(123)
//                 = 4 + 3 + sumDigits(12)
//                 = 4 + 3 + 2 + sumDigits(1)
//                 = 4 + 3 + 2 + 1 + sumDigits(0)
//                 = 4 + 3 + 2 + 1 + 0
//                 = 10
```

---

## 📚 PART 3: RECURSION WITH ARRAYS

### **Example 2: Array Sum**
```cpp
int arraySum(int arr[], int n) {
    if (n == 0)                // BASE CASE: empty array
        return 0;
    return arr[n-1] + arraySum(arr, n-1); // Add last element + sum of rest
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << arraySum(arr, 5);  // Output: 15
    return 0;
}
```

**Trace:**
```
arraySum([1,2,3,4,5], 5) = 5 + arraySum([1,2,3,4], 4)
                         = 5 + 4 + arraySum([1,2,3], 3)
                         = 5 + 4 + 3 + arraySum([1,2], 2)
                         = 5 + 4 + 3 + 2 + arraySum([1], 1)
                         = 5 + 4 + 3 + 2 + 1 + arraySum([], 0)
                         = 5 + 4 + 3 + 2 + 1 + 0
                         = 15
```

---

### **Example 3: Print Array Recursively**
```cpp
void printArray(int arr[], int n) {
    if (n == 0)                // BASE CASE
        return;
    printArray(arr, n-1);      // Print first n-1 elements
    cout << arr[n-1] << " ";   // Then print last element
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);        // Output: 1 2 3 4 5
    return 0;
}
```

---

## 📚 PART 4: RECURSION WITH STATIC VARIABLES

### **What is Static?**
A static variable retains its value between function calls!

### **Example 4: Counter with Static**
```cpp
int counter() {
    static int count = 0;      // Initialized only ONCE
    count++;
    return count;
}

int main() {
    cout << counter() << endl; // Output: 1
    cout << counter() << endl; // Output: 2
    cout << counter() << endl; // Output: 3
    return 0;
}
```

**CRITICAL:** Static variables are NOT reset on each call!

---

### **Example 5: Recursive with Static (Past Paper Style)**
```cpp
int mystery(int n) {
    static int x = 0;
    if (n == 0)
        return x;
    x++;
    return mystery(n - 1);
}

int main() {
    cout << mystery(5);        // Output: 5
    return 0;
}
```

**Trace:**
```
mystery(5): x=0 → x=1, call mystery(4)
  mystery(4): x=1 → x=2, call mystery(3)
    mystery(3): x=2 → x=3, call mystery(2)
      mystery(2): x=3 → x=4, call mystery(1)
        mystery(1): x=4 → x=5, call mystery(0)
          mystery(0): return x (which is 5)
```

---

## 📚 PART 5: RECURSION WITH REFERENCES

### **Pass by Reference in Recursion:**
Changes persist across recursive calls!

### **Example 6: Recursive with Reference**
```cpp
void modify(int n, int& result) {
    if (n == 0)
        return;
    result += n;
    modify(n - 1, result);
}

int main() {
    int result = 0;
    modify(5, result);
    cout << result;            // Output: 15 (1+2+3+4+5)
    return 0;
}
```

**Trace:**
```
modify(5, result): result = 0 + 5 = 5, call modify(4, result)
  modify(4, result): result = 5 + 4 = 9, call modify(3, result)
    modify(3, result): result = 9 + 3 = 12, call modify(2, result)
      modify(2, result): result = 12 + 2 = 14, call modify(1, result)
        modify(1, result): result = 14 + 1 = 15, call modify(0, result)
          modify(0, result): return
```

---

## 📚 PART 6: RECURSIVE PATTERNS (PAST PAPER STYLE)

### **Pattern: Pell Numbers (Past Paper)**
```cpp
int pellNum(int n) {
    if (n <= 2)
        return n;
    return 2 * pellNum(n-1) + pellNum(n-2);
}

// Sequence: 0, 1, 2, 5, 12, 29, 70, ...
// pellNum(5) = 2*pellNum(4) + pellNum(3)
//            = 2*12 + 5
//            = 29
```

---

### **Pattern: Print Pattern Recursively**
```cpp
void pattern(int n) {
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
        cout << "*";
    cout << endl;
    pattern(n - 1);
}

// pattern(4) prints:
// ****
// ***
// **
// *
```

---

### **Pattern: Reverse Print**
```cpp
void reversePrint(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    reversePrint(n - 1);
}

// reversePrint(5) prints: 5 4 3 2 1
```

---

## 📚 PART 7: TRACING RECURSIVE CALLS

### **How to Trace:**
1. **Draw the call stack** - Show each function call
2. **Track variables** - Especially static and reference variables
3. **Follow the return path** - Values bubble back up
4. **Watch for base case** - When recursion stops

### **Example 7: Complex Trace**
```cpp
int mystery(int n) {
    if (n <= 1)
        return 1;
    return n + mystery(n - 2);
}

// mystery(7) = ?
```

**Trace:**
```
mystery(7) = 7 + mystery(5)
  mystery(5) = 5 + mystery(3)
    mystery(3) = 3 + mystery(1)
      mystery(1) = 1 (base case)
    returns 3 + 1 = 4
  returns 5 + 4 = 9
returns 7 + 9 = 16
```

**Answer:** 16

---

## ⚠️ COMMON MISTAKES TO AVOID

### **Mistake 1: Missing Base Case**
```cpp
int bad(int n) {
    return n + bad(n - 1);     // NO BASE CASE! Infinite recursion!
}
```

**Fix:**
```cpp
int good(int n) {
    if (n == 0)                // BASE CASE
        return 0;
    return n + good(n - 1);
}
```

---

### **Mistake 2: Wrong Base Case**
```cpp
int factorial(int n) {
    if (n == 1)                // WRONG! Misses n=0
        return 1;
    return n * factorial(n - 1);
}
```

**Fix:**
```cpp
int factorial(int n) {
    if (n == 0 || n == 1)      // CORRECT
        return 1;
    return n * factorial(n - 1);
}
```

---

### **Mistake 3: Not Understanding Static**
```cpp
int count(int n) {
    static int x = 0;
    x++;
    if (n == 0)
        return x;
    return count(n - 1);
}

// Many students think x resets each call - IT DOESN'T!
```

---

### **Mistake 4: Confusing Return Values**
```cpp
void print(int n) {
    if (n == 0)
        return;                // Returns nothing (void)
    cout << n << " ";
    print(n - 1);
}

int sum(int n) {
    if (n == 0)
        return 0;              // Returns a value (int)
    return n + sum(n - 1);
}
```

---

## 🔥 QUICK REFERENCE CHEAT SHEET

| Pattern | Base Case | Recursive Case | Example |
|---------|-----------|----------------|---------|
| **Factorial** | `n == 0 or 1` | `n * fact(n-1)` | `fact(5) = 120` |
| **Fibonacci** | `n == 0 or 1` | `fib(n-1) + fib(n-2)` | `fib(5) = 5` |
| **Sum** | `n == 0` | `n + sum(n-1)` | `sum(5) = 15` |
| **Power** | `exp == 0` | `base * pow(base, exp-1)` | `pow(2,3) = 8` |
| **Array Sum** | `n == 0` | `arr[n-1] + sum(arr, n-1)` | Sum array |
| **Countdown** | `n == 0` | `print n, count(n-1)` | `3 2 1` |

---

## 🎯 TRACING TIPS

1. **Write down each call** - Don't try to do it in your head
2. **Track all variables** - Especially static and reference
3. **Indent nested calls** - Shows call stack depth
4. **Follow return path** - Values bubble back up
5. **Check base case** - Make sure recursion stops

---

## 🎯 NOW YOU'RE READY!

**You've learned:**
✅ Recursive thinking and base cases  
✅ Classic patterns (factorial, fibonacci, etc.)  
✅ Recursion with arrays  
✅ Static variables in recursion  
✅ Reference parameters in recursion  
✅ How to trace recursive calls  
✅ Common exam patterns  

**Next Step:** Open `session2_batch1_problems.md` and start solving!

**Remember:**
- Draw call stacks for complex problems
- Trace step-by-step
- Watch for static variables
- Make mistakes - that's how you learn!

**LET'S DOMINATE RECURSION! 🚀**
