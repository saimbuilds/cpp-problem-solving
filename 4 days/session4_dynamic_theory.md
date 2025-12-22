# SESSION 4: DYNAMIC MEMORY ALLOCATION - COMPREHENSIVE THEORY
**Read Time: 20 minutes | CRITICAL TOPIC!**

---

## 🎯 What You'll Master

1. Dynamic memory allocation (new/delete)
2. Dynamic arrays (1D and 2D)
3. Memory leaks and proper cleanup
4. Pointers with dynamic memory
5. Common exam patterns

---

## 📚 PART 1: WHY DYNAMIC MEMORY?

### **Static vs Dynamic Allocation**

**Static Allocation (Stack):**
```cpp
int arr[100];  // Size MUST be known at compile time
```
- Size fixed at compile time
- Automatically deallocated when out of scope
- Limited size (stack overflow possible)

**Dynamic Allocation (Heap):**
```cpp
int *arr = new int[n];  // Size can be determined at runtime
```
- Size can be determined at runtime
- Must manually deallocate
- Much larger available memory

---

## 📚 PART 2: THE `new` AND `delete` OPERATORS

### **Allocating Single Variable**
```cpp
int *p = new int;        // Allocate one int
*p = 10;                 // Use it
delete p;                // Free memory
p = NULL;                // Good practice: prevent dangling pointer
```

**Memory Diagram:**
```
BEFORE new:
p: [garbage]

AFTER new:
Heap: [allocated space] ← p points here

AFTER delete:
Heap: [freed] 
p: [dangling pointer - DANGEROUS!]

AFTER p = NULL:
p: [NULL] - SAFE
```

---

### **Allocating Array**
```cpp
int *arr = new int[5];   // Allocate array of 5 ints
arr[0] = 10;             // Use like normal array
arr[1] = 20;
delete[] arr;            // Free array memory (note the [])
arr = NULL;
```

**CRITICAL:** Use `delete[]` for arrays, `delete` for single variables!

---

### **Example 1: Basic Dynamic Allocation**
```cpp
int main() {
    int *p = new int;
    *p = 100;
    cout << *p << endl;  // Output: 100
    
    delete p;
    p = NULL;
    
    return 0;
}
```

---

### **Example 2: Dynamic Array**
```cpp
int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    int *arr = new int[n];  // Size determined at runtime!
    
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    delete[] arr;  // MUST free memory!
    arr = NULL;
    
    return 0;
}
```

---

## 📚 PART 3: MEMORY LEAKS

### **What is a Memory Leak?**
Memory that is allocated but never freed!

### **Example of Memory Leak:**
```cpp
void badFunction() {
    int *p = new int[1000];
    // ... use p ...
    // FORGOT TO DELETE!
}  // p goes out of scope, but memory is still allocated!

int main() {
    for (int i = 0; i < 1000; i++) {
        badFunction();  // Leaks 1000 ints each time!
    }
    // Program has leaked 1,000,000 ints!
    return 0;
}
```

**CRITICAL:** Every `new` MUST have a corresponding `delete`!

---

### **Common Memory Leak Scenarios:**

**Scenario 1: Forgetting to Delete**
```cpp
int *p = new int[100];
// ... use p ...
// FORGOT: delete[] p;
```

**Scenario 2: Losing Pointer**
```cpp
int *p = new int[100];
p = new int[200];  // LEAK! Lost reference to first allocation
delete[] p;        // Only frees second allocation
```

**Fix:**
```cpp
int *p = new int[100];
delete[] p;        // Free first
p = new int[200];  // Then allocate second
delete[] p;        // Free second
```

**Scenario 3: Early Return**
```cpp
void function() {
    int *p = new int[100];
    if (someCondition)
        return;  // LEAK! Forgot to delete before returning
    delete[] p;
}
```

**Fix:**
```cpp
void function() {
    int *p = new int[100];
    if (someCondition) {
        delete[] p;  // Free before returning
        return;
    }
    delete[] p;
}
```

---

## 📚 PART 4: DYNAMIC 2D ARRAYS

### **Method 1: Array of Pointers**
```cpp
int rows = 3, cols = 4;
int **arr = new int*[rows];  // Array of pointers

for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];  // Each pointer points to an array
}

// Use like normal 2D array
arr[0][0] = 10;
arr[1][2] = 20;

// MUST delete in reverse order!
for (int i = 0; i < rows; i++) {
    delete[] arr[i];  // Delete each row
}
delete[] arr;  // Delete array of pointers
```

**Memory Diagram:**
```
arr → [ptr0] → [10][  ][  ][  ]
      [ptr1] → [  ][  ][20][  ]
      [ptr2] → [  ][  ][  ][  ]
```

---

### **Example 3: Dynamic 2D Array**
```cpp
int main() {
    int rows = 3, cols = 3;
    
    // Allocate
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Initialize
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Deallocate
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
```

**Output:**
```
1 2 3
4 5 6
7 8 9
```

---

## 📚 PART 5: RETURNING POINTERS FROM FUNCTIONS

### **Returning Dynamically Allocated Memory**
```cpp
int* createArray(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    return arr;  // OK! Memory persists after function returns
}

int main() {
    int *myArr = createArray(5);
    
    for (int i = 0; i < 5; i++) {
        cout << myArr[i] << " ";
    }
    
    delete[] myArr;  // MUST delete in main!
    return 0;
}
```

