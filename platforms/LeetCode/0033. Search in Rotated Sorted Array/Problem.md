# 33. Search in Rotated Sorted Array

> Medium

Given an integer array `nums` sorted in **ascending order**, and an integer `target`, suppose that `nums` is **rotated** at some pivot unknown to you beforehand (i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).  
If `target` is found in the array, return *its index*; otherwise, return `-1`.

### Example:
- Input: `nums = [4,5,6,7,0,1,2], target = 0`  
- Output: `4`

- Input: `nums = [4,5,6,7,0,1,2], target = 3`  
- Output: `-1`

- Input: `nums = [1], target = 0`  
- Output: `-1`

### Constraints:
- `1 <= nums.length <= 5000`
- `-10⁴ <= nums[i] <= 10⁴`
- `nums` contains **distinct** values.
- `nums` is an ascending array that is possibly rotated.
- `-10⁴ <= target <= 10⁴`
