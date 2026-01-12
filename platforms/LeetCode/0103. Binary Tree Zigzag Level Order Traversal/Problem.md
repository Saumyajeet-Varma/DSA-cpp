# 103. Binary Tree Zigzag Level Order Traversal

> Medium

Given the `root` of a binary tree, return *the zigzag level order traversal* of its nodes’ values.  
(Zigzag level order means the values alternate between **left-to-right** and **right-to-left** on each level.)

### Example:

![binarytreezigzaglevelordertraversal](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

- Input: `root = [3,9,20,null,null,15,7]`  
- Output: `[[3],[20,9],[15,7]]`

- Input: `root = [1]`  
- Output: `[[1]]`

- Input: `root = []`  
- Output: `[]`

### Constraints:
- `0 <= no. of Nodes <= 2000`
- `-100 <= Node.val <= 100`
