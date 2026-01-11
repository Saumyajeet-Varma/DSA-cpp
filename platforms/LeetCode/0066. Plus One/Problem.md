# 66. Plus One

> Easy

You are given a **large integer** represented as an array of digits `digits`, where each element is a **single digit**.  
The digits are ordered **most significant to least significant**.  
Increment the integer by **one** and return *the resulting array of digits*.

### Example:
- Input: `digits = [1,2,3]`  
- Output: `[1,2,4]`  
- Explanation: `123 + 1 = 124`

- Input: `digits = [4,3,2,1]`  
- Output: `[4,3,2,2]`

- Input: `digits = [9,9]`  
- Output: `[1,0,0]`

### Constraints:
- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading `0`'s.