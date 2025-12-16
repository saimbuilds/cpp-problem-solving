# RAPID REVIEW CHEAT SHEET
## Last-Hour Power Review

> **Use this in the final hour before exam for quick recall of critical concepts**

---

## 1. Pointer Fundamentals

### Declaration & Initialization
```cpp
int* ptr;              // Declaration
int* ptr = &var;       // Initialize with address
int* ptr = nullptr;    // Initialize as null (C++11)
```

### Key Operators
| Operator | Name | Usage |
|----------|------|-------|
| `&` | Address-of | `&var` gives address |
| `*` | Dereference | `*ptr` gives value |
| `*` | Declaration | `int* ptr` declares pointer |

### Essential Rules
✅ Always initialize pointers  
✅ Check for nullptr before dereferencing  
✅ Pointer type must match variable type  

---

## 2. Pointer Arithmetic

### Scaling Factor
```cpp
ptr + 1  →  address + sizeof(type)
```

**Examples:**
- `int* ptr + 1` → address + 4 bytes
- `char* ptr + 1` → address + 1 byte
- `double* ptr + 1` → address + 8 bytes

### Array-Pointer Equivalence
```cpp
arr[i]  ≡  *(arr + i)
&arr[i] ≡  arr + i
```

### Common Operations
```cpp
ptr++       // Move to next element
ptr--       // Move to previous element
ptr + n     // n elements forward
ptr - n     // n elements backward
ptr2 - ptr1 // Element distance (not bytes!)
```

---

## 3. Pointers & Functions

### Pass-by-Value vs Pass-by-Pointer
```cpp
// Pass by value (won't modify original)
void func(int x) { x = 10; }

// Pass by pointer (WILL modify original)
void func(int* x) { *x = 10; }

// Call
int num = 5;
func(&num);  // Pass address
```

### Returning Pointers
✅ **Safe:** Return pointer to heap memory or array element  
❌ **DANGER:** Return pointer to local variable  

```cpp
// BAD
int* bad() {
    int x = 10;
    return &x;  // x destroyed when function ends!
}

// GOOD
int* good(int* arr, int size) {
    return arr + 2;  // array lives beyond function
}
```

---

## 4. Dynamic Memory (1D)

### Allocation & Deallocation
```cpp
// Single variable
int* ptr = new int;       // Allocate
int* ptr = new int(42);   // Allocate & initialize
delete ptr;               // Deallocate
ptr = nullptr;            // Good practice

// Array
int* arr = new int[n];    // Allocate array
delete[] arr;             // Deallocate array (NOTE: [])
arr = nullptr;
```

### Critical Rules
✅ `delete` for single, `delete[]` for arrays  
✅ Always delete what you new  
✅ Set to nullptr after delete  
✅ Never use after delete (dangling pointer)  

### Common Mistakes
❌ Using `delete` instead of `delete[]` for arrays  
❌ Forgetting to delete (memory leak)  
❌ Double delete  
❌ Using after delete  

---

## 5. Dynamic Memory (2D)

### Allocation Pattern
```cpp
int rows = 3, cols = 4;

// Step 1: Allocate array of row pointers
int** arr = new int*[rows];

// Step 2: Allocate each row
for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
}
```

### Deallocation Pattern (ORDER CRITICAL!)
```cpp
// Step 1: Delete each row FIRST
for (int i = 0; i < rows; i++) {
    delete[] arr[i];
}

// Step 2: Delete array of pointers LAST
delete[] arr;
```

### Mnemonic
**"Last In, First Out"** (LIFO)
- Last allocated (rows) → deleted first
- First allocated (array of pointers) → deleted last

### Jagged Arrays
```cpp
int** arr = new int*[3];
arr[0] = new int[2];   // Row 0: 2 elements
arr[1] = new int[5];   // Row 1: 5 elements
arr[2] = new int[3];   // Row 2: 3 elements
```

---

## 6. Advanced Concepts

### Pointer to Pointer
```cpp
int x = 10;
int* p = &x;
int** pp = &p;

**pp = 20;  // Changes x to 20
```

### Complex Expressions
| Expression | Effect |
|------------|--------|
| `*ptr++` | Use value, then move pointer |
| `(*ptr)++` | Increment value at pointer |
| `*++ptr` | Move pointer, then use value |
| `++*ptr` | Pre-increment value |

### Shallow vs Deep Copy
```cpp
// Shallow (both point to same memory)
int* arr2 = arr1;

// Deep (independent copies)
int* arr2 = new int[size];
for (int i = 0; i < size; i++)
    arr2[i] = arr1[i];
```

---

## 7. Quick Checklist

### Before Exam Starts
- [ ] Pointer basics clear
- [ ] Can write 2D allocation/deallocation blind
- [ ] Know operator precedence
- [ ] Understand shallow vs deep copy
- [ ] Can spot memory leaks

### During Exam
- [ ] Read question fully
- [ ] Watch for `delete` vs `delete[]`
- [ ] Check deallocation order for 2D
- [ ] Trace pointer arithmetic carefully
- [ ] Check for memory leaks
- [ ] Initialize pointers before using

---

## 8. Common Exam Tricks

### Trick 1: Wrong Delete
```cpp
int* arr = new int[100];
delete arr;  // WRONG! Should be delete[]
```

### Trick 2: Memory Leak from Reassignment
```cpp
int* p = new int[100];
p = new int[200];  // Leaked first 100!
```

### Trick 3: Deallocation Order
```cpp
int** mat = new int*[5];
// ... allocate rows ...
delete[] mat;  // WRONG! Rows not freed
```

### Trick 4: Using After Delete
```cpp
delete[] arr;
arr[0] = 10;  // CRASH! Dangling pointer
```

### Trick 5: Shallow Copy Issues
```cpp
int* arr2 = arr1;  // Same memory!
delete[] arr1;
delete[] arr2;  // CRASH! Double delete
```

---

## 9. Speed Formulas

### Memory Leak Calculation
Integers leaked = (arrays not deleted) × (size of each array)

### Pointer Distance
```cpp
ptr2 - ptr1 = number of elements (not bytes!)
```

### 2D Array Element Access
```cpp
mat[i][j] = *(*(mat + i) + j)
```

---

## 10. Final Reminders

🔥 **THE BIG 3:**
1. **Allocation:** `new` = `delete`, `new[]` = `delete[]`
2. **2D Order:** Delete rows first, then array of pointers
3. **Always:** Initialize, check nullptr, set to nullptr after delete

🎯 **RED FLAGS:**
- Returning `&localVar` from function
- `delete arr` when should be `delete[] arr`
- Deleting rows after array in 2D
- Using pointer after delete
- Not deleting allocated memory

💪 **YOU GOT THIS!**

---

*Read this sheet 30 minutes before exam. You're prepared. Stay calm. Execute.*
