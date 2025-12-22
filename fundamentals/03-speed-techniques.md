# Speed Techniques - Exam Time Savers

> **Purpose**: Solve problems FASTER. You have 3 hours for 50 marks. Every minute counts.

---

## Time Budget (3 Hour Exam)

Typical exam breakdown:
- **MCQs/Short** (10 marks): 15 minutes
- **Dry Runs** (20 marks): 50 minutes  
- **Function Completion** (10 marks): 25 minutes
- **Programming** (10 marks): 60 minutes
- **Buffer/Review**: 30 minutes

**Total**: 180 minutes

**Golden Rule**: If stuck >3 minutes, SKIP and return later. Mark clearly.

---

## Technique 1: Dry Run Speed Solving

### Standard Approach (Slow):
```
Read problem → Write all variables → Trace line by line → Write output
Time: 3-5 minutes per problem
```

### Speed Approach:
```
1. Scan for patterns (5 sec)
2. Identify trap type (5 sec)
3. Trace critical path only (30 sec)
4. Write output (5 sec)
```
**Time**: 45 seconds per problem

---

### Pattern Recognition Shortcuts:

| When You See... | Likely Trap | Quick Check |
|----------------|-------------|-------------|
| `static int` | Value persists across calls | Increment by 1 each call |
| `*ptr++` | Use then move | Current value, ptr shifts |
| `arr[i][j]` in loop | Index confusion | Check bounds carefully |
| `&` in parameters | Pass by reference | Original modified |
| `char` in arithmetic | ASCII conversion | 'A' = 65 |
| Multiple `++`/`--` | Operator precedence | Parenthesize mentally |
| Recursion | Stack trace | Draw tree for small input |

---

### Example: Speed vs Standard

```cpp
// Problem:
int get() {
    static int x = 0;
    return x++;
}
int main() {
    cout << get() << get() << get();
}
```

**Standard Approach (2 min)**:
```
Call 1: x = 0, return 0, x becomes 1
Call 2: x = 1, return 1, x becomes 2
Call 3: x = 2, return 2, x becomes 3
Output: "012"... wait, right to left evaluation!
Output: "210"
```

**Speed Approach (30 sec)**:
```
Pattern: static → incrementing sequence
Trap: Output order (right-to-left in cout)
Answer: "210"
```

---

## Technique 2: Memory Diagram Shortcuts

### Don't Draw EVERYTHING:
Only draw what changes or what's confusing.

#### Example:
```cpp
int arr[] = {10, 20, 30, 40};
int *p = arr + 1;
*p++ = 50;
cout << arr[1] << " " << arr[2];
```

**Efficient Diagram**:
```
p → [10][20][30][40]
         ↑
    arr[1] = 50, then p moves
Result: 50 30
```

**Don't waste time drawing**:
- Entire stack frame
- All memory addresses
- Variables that don't change

---

## Technique 3: Code Skeleton for Programming Questions

Don't start from scratch. Use templates!

### Array Problem Template:
```cpp
int main() {
    int n;
    cin >> n;
    
    // Allocate if dynamic
    int *arr = new int[n];
    
    // Input
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    // [YOUR LOGIC HERE]
    
    // Output
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    // Cleanup
    delete[] arr;
    return 0;
}
```

### 2D Array Template:
```cpp
int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    // Allocate
    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    
    // Input
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    
    // [YOUR LOGIC HERE]
    
    // Output
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
    // Cleanup
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
```

### Recursion Template:
```cpp
int recursive_func(int n) {
    // Base case FIRST
    if (n <= BASE_VALUE)
        return BASE_RESULT;
    
    // Recursive case
    return OPERATION(recursive_func(n - 1));
}
```

**Time Saved**: 2-3 minutes per problem (no syntax errors!)

---

## Technique 4: Restrict Complexity with Problem Constraints

### Example Restriction: "Use max 2 variables"
```cpp
// Task: Reverse array in-place, max 2 variables

// BAD (3 variables):
for (int i = 0, j = n-1; i < j; i++, j--) {
    int temp = arr[i];  // 3rd variable!
    arr[i] = arr[j];
    arr[j] = temp;
}

// GOOD (2 variables):
for (int i = 0; i < n/2; i++) {
    arr[i] ^= arr[n-1-i];      // XOR swap trick
    arr[n-1-i] ^= arr[i];
    arr[i] ^= arr[n-1-i];
}
```

### Common Restriction Workarounds:

| Restriction | Workaround |
|-------------|-----------|
| Max 2 variables | Use XOR swap, array elements as temp |
| Single loop | Use multiple loop variables (i, j) |
| No array indexing | Use pointers only |
| No global/static | Pass by reference |

---

## Technique 5: Output Prediction Without Full Trace

For simple dry runs, predict without writing:

