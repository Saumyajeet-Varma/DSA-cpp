# 167. Two Sum II - Input Array Is Sorted

> Medium

Given an integer array `numbers` that is **sorted in non-decreasing order**, and a **target** integer `target`, return *the 1-indexed* positions of the two numbers such that they add up to `target`.  
You may assume that **exactly one solution exists**, and you may **not use the same element twice**.  
Return the answer as an array `[index1, index2]` of length `2` with **1-indexed** values.

### Example:
- Input: `numbers = [2,7,11,15], target = 9`  
- Output: `[1,2]`

- Input: `numbers = [2,3,4], target = 6`  
- Output: `[1,3]`

- Input: `numbers = [-1,0], target = -1`  
- Output: `[1,2]`

### Constraints:
- `2 <= numbers.length <= 3·10⁴`
- `-10⁵ <= numbers[i] <= 10⁵`
- `numbers` is sorted in non-decreasing order
