# 51. N-Queens

> Hard

The **n-queens puzzle** is the problem of placing `n` queens on an `n × n` chessboard such that **no two queens attack each other**.  
Given an integer `n`, return *all distinct solutions* to the n-queens puzzle.  
Each solution contains a different board configuration of the `n`-queens’ placement, where:
- `'Q'` and `'.'` indicate a **queen** and an **empty space**, respectively.

### Example:

![nqueens](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

- Input: `n = 4`  
- Output: `[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]`  
- Explanation: There are two distinct solutions to the 4-queens puzzle.

- Input: `n = 1`  
- Output: `[["Q"]]`

### Constraints:
- `1 <= n <= 9`
