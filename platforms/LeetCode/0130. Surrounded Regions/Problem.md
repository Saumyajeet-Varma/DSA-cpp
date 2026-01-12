# 130. Surrounded Regions

> Medium

Given an `m × n` board `board` containing `'X'` and `'O'`, capture all regions that are **surrounded by `'X'`**.  
A region is captured by flipping all `'O'`s into `'X'`s **in that surrounded region**.  
A region is **surrounded** if it is completely enclosed by `'X'` on all four sides (horizontal and vertical).  
Note that any `'O'` connected to the **border** should **not** be flipped.

### Example:

![surroundedregions](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

- Input: `board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]`
- Output: `[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]`

- Input: `board = [["X"]]`
- Output: `[["X"]]`

### Constraints:
- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`