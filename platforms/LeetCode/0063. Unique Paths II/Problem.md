# 63. Unique Paths II

> Medium

A robot is on an `m × n` grid. The robot starts at the **top-left corner** `(1, 1)` and can only move **down** or **right** at any point.  
Now some cells are **obstacles** represented as `1` in the grid `obstacleGrid`, and empty cells are `0`.  
Return *the number of unique paths* the robot can take to reach the **bottom-right corner** `(m, n)` without stepping on obstacles.

### Example:

![uniquepathsii1](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

- Input: `obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]`
- Output: `2`

![uniquepathsii2](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

- Input: `obstacleGrid = [[0,1],[0,0]]`
- Output: `1`

- Output: `1`

### Constraints:
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`