```cpp
// Problem:
for (int i = 1; i < 9; i++) {
    spaces(9-i);
    equals(i);
    cout << endl;
}
```

**Don't trace all 8 iterations!**
```
Pattern: Decreasing spaces, increasing equals
i=1: 8 spaces, 1 equals
i=2: 7 spaces, 2 equals
...
i=8: 1 space, 8 equals

Output: Right-aligned triangle pattern
```

**Time**: 10 seconds vs 2 minutes

---

## Technique 6: Function Completion Shortcuts

### Read the Test Case FIRST!
Don't code blindly. See what output is expected.

```cpp
// Given test: input "cat", "dog" → output true
// What's the pattern?
```

Then code with that specific case in mind.

### Use Descriptive Variable Names:
```cpp
// BAD (confusing):
for (int a = 0; a < b; a++)
    for (int c = 0; c < d; c++)
        e[a][c] = a + c;

// GOOD (clear):
for (int row = 0; row < rows; row++)
    for (int col = 0; col < cols; col++)
        matrix[row][col] = row + col;
```

**Time Saved**: Less debugging, fewer errors

---

## Technique 7: Syntax Error Prevention

### Common Mistakes to Avoid:

```cpp
// WRONG              // RIGHT
delete arr;           delete[] arr;        // Arrays use []
arr = malloc(...);    arr = new int[...];  // Use new, not malloc in C++
for (i = 0, i < n)    for (i = 0; i < n)   // Semicolons in for
if (x = 5)            if (x == 5)          // == for comparison
cout << x             cout << x;           // Don't forget semicolon
```

**Habit**: Always write `delete[]` immediately after `new[]`

---

## Technique 8: Verification in 30 Seconds

After solving, quick checklist:

1. ✅ **Boundary conditions**: n=0, n=1, max size
2. ✅ **Memory**: Every `new` has `delete`
3. ✅ **Loops**: Correct bounds (< vs <=)
4. ✅ **Output format**: Spaces, newlines match expected
5. ✅ **Variables initialized**: No wild pointers

**Don't**: Re-trace entire code. Spot-check only.

---

## Technique 9: Partial Credit Strategy

If stuck on a hard problem:

### Write Structure Even If Logic Incomplete:
```cpp
bool checkPalindrome(char arr[][10], int size) {
    // TODO: Check square
    if (size != size)  // placeholder
        return false;
    
    // TODO: Check diagonal
    
    // TODO: Check rows
    
    // TODO: Check cols
    
    return true;  // Partial structure = partial credit!
}
```

**Partial Credit**: 30-40% for structure vs 0% for blank.

---

## Technique 10: Time Management During Exam

### First 10 Minutes:
- Scan entire paper
- Mark easy wins (simple dry runs, MCQs)
- Identify hardest 2 problems

### Next 60 Minutes:
- Solve ALL easy problems (bank 60% marks)
- Attempt medium problems

### Next 60 Minutes:
- Tackle hard problems
- Write partial solutions if stuck

### Last 30 Minutes:
- Return to skipped problems
- Verify all outputs
- Check for syntax errors

**NEVER** spend 30 minutes on one problem if others unsolved!

---

## Quick Reference: Time Targets

| Question Type | Target Time | If Stuck |
|--------------|-------------|-----------|
| MCQ | 30 sec each | Skip, return later |
| Simple dry run | 45 sec | 2 min max |
| Complex dry run | 2 min | Draw diagram |
| Function completion | 5 min | Write structure |
| Programming (10 marks) | 15 min | Partial code |

---

## Final Exam Day Hacks

### Pre-Exam (30 min before):
- Don't learn new concepts
- Review cheat sheet
- Solve 3-5 easy dry runs (confidence booster)
- Deep breaths!

### During Exam:
- Read questions carefully (2 min scanning)
- Start with easiest (momentum)
- Use pencil for rough work
- Circle answers clearly

### Mental Game:
- **If panicking**: Close eyes, breathe 5 seconds, refocus
- **If blanking**: Skip and return
- **If time running out**: Prioritize partial credit

---

## Practice Schedule for Speed

### Week Before Exam:
- Day 1-3: Accuracy (no time limit)
- Day 4-5: Speed (set 2 min timer per dry run)
- Day 6: Mock exam (full 3 hours)
- Day 7: Review mistakes

### Day Before Exam:
- Solve 10 easy problems (90% success rate)
- Skim cheat sheets
- Early sleep (8 hours!)

---

**Remember**: Speed comes from PATTERN RECOGNITION, not rushing.

After 100+ practice problems, you'll spot patterns in 5 seconds. That's when you hit exam speed!

**Next**: Start practicing with **Dry Run Set 1** and time yourself. Target: <90 seconds per problem by end of Day 1.
