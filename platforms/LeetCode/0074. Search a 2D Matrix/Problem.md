# 74. Search a 2D Matrix

> Medium

Write an efficient algorithm that searches for a value `target` in an `m × n` matrix `matrix`.  
This matrix has the following properties:
- Integers in each row are sorted in **ascending** order from left to right.
- The first integer of each row is **greater than** the last integer of the previous row.

Return `true` if `target` is in the matrix; otherwise, return `false`.

### Example:

![searcha2dmatrix1](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

- Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
- Output: true

![searcha2dmatrix2](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

- Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
- Output: false

### Constraints:
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10⁴ <= matrix[i][j] <= 10⁴`