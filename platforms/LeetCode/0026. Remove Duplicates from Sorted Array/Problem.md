# 26. Remove Duplicates from Sorted Array

> Easy

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only once.  
The relative order of the elements should be kept the same.  
Since it is **in-place**, you must place the result in the first part of the array and return the **number of unique elements**.

### Example:
- Input: `nums = [1,1,2]`  
- Output: `2, nums = [1,2,_]`  
- Explanation: The first 2 elements are `[1,2]`. It doesn’t matter what you leave beyond the returned length.

- Input: `nums = [0,0,1,1,1,2,2,3,3,4]`  
- Output: `5, nums = [0,1,2,3,4,_,_,_,_,_]`

### Constraints:
- `0 <= nums.length <= 3·10⁴`
- `-10⁴ <= nums[i] <= 10⁴`
