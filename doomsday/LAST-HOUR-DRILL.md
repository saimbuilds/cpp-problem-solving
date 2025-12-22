# ⚡ LAST HOUR DRILL
## 12:30 PM - 1:00 PM (30 Minutes Before Exam)

> **ZERO NEW LEARNING - ONLY CONFIDENCE BUILDING**

---

# 🎯 12:30 - 12:45 PM: RAPID PATTERN REVIEW

## Speed Read These (2 min each)

### 1. Pointer Quick Rules (2 min)
- `int*` = pointer to int
- `int**` = pointer to pointer (2D arrays)
- `int&` = reference (can't reassign, no nullptr)
- `int*&` = reference to pointer (modify pointer itself)
- Deallocation: `delete` for single, `delete[]` for arrays

---

### 2. Array Traversal Formulas (2 min)
```cpp
// Main diagonal
for(i=0; i<n; i++) arr[i][i]

// Anti-diagonal  
for(i=0; i<n; i++) arr[i][n-1-i]

// Spiral: 4 boundaries (top, bottom, left, right)
// Rotate 90°: Transpose + Reverse rows
```

---

### 3. Recursion Base Cases (2 min)
- Factorial: `if(n<=1) return 1`
- Fibonacci: `if(n<=1) return n`
- Array: `if(n==0) return 0` or `if(index==size) return`
- **Always check:** What's the simplest input?

---

### 4. Loop Bounds (1 min)
```cpp
for(i=0; i<n; i++)     // 0 to n-1 (SAFE)
for(i=0; i<=n; i++)    // 0 to n (DANGER - extra iteration)
for(i=1; i<=n; i++)    // 1 to n (use for counting)
```

---

### 5. Common Errors to Check (3 min)
✅ **Before submitting answer:**
- [ ] Did I delete dynamically allocated memory?
- [ ] Are all array indices within bounds?
- [ ] Did I handle base case in recursion?
- [ ] Did I initialize variables before using them?
- [ ] Did I use correct comparison (`<` vs `<=`)?
- [ ] Did I close file after opening? (if file I/O question)

---

### 6. Project Cheat Codes (2 min)
**If question asks about:**
- "Managing multiple objects" → Parallel arrays
- "Collision detection" → AABB (4 conditions)
- "File I/O" → Read to arrays, process, write back
- "Grid systems" → Pixel/cellSize for conversion

---

# 📝 12:45 - 12:50 PM: EXAM ROOM STRATEGY

## The 3-Pass System

### Pass 1: Skim (First 5 min in exam)
1. Read entire paper quickly
2. Mark each question:
   - ✅ = I know this instantly
   - ⚠️ = Need to think
   - ❌ = Very hard / might skip
3. Count answer space for each question
4. Plan your time splits

---

### Pass 2: Execute (Next 2.5 hours)
**Order of attack:**
1. All ✅ questions first (build momentum)
2. All ⚠️ questions next
3. All ❌ questions last (attempt what you can)

**Time per question estimate:**
- Short question (2-3 marks): ~10 min
- Medium question (5-7 marks): ~20 min  
- Long question (10+ marks): ~30-40 min

---

### Pass 3: Review (Last 20 min)
1. Check syntax errors (missing `;`, `{}`)
2. Verify loop bounds
3. Check for neatness (can they read it?)
4. Add comments to partial answers

---

## In-Exam Tracing Technique

**For "What's the output?" questions:**

1. Draw mini table:
```
Line | Var1 | Var2 | Output
-----|------|------|-------
 1   |  5   |  0   |
 2   |  5   |  5   |
 3   |  5   |  5   | "5"
```

2. Track one line at a time
3. Don't skip steps mentally
4. Write final output clearly

---

# 🧘 12:50 - 12:55 PM: PHYSICAL PREP

## Do This Literally

1. **Pack your bag:**
   - [ ] 2 pens (blue/black)
   - [ ] 1 pencil + eraser
   - [ ] Student ID
   - [ ] Admit card (if required)
   - [ ] Water bottle (if allowed)

2. **Quick body reset:**
   - Stand up, stretch arms
   - Roll shoulders 5 times
   - Take 3 deep breaths (4 sec in, 4 sec out)
   - Shake hands to release tension

3. **Mental reset:**
   - Say out loud: "I've coded a 4765-line game. I can handle this."
   - Don't review anything new (anxiety trap)
   - Don't talk to stressed classmates

---

# 🚀 12:55 PM: WALK TO EXAM HALL

## Mindset Mantras

Repeat these while walking:

1. **"I know patterns, not just syntax."**
   - You've crammed all the logic
   - It's about recognition, not memorization

2. **"Partial credit > 0 credit."**
   - If stuck, write algorithm in comments
   - Show your thinking process
   - Never leave blank

3. **"I answer what I know first."**
   - Don't get stuck on one question
   - Build confidence with easy wins

4. **"Neatness = Free marks."**
   - Clear handwriting
   - Proper indentation
   - Comments for clarity

---

# 📋 IN EXAM HALL (Waiting for Paper)

## The 60-Second Calm Routine

**When seated, before paper:**

1. **Organize desk** (15 sec)
   - Pen on right
   - ID on desk
   - Water bottle under chair

2. **Breathing** (30 sec)
   - Close eyes
   - Breathe: 4 counts in, 4 counts out (repeat 3x)
   - Relax shoulders

3. **Micro-visualization** (15 sec)
   - Picture yourself writing first answer
   - Imagine turning in completed paper
   - Smile (releases tension)

---

# 🎯 WHEN PAPER ARRIVES

## First 10 Minutes Checklist

```
[ ] Write name/ID on answer sheet
[ ] Verify page count (all pages present?)
[ ] Read all instructions box carefully
[ ] Skim entire paper (mark difficulty)
[ ] Plan rough time allocation
[ ] Choose starting question (easiest one)
[ ] BEGIN!
```

---

# 🚨 EMERGENCY PROTOCOLS

## If You Blank Out Mid-Exam

**Scenario:** You're stuck on a question, brain freezes

**Solution (90-second reset):**
1. Put pen down
2. Close eyes, take 3 deep breaths
3. Read question again slowly
4. Skip to next question, come back later
5. **Remember:** Your brain needs a break, not more pressure

---

## If Running Out of Time

**15 minutes left, still have questions:**

**Priority system:**
1. Finish current answer (even partially)
2. Skim remaining questions
3. Write algorithms in comments (pseudocode = partial credit)
4. Fill in easy remaining questions first
5. Mark incomplete work clearly

**Example incomplete answer:**
```cpp
// Algorithm:
// 1. Traverse array from 0 to n-1
// 2. For each element, check if already exists
// 3. If duplicate, shift array left
// 4. Decrement size

// Due to time, partial implementation:
for(int i = 0; i < n; i++) {
    // Check duplicate logic here
}
```

---

## If Question Seems Impossible

**"I have NO idea what this is asking"**

**Salvage strategy:**
1. Break question into parts
2. Answer what you DO understand
3. Make reasonable assumptions (state them)
4. Show related knowledge

**Example:**
```
Question: "Implement inverse of a matrix"
If you don't know full algorithm:

Answer: 
```cpp
// Matrix inverse requires:
// 1. Calculate determinant
// 2. Find cofactor matrix
// 3. Transpose cofactor matrix (adjoint)
// 4. Divide adjoint by determinant

// Partial implementation (transpose step):
void transpose(int arr[][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

// [State: Could not complete full inverse in given time]
```
```

**Shows:** You understand components even if not complete solution

---

# 💪 CONFIDENCE AFFIRMATIONS

## Read These if Anxious

**Before exam:**
- ✅ You built a 4765-line game in C++
- ✅ You've coded parallel arrays, collision detection, file I/O, recursion
- ✅ You've crammed all major patterns tonight
- ✅ You know more than you think

**During exam:**
- ✅ You don't need 100% - aim for your best
- ✅ Every mark counts (partial credit exists)
- ✅ You've survived this long - you can handle 3 hours

**If struggling:**
- ✅ Others are struggling too
- ✅ Move to next question - come back later
- ✅ Your worth ≠ one exam score

---

# 🎓 FINAL REMINDERS

## The 5 Golden Rules

### 1. **READ INSTRUCTIONS FULLY**
- Check constraints
- Note: "Must use recursion" or "No loops allowed"
- Verify output format

### 2. **MANAGE SPACE**
- Don't overflow answer area
- Write smaller if needed
- No extra sheets given

### 3. **SHOW YOUR WORK**
- Comments = partial credit
- Algorithm steps = proof you understand

### 4. **CHECK SYNTAX**
- Missing `;`
- Mismatched `{}`
- Array bounds

### 5. **STAY CALM**
- 3 hours is enough time
- You've prepared well
- Trust your cramming

---

# ⏰ TIME CHECK

**Current time: 12:55 PM**
**Exam starts: 1:00 PM**

**RIGHT NOW:**
1. Close this document
2. Take 3 deep breaths
3. Head to exam hall
4. Trust yourself

---

# 🔥 FINAL MESSAGE

You've:
- ✅ Built an entire game
- ✅ Studied the ultimate cheat sheet
- ✅ Reviewed project patterns
- ✅ Followed the battle plan

**You're ready.**

**Now go show them what you know.**

**Walk in confident. Walk out victorious.**

---

**SEE YOU ON THE OTHER SIDE** 🚀

**YOU'VE GOT THIS!** 💪
