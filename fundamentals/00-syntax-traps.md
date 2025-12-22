# C++ Syntax Traps - The Complete Guide

> **Purpose**: Master every confusing syntax pattern that appears in your exam. These are the traps that separate 70% from 95%.

---

## 1. Pointer Arithmetic Traps

### Trap 1.1: Increment/Decrement Operator Precedence
```cpp
int arr[] = {10, 20, 30, 40};
int *ptr = arr;

// DIFFERENT BEHAVIORS:
*ptr++    // Returns *ptr, THEN increments ptr
(*ptr)++  // Increments the VALUE at ptr
*++ptr    // Increments ptr FIRST, then returns *ptr
++*ptr    // Increments the VALUE at ptr (same as (*ptr)++)
```

**Memory Model:**
```
Initial: ptr → [10][20][30][40]
                 ↑
         
*ptr++:  Use 10, then ptr moves →
(*ptr)++: Change 10 to 11, ptr stays
*++ptr:  ptr moves →, use 20
++*ptr:  Change 10 to 11, ptr stays
```

**Exam Tip**: Draw a quick arrow diagram. If `++` is BEFORE `*`, ptr moves. If AFTER or in `()`, value changes.

---

### Trap 1.2: Pointer vs Array Indexing
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;

// ALL EQUIVALENT:
arr[2]      // 3
*(arr + 2)  // 3
p[2]        // 3
*(p + 2)    // 3
2[arr]      // 3 (WTF but valid!)
```

**Key Insight**: `a[b]` is just syntactic sugar for `*(a + b)`

---

### Trap 1.3: Pointer Arithmetic with Different Types
```cpp
int arr[] = {10, 20, 30, 40};
int *p = arr;

p + 1  // Points to arr[1] (moves by sizeof(int) bytes, usually 4)
p + 2  // Points to arr[2] (moves by 8 bytes)

// CAREFUL:
(p + 1) - p == 1  // TRUE (difference is in "elements", not bytes)
```

---

### Trap 1.4: Array Name vs Address of Array
```cpp
int arr[10];

arr      // Pointer to first element (type: int*)
&arr     // Pointer to entire array (type: int(*)[10])
&arr[0]  // Pointer to first element (type: int*)

// COMPARISON TRAP:
arr == &arr[0]  // TRUE (same address)
arr == &arr     // TRUE (same address, but different types!)
```

**Exam Pattern**: They love asking `if(arr == &arr[0])` → Always TRUE

---

## 2. Function Parameter Traps

### Trap 2.1: Pass by Value vs Reference
```cpp
void func1(int x) {     // Pass by value (copy)
    x = 100;            // Changes LOCAL copy only
}

void func2(int &x) {    // Pass by reference
    x = 100;            // Changes ORIGINAL variable
}

void func3(int *x) {    // Pass by pointer
    *x = 100;           // Changes value at address
}

int main() {
    int a = 5;
    func1(a);  // a is still 5
    func2(a);  // a is now 100
    func3(&a); // a is now 100
}
```

---

### Trap 2.2: Array Parameters Decay to Pointers
```cpp
void func(int arr[10]) {    // Actually receives int *arr
    cout << sizeof(arr);     // 8 (pointer size), NOT 40!
}

void func2(int arr[], int size) {  // Correct way
    // Must pass size separately
}
```

**Key**: Arrays ALWAYS decay to pointers when passed to functions. Size information is lost!

---

### Trap 2.3: Default Parameters
```cpp
void func(int a, int b = 10, int c = 20);

func(5);        // a=5, b=10, c=20
func(5, 15);    // a=5, b=15, c=20
func(5, 15, 25);// a=5, b=15, c=25
```

**Trap**: Default params must be rightmost. `void func(int a=5, int b)` is INVALID!

---

### Trap 2.4: Function Overloading Resolution
```cpp
void Sum(int a) { 
    cout << a + 100 << endl; 
}

void Sum(int a, int b, int c = 10) { 
    cout << a + b + c << endl; 
}

Sum('A');      // Calls first: 65 + 100 = 165
Sum('B', 30);  // Calls second: 66 + 30 + 10 = 106
Sum(20, 30, 90.5); // Calls second: 20 + 30 + 90 = 140 (90.5 truncated to int!)
```

**Trap**: `char` auto-converts to `int` ('A' = 65). Float gets truncated to int.

---

## 3. Loop & Control Flow Traps

### Trap 3.1: For Loop with Multiple Variables
```cpp
for (int i = 0, j = 10; i < j; i++, j--) {
    cout << i << " " << j << endl;
}
// Output: 0 10, 1 9, 2 8, 3 7, 4 6
```

**Trap**: Comma separates multiple operations in init and increment sections.

---

### Trap 3.2: Loop Scope Confusion
```cpp
for (int i = 0; i < 5; i++);  // Semicolon = empty loop!
{
    cout << "Hello";  // Executes ONCE after loop
}

// vs

for (int i = 0; i < 5; i++) {
    cout << "Hello";  // Executes 5 times
}
```

---

### Trap 3.3: Break vs Continue
```cpp
for (int i = 0; i < 5; i++) {
    if (i == 2) break;     // Exit loop entirely
    cout << i;
}
// Output: 01

for (int i = 0; i < 5; i++) {
    if (i == 2) continue;  // Skip this iteration only
    cout << i;
}
// Output: 0134
```

---

### Trap 3.4: Ternary Operator in Conditions
```cpp
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max = 20

// NESTED TERNARY (Evil but appears in exams):
int discriminant = 5;
int result = (discriminant > 0) ? 1 : (discriminant == 0) ? 2 : 3;
// result = 1
```

---

## 4. Static Variables

### Trap 4.1: Static in Functions
```cpp
int get() {
    static int x = 0;  // Initialized ONCE, persists across calls
    return x++;
}

