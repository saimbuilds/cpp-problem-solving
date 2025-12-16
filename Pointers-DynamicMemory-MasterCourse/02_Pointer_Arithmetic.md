# Module 2: Pointer Arithmetic & Arrays
## Understanding the Math Behind Memory

> **Learning Objective**: Master pointer arithmetic and the deep relationship between pointers and arrays.

---

## Table of Contents
1. [Pointer Arithmetic Basics](#pointer-arithmetic-basics)
2. [Pointers and Arrays](#pointers-and-arrays)
3. [Array Traversal Using Pointers](#array-traversal-using-pointers)
4. [Pointer Comparison](#pointer-comparison)
5. [Advanced Patterns](#advanced-patterns)
6. [Common Mistakes](#common-mistakes)

---

## Pointer Arithmetic Basics

### Valid Operations
```cpp
int arr[] = {10, 20, 30, 40, 50};
int* ptr = arr;  // Points to arr[0]

ptr++;      // Move to next element
ptr--;      // Move to previous element
ptr += 3;   // Move forward 3 elements
ptr -= 2;   // Move backward 2 elements

int diff = ptr2 - ptr1;  // Difference in elements
```

### ⚠️ CRITICAL: Scaling Factor

When you increment a pointer, it moves by **sizeof(data type)** bytes, not 1 byte!

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << ptr;        // Example: 0x1000
cout << ptr + 1;    // Example: 0x1004 (not 0x1001!)
cout << ptr + 2;    // Example: 0x1008
```

**Why?** `sizeof(int) = 4 bytes`, so:
- `ptr + 1` means "1 int ahead" = address + 4
- `ptr + 2` means "2 ints ahead" = address + 8

### Example with Different Types
```cpp
char c_arr[] = {'A', 'B', 'C'};
char* c_ptr = c_arr;
// c_ptr + 1 moves 1 byte (sizeof(char) = 1)

double d_arr[] = {1.1, 2.2, 3.3};
double* d_ptr = d_arr;
// d_ptr + 1 moves 8 bytes (sizeof(double) = 8)
```

---

## Pointers and Arrays

### The BIG Truth
**Array name = Pointer to first element**

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;  // Same as: int* ptr = &arr[0];

cout << arr;       // Address of first element
cout << &arr[0];   // Same as above
cout << ptr;       // Same address
```

### Array Access: Two Methods

#### Method 1: Array Notation
```cpp
int arr[] = {10, 20, 30, 40};
cout << arr[0];  // 10
cout << arr[2];  // 30
```

#### Method 2: Pointer Notation
```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;

cout << *ptr;        // 10 (same as arr[0])
cout << *(ptr + 1);  // 20 (same as arr[1])
cout << *(ptr + 2);  // 30 (same as arr[2])
```

### Equivalence Table

| Array Notation | Pointer Notation | Meaning |
|----------------|------------------|---------|
| `arr[i]` | `*(arr + i)` | Value at index i |
| `&arr[i]` | `arr + i` | Address of index i |
| `arr[0]` | `*arr` | First element |
| `arr` | `&arr[0]` | Address of first element |

### Key Insight
```cpp
arr[i]  ≡  *(arr + i)
i[arr]  ≡  *(i + arr)  // Yes, this works too! (rare but valid)
```

---

## Array Traversal Using Pointers

### Traditional Loop
```cpp
int arr[] = {5, 10, 15, 20, 25};
int size = 5;

for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
```

### Pointer Method 1: Indexing
```cpp
int arr[] = {5, 10, 15, 20, 25};
int size = 5;
int* ptr = arr;

for (int i = 0; i < size; i++) {
    cout << *(ptr + i) << " ";  // or ptr[i]
}
```

### Pointer Method 2: Incrementing (Preferred in exams!)
```cpp
int arr[] = {5, 10, 15, 20, 25};
int size = 5;
int* ptr = arr;

for (int i = 0; i < size; i++) {
    cout << *ptr << " ";
    ptr++;  // Move to next element
}
```

### Pointer Method 3: End Pointer
```cpp
int arr[] = {5, 10, 15, 20, 25};
int* start = arr;
int* end = arr + 5;  // Points past last element

for (int* ptr = start; ptr < end; ptr++) {
    cout << *ptr << " ";
}
```

---

## Pointer Comparison

You can compare pointers of the same array:

```cpp
int arr[] = {10, 20, 30, 40};
int* p1 = &arr[1];
int* p2 = &arr[3];

if (p1 < p2) {
    cout << "p1 comes before p2";  // TRUE
}

int distance = p2 - p1;  // 2 (elements between them)
```

### Valid Comparisons
```cpp
ptr1 == ptr2  // Are they pointing to same location?
ptr1 != ptr2  // Different locations?
ptr1 < ptr2   // Is ptr1 before ptr2?
ptr1 > ptr2   // Is ptr1 after ptr2?
ptr1 <= ptr2
ptr1 >= ptr2
```

---

## Advanced Patterns

### Pattern 1: Reverse Traversal
```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = 5;
int* ptr = arr + size - 1;  // Points to last element

for (int i = 0; i < size; i++) {
    cout << *ptr << " ";
    ptr--;
}
// Output: 5 4 3 2 1
```

### Pattern 2: Two Pointers (Start & End)
```cpp
int arr[] = {1, 2, 3, 4, 5};
int* start = arr;
int* end = arr + 4;  // Points to last element

while (start < end) {
    cout << *start << " " << *end << endl;
    start++;
    end--;
}
// Output:
// 1 5
// 2 4
```

### Pattern 3: Finding Element
```cpp
int arr[] = {10, 20, 30, 40, 50};
int size = 5;
int target = 30;
int* ptr = arr;
bool found = false;

for (int i = 0; i < size; i++) {
    if (*ptr == target) {
        cout << "Found at index " << i;
        found = true;
        break;
    }
    ptr++;
}
```

### Pattern 4: Sum Using Pointers
```cpp
int arr[] = {5, 10, 15, 20};
int size = 4;
int* ptr = arr;
int sum = 0;

for (int i = 0; i < size; i++) {
    sum += *ptr;
    ptr++;
}
cout << "Sum: " << sum;  // 50
```

---

## Common Mistakes

### ❌ Mistake 1: Out of Bounds
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;
ptr += 10;  // Now pointing outside array!
cout << *ptr;  // UNDEFINED BEHAVIOR
```

### ❌ Mistake 2: Modifying Array Name
```cpp
int arr[] = {1, 2, 3};
arr++;  // ERROR! Array name is not a modifiable lvalue
```

**✅ Fix:**
```cpp
int arr[] = {1, 2, 3};
int* ptr = arr;
ptr++;  // OK
```

### ❌ Mistake 3: Pointer Arithmetic on Void Pointers
```cpp
void* ptr = arr;
ptr++;  // ERROR! Cannot do arithmetic on void*
```

### ❌ Mistake 4: Comparing Unrelated Pointers
```cpp
int arr1[] = {1, 2};
int arr2[] = {3, 4};
if (arr1 < arr2) { }  // UNDEFINED! Different arrays
```

---

## Dry Run Examples

### Example 1: Basic Traversal
```cpp
int arr[] = {2, 4, 6, 8};
int* ptr = arr;
ptr += 2;
cout << *ptr << " ";
ptr--;
cout << *ptr;
```

**Output:** `6 4`

**Trace:**
1. ptr = &arr[0]
2. ptr += 2 → ptr = &arr[2]
3. *ptr = 6
4. ptr-- → ptr = &arr[1]
5. *ptr = 4

---

### Example 2: Equivalence
```cpp
int arr[] = {10, 20, 30};
cout << arr[1] << " ";
cout << *(arr + 1) << " ";
cout << 1[arr];
```

**Output:** `20 20 20`

All three are equivalent!

---

### Example 3: Pointer Difference
```cpp
int arr[] = {5, 10, 15, 20, 25};
int* p1 = &arr[1];
int* p2 = &arr[4];
cout << (p2 - p1);
```

**Output:** `3`

Distance = index 4 - index 1 = 3 elements

---

### Example 4: Modification
```cpp
int arr[] = {1, 2, 3, 4};
int* ptr = arr + 1;
*ptr = 10;
ptr++;
*ptr = 20;
for (int i = 0; i < 4; i++)
    cout << arr[i] << " ";
```

**Output:** `1 10 20 4`

**Trace:**
1. ptr = &arr[1]
2. arr[1] = 10
3. ptr = &arr[2]
4. arr[2] = 20

---

## Quick Reference

| Operation | Result |
|-----------|--------|
| `ptr++` | Move to next element |
| `ptr--` | Move to previous element |
| `ptr + n` | n elements forward |
| `ptr - n` | n elements backward |
| `ptr2 - ptr1` | Distance in elements |
| `*ptr++` | Use value, then move pointer |
| `(*ptr)++` | Increment value at pointer |
| `*(ptr++)` | Same as *ptr++ |

---

## MCQs

### Q1. What does `ptr + 2` mean?
A) Address increased by 2 bytes  
B) Address increased by 2 × sizeof(type)  
C) Value increased by 2  
D) Syntax error  

<details>
<summary>Answer</summary>
**B)** Pointer arithmetic scales by the size of the data type.
</details>

### Q2. Given `int arr[5];`, which is FALSE?
A) `arr` is the address of first element  
B) `arr++` is valid  
C) `&arr[0]` equals `arr`  
D) `arr[2]` equals `*(arr + 2)`  

<details>
<summary>Answer</summary>
**B)** Array names are not modifiable lvalues.
</details>

---

## Key Takeaways

1. ✅ Pointer arithmetic scales by `sizeof(type)`
2. ✅ `arr[i]` ≡ `*(arr + i)`
3. ✅ Array name is a constant pointer
4. ✅ Can increment pointer variables, not array names
5. ✅ Pointer difference gives element count
6. ✅ Always check bounds!

**Next**: Practice_02_Arithmetic.md → Module 3

---

*🎯 Master this before moving on - pointer arithmetic is CRUCIAL for arrays!*
