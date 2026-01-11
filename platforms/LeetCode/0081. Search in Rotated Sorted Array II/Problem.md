# 81. Search in Rotated Sorted Array II

> Medium

Given an integer array `nums` sorted in **non-decreasing order** and then possibly **rotated** at some pivot, return `true` if `target` is in `nums`, or `false` otherwise.  
Unlike the original rotated sorted array problem, this version **may contain duplicates**.

### Example:
- Input: `nums = [2,5,6,0,0,1,2], target = 0`  
- Output: `true`

- Input: `nums = [2,5,6,0,0,1,2], target = 3`  
- Output: `false`

### Constraints:
- `1 <= nums.length <= 5000`
- `-10⁴ <= nums[i] <= 10⁴`
- `nums` is guaranteed to be rotated at some pivot.
- `-10⁴ <= target <= 10⁴`
