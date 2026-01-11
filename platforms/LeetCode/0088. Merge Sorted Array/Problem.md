# 88. Merge Sorted Array

> Easy

You are given two **sorted** integer arrays `nums1` and `nums2`, and two integers `m` and `n` representing the number of initialized elements in `nums1` and `nums2` respectively.  
Merge `nums2` into `nums1` **in-place**, so that the final array is sorted.  
The final sorted array should not be returned — it should be stored inside the array `nums1`.

### Example:
- Input: `nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3`  
- Output: `[1,2,2,3,5,6]`

- Input: `nums1 = [1], m = 1, nums2 = [], n = 0`  
- Output: `[1]`

- Input: `nums1 = [0], m = 0, nums2 = [1], n = 1`  
- Output: `[1]`

### Constraints:
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10⁹ <= nums1[i], nums2[i] <= 10⁹`
