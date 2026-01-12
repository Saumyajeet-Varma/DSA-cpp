# 120. Triangle

> Medium

Given a **triangle** array `triangle`, return *the minimum path sum* from top to bottom.  
For each step, you may move to **adjacent numbers** on the row below.  
More formally, if you are on index `i` on the current row, you may move to either index `i` or `i + 1` on the next row.

### Example:
- Input: `triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]`  
- Output: `11`  
- Explanation: The minimum path sum is `2 → 3 → 5 → 1 = 11`.

- Input: `triangle = [[-10]]`  
- Output: `-10`

### Constraints:
- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- `-10⁴ <= triangle[i][j] <= 10⁴`
