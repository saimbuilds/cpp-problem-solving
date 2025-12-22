# SESSION 3: POINTERS + RECURSION FUSION - THEORY
**Read Time: 10 minutes**

---

## 🎯 What You'll Master

Combining pointers and recursion - the MOST TESTED combination in finals!

---

## 📚 KEY PATTERNS

### **Pattern 1: Recursive with Pointer Parameters**
```cpp
void modify(int *p, int n) {
    if (n == 0)
        return;
    *p += n;
    modify(p, n - 1);
}

int main() {
    int x = 0;
    modify(&x, 5);
    cout << x;  // Output: 15
    return 0;
}
```

### **Pattern 2: Recursive Array Traversal with Pointers**
```cpp
int sumArray(int *arr, int n) {
    if (n == 0)
        return 0;
    return *arr + sumArray(arr + 1, n - 1);
}
```

### **Pattern 3: Recursive with Reference Parameters (Past Paper)**
```cpp
void find(int a, int& b, int& c, int d=4) {
    if(d < 1)
        return;
    cout << a << "," << b << "," << c << endl;
    c = a + 2 * b;
    int temp = b;
    b = a;
    a = 2 * temp;
    d % 2 ? find(b,a,c,d-1) : find(c,b,a,d-1);
}
```

**CRITICAL:** Changes to reference parameters persist across calls!

---

## 🔥 EXAM TIPS

1. **Draw call stacks** with pointer/reference values
2. **Track what pointers point to** at each recursive level
3. **Watch for reference parameter changes**
4. **Trace carefully** - these are the hardest questions!

---

**Next:** `session3_batch1_problems.md`