**CRITICAL:** Caller is responsible for deleting!

---

### **WRONG: Returning Local Array**
```cpp
int* badFunction() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;  // WRONG! arr is local, will be destroyed!
}
```

**This is UNDEFINED BEHAVIOR!**

---

## 📚 PART 6: COMMON EXAM PATTERNS

### **Pattern 1: Dynamic Array Creation**
```cpp
int *arr = new int[n];
// ... use arr ...
delete[] arr;
```

### **Pattern 2: Dynamic 2D Array**
```cpp
int **arr = new int*[rows];
for (int i = 0; i < rows; i++)
    arr[i] = new int[cols];

// ... use arr ...

for (int i = 0; i < rows; i++)
    delete[] arr[i];
delete[] arr;
```

### **Pattern 3: Returning Dynamic Array (Past Paper)**
```cpp
int* listMystery(int list[][3]) {
    int *n = new int[3];
    // ... fill n ...
    return n;  // Caller must delete!
}

int main() {
    int L[][3] = {{8,9,4}, {2,3,4}, {7,6,1}};
    int *ptr = listMystery(L);
    // ... use ptr ...
    delete[] ptr;  // MUST delete!
    return 0;
}
```

### **Pattern 4: Memory Leak Detection**
```cpp
void function() {
    int *p = new int[100];
    // ... code ...
    if (condition)
        return;  // LEAK if we don't delete before return!
    delete[] p;
}
```

---

## 📚 PART 7: POINTER ARITHMETIC WITH DYNAMIC MEMORY

### **Works Just Like Static Arrays!**
```cpp
int *arr = new int[5];
arr[0] = 10;
arr[1] = 20;

int *p = arr;
cout << *p;        // 10
cout << *(p + 1);  // 20

p++;
cout << *p;        // 20

delete[] arr;
```

---

## ⚠️ COMMON MISTAKES

### **Mistake 1: Using `delete` instead of `delete[]`**
```cpp
int *arr = new int[5];
delete arr;  // WRONG! Should be delete[]
```

**Correct:**
```cpp
int *arr = new int[5];
delete[] arr;  // CORRECT
```

---

### **Mistake 2: Double Delete**
```cpp
int *p = new int;
delete p;
delete p;  // UNDEFINED BEHAVIOR! Already deleted!
```

**Fix:**
```cpp
int *p = new int;
delete p;
p = NULL;  // Prevent double delete
if (p != NULL)
    delete p;  // Safe
```

---

### **Mistake 3: Deleting Stack Memory**
```cpp
int x = 10;
int *p = &x;
delete p;  // WRONG! x is on stack, not heap!
```

**Only delete memory allocated with `new`!**

---

### **Mistake 4: Accessing After Delete**
```cpp
int *p = new int;
*p = 10;
delete p;
cout << *p;  // UNDEFINED BEHAVIOR! Accessing freed memory!
```

---

### **Mistake 5: Wrong Deallocation Order for 2D Arrays**
```cpp
int **arr = new int*[rows];
for (int i = 0; i < rows; i++)
    arr[i] = new int[cols];

delete[] arr;  // WRONG! Leaks all rows!
for (int i = 0; i < rows; i++)
    delete[] arr[i];  // Can't access after arr is deleted!
```

**Correct:**
```cpp
for (int i = 0; i < rows; i++)
    delete[] arr[i];  // Delete rows first
delete[] arr;  // Then delete array of pointers
```

---

## 🔥 QUICK REFERENCE CHEAT SHEET

| Operation | Syntax | Notes |
|-----------|--------|-------|
| **Allocate single** | `int *p = new int;` | Use `delete p;` |
| **Allocate array** | `int *arr = new int[n];` | Use `delete[] arr;` |
| **Allocate 2D** | `int **arr = new int*[rows];` | Delete rows first, then arr |
| **Delete single** | `delete p;` | Then set `p = NULL;` |
| **Delete array** | `delete[] arr;` | Then set `arr = NULL;` |
| **Check before delete** | `if (p != NULL) delete p;` | Safe practice |

---

## 🎯 MEMORY MANAGEMENT RULES

1. **Every `new` needs a `delete`** - No exceptions!
2. **Use `delete[]` for arrays** - Not just `delete`
3. **Set to NULL after delete** - Prevents double delete
4. **Delete before reassigning** - Prevents memory leaks
5. **Delete in reverse order** - For 2D arrays
6. **Check for NULL** - Before deleting (safe practice)
7. **Caller deletes returned pointers** - If function returns `new`

---

## 🎯 EXAM TIPS

1. **Always check for memory leaks** - Every `new` has `delete`?
2. **Watch for early returns** - Delete before returning!
3. **2D array deallocation** - Delete rows first!
4. **Returning pointers** - Who is responsible for deleting?
5. **Pointer arithmetic** - Works same as static arrays

---

## 🎯 NOW YOU'RE READY!

**You've learned:**
✅ Dynamic memory allocation (new/delete)  
✅ Dynamic arrays (1D and 2D)  
✅ Memory leaks and prevention  
✅ Returning pointers from functions  
✅ Common exam patterns  
✅ Memory management rules  

**Next Step:** Open `session4_batch1_problems.md`!

**Remember:**
- Every `new` needs a `delete`!
- Use `delete[]` for arrays
- Set pointers to NULL after delete
- Watch for memory leaks!

**LET'S MASTER DYNAMIC MEMORY! 🚀**
