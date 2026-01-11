# 94. Binary Tree Inorder Traversal

> Easy

Given the `root` of a binary tree, return *the inorder traversal* of its nodes’ values.

### Example:

![binarytreeinordertraversal](https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png)

- Input: `root = [1,null,2,3]`  
- Output: `[1,2,3]`

![binarytreeinordertraversal](https://assets.leetcode.com/uploads/2024/08/29/tree_2.png)

- Input: `root = [1,2,3,4,5,null,8,null,null,6,7,9]`
- Output: `[4,2,6,5,7,1,3,9,8]`

- Input: `root = []`  
- Output: `[]`

- Input: `root = [1]`  
- Output: `[1]`

### Constraints:
- The number of nodes in the tree is in the range `[0, 100]`
- `-100 <= Node.val <= 100`
