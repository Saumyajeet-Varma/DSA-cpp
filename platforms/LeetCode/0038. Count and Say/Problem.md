# 37. Count and Say

> Medium

The **count-and-say sequence** is a sequence of digit strings defined by the following process:

1. `1` is the first term of the sequence.
2. To generate the next term from the previous term, **read off the digits** of the previous term, counting the number of digits in groups of the same digit.

Given an integer `n`, return *the nth term* of the count-and-say sequence.

### Example:

- Input: `n = 1`  
- Output: `"1"`
- Explanation: `This is the base case`

- Input: `n = 4`  
- Output: `"1211"`  
- Explanation:  
  The sequence starts:  
  `1` → `"11"` (one 1) → `"21"` (two 1s) → `"1211"` (one 2, one 1)


### Constraints:
- `1 <= n <= 30`
