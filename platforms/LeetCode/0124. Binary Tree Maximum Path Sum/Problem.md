# 124. Binary Tree Maximum Path Sum

> Hard

Given the `root` of a binary tree, return *the maximum path sum*.  
For this problem, a **path** is defined as any sequence of nodes from some starting node to **any node** in the tree along the parent-child connections.  
The path must contain **at least one node**, and does **not** need to go through the root.

### Example:

![binarytreemaximumpathsum1](https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg)

- Input: `root = [1,2,3]`  
- Output: `6`  
- Explanation: The path `2 → 1 → 3` has the largest sum.

![binarytreemaximumpathsum2](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)

- Input: `root = [-10,9,20,null,null,15,7]`  
- Output: `42`  
- Explanation: The path `15 → 20 → 7` has the largest sum.

### Constraints:
- `1 <= sz <= 3 * 10⁴`
- `-1000 <= Node.val <= 1000`
