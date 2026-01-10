# 12. Integer to Roman

> Medium

Given an integer `num`, convert it to a Roman numeral.

Roman numerals are represented by seven different symbols:  
| Symbol | Value |
|------|-------|
| `I`  | 1     |
| `V`  | 5     |
| `X`  | 10    |
| `L`  | 50    |
| `C`  | 100   |
| `D`  | 500   |
| `M`  | 1000  |
 
Roman numerals are usually written from largest to smallest from left to right. However, in certain cases, subtractive notation is used:
- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

### Example:
- Input: `num = 3`  
- Output: `"III"`

### Constraints:
- `1 <= num <= 3999`
