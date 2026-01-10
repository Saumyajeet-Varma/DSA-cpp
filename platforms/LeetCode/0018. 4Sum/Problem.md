# 18. 4Sum

> Medium

Given an integer array `nums` and an integer `target`, return all the **unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:
- `a`, `b`, `c`, and `d` are **distinct indices**, and  
- `nums[a] + nums[b] + nums[c] + nums[d] == target`.

The solution set **must not contain duplicate quadruplets**, and the order of quadruplets in the output does not matter.

### Example:
- Input: `nums = [1,0,-1,0,-2,2], target = 0`  
- Output: `[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]`

### Constraints:
- `4 <= nums.length <= 200`
- `-10⁵ <= nums[i] <= 10⁵`
- `-10⁹ <= target <= 10⁹`
