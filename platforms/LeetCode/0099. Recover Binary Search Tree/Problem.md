# 99. Recover Binary Search Tree

> Medium

You are given the `root` of a binary search tree (BST) where the values of **two nodes** have been **swapped by mistake**.  
Recover the tree without changing its structure, so that it becomes a **valid BST** again.

### Example:

![recoverbinarytreesearch1](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)

- Input: `root = [1,3,null,null,2]`  
- Output: `[3,1,null,null,2]`

![recoverbinarytreesearch2](https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg)

- Input: `root = [3,1,4,null,null,2]`  
- Output: `[3,2,4,1]`

### Constraints:
- The number of nodes in the tree is in the range `[2, 1000]`
- `-2³¹ <= Node.val <= 2³¹ - 1`
