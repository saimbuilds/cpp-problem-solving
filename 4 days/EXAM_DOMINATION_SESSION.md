# EXAM DOMINATION SESSION - FALL 2023 LEVEL
**Duration: 6-7 hours | 60 Problems | HARDEST DIFFICULTY**

---

## 🎯 MISSION

Match or EXCEED Fall 2023 difficulty - the HARDEST PF final exam!

**Topics:**
1. Dynamic Memory Allocation (new/delete, memory leaks)
2. Pointers + Arrays (1D, 2D, complex arithmetic)
3. Functions (pass by reference, default params, overloading)
4. Recursion (easy-medium, mixed with pointers)

**NO bitwise today - pure focus on these 4!**

---

## 📚 QUICK CONCEPT REVIEW (30 minutes)

### **1. Dynamic Memory - Critical Points**

**Allocation:**
```cpp
int *p = new int;           // Single variable
int *arr = new int[n];      // Array
int **mat = new int*[rows]; // 2D array
```

**Deallocation:**
```cpp
delete p;        // Single
delete[] arr;    // Array
delete[] mat;    // 2D (delete rows first!)
```

**MEMORY LEAK = Allocated but never deleted!**

---

### **2. Pointers - Tricky Patterns**

**Pattern 1: Pointer to Pointer**
```cpp
int x = 10;
int *p = &x;
int **pp = &p;
**pp = 20;  // Changes x to 20!
```

**Pattern 2: 2D Arrays in Memory**
```cpp
int arr[2][3] = {{1,2,3}, {4,5,6}};
// Memory: 1 2 3 4 5 6 (continuous!)
int *p = arr[0] + 3;  // Points to 4!
```

**Pattern 3: Returning Pointers**
```cpp
int* func() {
    int *arr = new int[5];  // OK - heap memory
    return arr;             // Caller must delete!
}
```

---

### **3. Functions - Key Concepts**

**Pass by Reference:**
```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Changes persist!
```

**Default Parameters:**
```cpp
void func(int a, int b = 10, int c = 20);
func(5);        // a=5, b=10, c=20
func(5, 15);    // a=5, b=15, c=20
```

**Function Overloading:**
```cpp
void print(int x);
void print(double x);
void print(int x, int y);
// Different signatures!
```

---

### **4. Recursion - Essential Patterns**

**Pattern 1: Array Processing**
```cpp
int sum(int *arr, int n) {
    if (n == 0) return 0;
    return *arr + sum(arr + 1, n - 1);
}
```

**Pattern 2: With References**
```cpp
void modify(int& x, int n) {
    if (n == 0) return;
    x += n;
    modify(x, n - 1);  // Changes persist!
}
```

**Pattern 3: Static Variables**
```cpp
int count() {
    static int x = 0;  // Initialized ONCE
    return x++;        // Persists across calls!
}
```

---

## 🔥 NOW LET'S BLEED!

**Open these files in order:**
1. `exam_part1_dynamic_memory.md` (20 problems)
2. `exam_part2_functions_pointers.md` (20 problems)
3. `exam_part3_recursion_mix.md` (20 problems)
4. `exam_part4_past_paper_killers.md` (20 problems)

**Each part has solutions file!**

**Time allocation:**
- Part 1: 1.5 hours
- Part 2: 1.5 hours
- Part 3: 2 hours
- Part 4: 2 hours

**LET'S DOMINATE! 💪🔥**
