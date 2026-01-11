# 39. Combination Sum

> Medium

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all unique combinations* of `candidates` where the chosen numbers sum to `target`.  
You may return the combinations in any order.  
The same number may be chosen from `candidates` **unlimited times**. Two combinations are unique if the **frequency of at least one chosen number is different**.

### Example:
- Input: `candidates = [2,3,6,7], target = 7`  
- Output: `[[2,2,3],[7]]`

- Input: `candidates = [2,3,5], target = 8`  
- Output: `[[2,2,2,2],[2,3,3],[3,5]]`

- Input: `candidates = [2], target = 1`  
- Output: `[]`

### Constraints:
- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 40`
- `All elements of candidates are distinct.`
- `1 <= target <= 40`
