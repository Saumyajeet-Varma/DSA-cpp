# 48. Rotate Image

> Medium

You are given an `n × n` 2D matrix `matrix` representing an image, rotate the image by **90 degrees clockwise** *in-place*.

### Example:

![rotatematrix2](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

- Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
- Output: `[[7,4,1],[8,5,2],[9,6,3]]`

![rotatematrix2](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)

- Input: `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`
- Output: `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`


### Constraints:
- `n == matrix.length == matrix[i].length`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`