int main() {
    cout << get() << endl;  // 0
    cout << get() << endl;  // 1
    cout << get() << endl;  // 2
}
```

**Key**: `static` variables retain their value between function calls!

---

### Trap 4.2: Static vs Normal Variables
```cpp
void func() {
    int a = 0;         // Re-initialized every call
    static int b = 0;  // Initialized ONCE
    a++;
    b++;
    cout << a << " " << b << endl;
}

func();  // Output: 1 1
func();  // Output: 1 2
func();  // Output: 1 3
```

---

## 5. Operator Precedence & Associativity

### Critical Precedence Table (High to Low):
```
1.  ()  []  ->  .         (Highest)
2.  ++  --  (postfix)
3.  ++  --  (prefix)  !  &  *  (unary)
4.  *  /  %
5.  +  -
6.  <<  >>
7.  <  <=  >  >=
8.  ==  !=
9.  &
10. ^
11. |
12. &&
13. ||
14. ?:
15. =  +=  -=  etc.      (Lowest)
```

### Exam Traps:
```cpp
*p++     // *(p++) - dereference, then increment p
*++p     // *(++p) - increment p, then dereference
++*p     // ++(*p) - increment value at p

a + b * c     // a + (b * c)
a && b || c   // (a && b) || c
!a && b       // (!a) && b
```

---

## 6. Type Casting Traps

### Trap 6.1: Implicit Conversions
```cpp
int a = 7, b = 2;
double result = a / b;        // 3.0 (int division, then convert to double!)
double result2 = (double)a / b; // 3.5 (correct)

char c = 'A';
int x = c;      // x = 65
cout << c + 1;  // 66 (not 'B'!)
cout << char(c + 1); // 'B'
```

---

### Trap 6.2: Static Cast
```cpp
static_cast<double>(3) / 12  // 0.25
3 / 12                       // 0 (integer division)

static_cast<char>(11 / 7 * 3 * 2 * 39 % 102 + 55)
// 11/7=1, 1*3=3, 3*2=6, 6*39=234, 234%102=30, 30+55=85
// static_cast<char>(85) = 'U'
```

---

## 7. Char Array & String Traps

### Trap 7.1: Null Terminator
```cpp
char str[5] = "Hi";  // ['H']['i']['\0'][?][?]
char str2[5] = {'H', 'i'};  // ['H']['i'][?][?][?] - NOT null-terminated!

cout << str;   // "Hi" (stops at \0)
cout << str2;  // "Hi????..." (garbage until \0 found)
```

---

### Trap 7.2: 2D Char Arrays
```cpp
char data[3][11] = {"cat", "dog", "horse"};

// Accessing:
data[0]     // "cat"
data[1][2]  // 'g'
data[2]     // "horse"

// Printing diagonal:
for(int i = 0; i < 3; i++)
    cout << data[i][i];  // "cog"
```

---

## 8. Logical Operators

### Trap 8.1: Short Circuit Evaluation
```cpp
if (a != 0 && b / a > 5) {  // Safe: if a==0, b/a never evaluated
}

if (b / a > 5 && a != 0) {  // CRASH if a==0!
}
```

**Key**: `&&` stops if first is false, `||` stops if first is true.

---

### Trap 8.2: Bitwise vs Logical
```cpp
&   // Bitwise AND
&&  // Logical AND

|   // Bitwise OR
||  // Logical OR

5 & 3   // 1 (binary: 101 & 011 = 001)
5 && 3  // 1 (true, both non-zero)

0 | 1   // 1
0 || 1  // 1 (true)
```

---

## 9. Common Expression Evaluation Traps

```cpp
// Trap 1: Mixed operators
3 * 5 / 4 * 3 * 2 % 4
// Left to right: 15 / 4 = 3, 3 * 3 = 9, 9 * 2 = 18, 18 % 4 = 2

// Trap 2: Boolean to int
(3 != 10 || 6 <= 10 * -200)
// (true || true) = 1

// Trap 3: Character comparison
'b' > 'Z'  // 98 > 90 = 1 (true)

// Trap 4: Power
pow(8, 730 % 9) - pow(2, 5 / 2) / 2
// pow(8, 1) - pow(2, 2) / 2 = 8 - 4/2 = 8 - 2 = 6
```

---

## 10. Memory & Const Traps

### Trap 10.1: Const Variables
```cpp
const int N = 5;
N = 10;  // ERROR: cannot modify const

int arr[N];  // VALID in C++
```

---

### Trap 10.2: Const Parameters
```cpp
void func(const int &x) {
    x = 10;  // ERROR
    cout << x;  // OK
}
```

---

## Quick Reference: Speed Solving

### Pattern Recognition (spot in 5 seconds):

| Pattern | Likely Output |
|---------|---------------|
| `static int x = 0; return x++;` | Incrementing sequence across calls |
| `*ptr++` | Use current, move ptr |
| `arr == &arr[0]` | TRUE |
| `char c = 'A'; c + 1` | 66 (not 'B') |
| `int/int` | Integer division (truncated) |
| Loop with semicolon | Empty loop |
| `arr[]` parameter | Decays to pointer |

---

## Exam Day Checklist

Before attempting any dry run:
- ✅ Check for `static` variables
- ✅ Identify pointer arithmetic (`++`, `--`)
- ✅ Look for pass-by-reference (`&`)
- ✅ Note integer division (no decimal)
- ✅ Check loop termination conditions
- ✅ Verify operator precedence if mixed

**Time Target**: <20 seconds per dry run problem (after practice)

---

**Next**: Practice with Dry Run Set 1 (Pointer Arithmetic Hell) to internalize these patterns!
