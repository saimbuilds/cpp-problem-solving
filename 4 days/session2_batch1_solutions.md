# SESSION 2 - BATCH 1: SOLUTIONS
**Easy Recursion Problems - With Call Stack Traces**

---

## SOLUTION 1: Simple Countdown
**Output:** `5 4 3 2 1 `

**Call Stack:**
```
countdown(5) → print 5 → countdown(4)
  countdown(4) → print 4 → countdown(3)
    countdown(3) → print 3 → countdown(2)
      countdown(2) → print 2 → countdown(1)
        countdown(1) → print 1 → countdown(0)
          countdown(0) → return (base case)
```

---

## SOLUTION 2: Factorial
**Output:** `24`

**Trace:** `4! = 4 × 3 × 2 × 1 = 24`

**Call Stack:**
```
factorial(4) = 4 * factorial(3)
  factorial(3) = 3 * factorial(2)
    factorial(2) = 2 * factorial(1)
      factorial(1) = 1 (base case)
    returns 2 * 1 = 2
  returns 3 * 2 = 6
returns 4 * 6 = 24
```

---

## SOLUTION 3: Sum of Numbers
**Output:** `15`

**Trace:** `5 + 4 + 3 + 2 + 1 + 0 = 15`

---

## SOLUTION 4: Print Forward
**Output:** `1 2 3 4 `

**Explanation:** Recursion happens FIRST, then printing. So it prints in ascending order!

**Call Stack:**
```
printForward(4) → call printForward(3) → then print 4
  printForward(3) → call printForward(2) → then print 3
    printForward(2) → call printForward(1) → then print 2
      printForward(1) → call printForward(0) → then print 1
        printForward(0) → return
      prints 1
    prints 2
  prints 3
prints 4
```

---

## SOLUTION 5: Power Function
**Output:** `8`

**Trace:** `2³ = 2 × 2 × 2 = 8`

---

## SOLUTION 6: Count Digits
**Output:** `5`

**Trace:**
```
countDigits(12345) = 1 + countDigits(1234)
                   = 1 + 1 + countDigits(123)
                   = 1 + 1 + 1 + countDigits(12)
                   = 1 + 1 + 1 + 1 + countDigits(1)
                   = 1 + 1 + 1 + 1 + 1 + countDigits(0)
                   = 5
```

---

## SOLUTION 7: Sum of Digits
**Output:** `6`

**Trace:** `123 → 3 + 2 + 1 = 6`

---

## SOLUTION 8: Fibonacci
**Output:** `5`

**Sequence:** 0, 1, 1, 2, 3, **5**

---

## SOLUTION 9: Print Stars
**Output:** `*****`

---

## SOLUTION 10: Array Sum
**Output:** `10`

**Trace:** `1 + 2 + 3 + 4 = 10`

---

## SOLUTION 11: Reverse Print
**Output:** `3 2 1 `

---

## SOLUTION 12: Product of Numbers
**Output:** `120`

**Trace:** `5 × 4 × 3 × 2 × 1 = 120` (same as factorial)

---

## SOLUTION 13: Print Pattern
**Output:**
```
***
**
*
```

---

## SOLUTION 14: GCD
**Output:** `6`

**Trace:**
```
gcd(48, 18) = gcd(18, 12)
            = gcd(12, 6)
            = gcd(6, 0)
            = 6
```

---

## SOLUTION 15: Array Max
**Output:** `9`

**Explanation:** Finds maximum value in array recursively.

---

**Next:** `session2_batch2_problems.md`
