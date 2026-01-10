# 13. Roman to Integer

> Easy

Given a Roman numeral string `s`, convert it to its integer value.

Roman numerals are represented by seven different symbols:

| Symbol | Value |
|--------|-------|
| `I`    | 1     |
| `V`    | 5     |
| `X`    | 10    |
| `L`    | 50    |
| `C`    | 100   |
| `D`    | 500   |
| `M`    | 1000  |

Normally, Roman numerals are written from largest to smallest from left to right.  
However, in some cases, a smaller value placed before a larger one means subtraction.  
For example, `IV` = `5 - 1` = `4` and `IX` = `10 - 1` = `9`.

### Example:
- Input: `s = "III"`  
- Output: `3`  
- Explanation: `I + I + I = 3`

### Constraints:
- `1 <= s.length <= 15`  
- `s` contains only the characters (`I`, `V`, `X`, `L`, `C`, `D`, `M`).  
- It is guaranteed that `s` is a valid Roman numeral in the range `[1, 3999]`.
