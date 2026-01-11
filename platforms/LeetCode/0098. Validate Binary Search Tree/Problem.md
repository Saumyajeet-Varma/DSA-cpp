# 98. Validate Binary Search Tree

> Medium

Given the `root` of a binary tree, determine whether it is a **valid binary search tree (BST)**.  
A **BST** is defined as follows:
- The left subtree of a node contains only nodes with **keys less than** the node’s key.
- The right subtree of a node contains only nodes with **keys greater than** the node’s key.
- Both the left and right subtrees must also be **binary search trees**.

### Example:

![validatebinarysearchtree1](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

- Input: `root = [2,1,3]`  
- Output: `true`

![validatebinarysearchtree2](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

- Input: `root = [5,1,4,null,null,3,6]`  
- Output: `false`

### Constraints:
- The number of nodes in the tree is in the range `[1, 10⁴]`
- `-2³¹ <= Node.val <= 2³¹ - 1`
