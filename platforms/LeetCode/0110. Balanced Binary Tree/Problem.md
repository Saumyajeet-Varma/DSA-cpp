# 110. Balanced Binary Tree

> Easy

Given the `root` of a binary tree, return `true` if it is **height-balanced**, or `false` otherwise.  
A binary tree is **height-balanced** if **for every node**, the difference in height between its left subtree and right subtree is **no more than 1**.

### Example:

![balancedbinarytree1](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

- Input: `root = [3,9,20,null,null,15,7]`  
- Output: `true`

![balancedbinarytree1](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

- Input: `root = [1,2,2,3,3,null,null,4,4]`  
- Output: `false`

- Input: `root = []`  
- Output: `true`

### Constraints:
- `0 <= sz <= 5000`
- `-10⁴ <= Node.val <= 10⁴`
