# 79. Word Search

> Medium

Given an `m × n` board of characters `board` and a string `word`, return `true` if `word` exists in the grid; otherwise, return `false`.  
The word must be constructed from letters of sequentially adjacent cells, where **adjacent** cells are horizontal or vertical neighbors.  
The same letter cell may **not** be used more than once.

### Example:

![wordsearch1](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

- Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"`
- Output: `true`

![wordsearch2](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

- Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"`
- Output: `true`

![wordsearch3](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

- Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"`
- Output: `false`

### Constraints:
- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 10`
- `1 <= word.length <= 10⁵`
- `board` and `word` consists of only lowercase and uppercase English letters.