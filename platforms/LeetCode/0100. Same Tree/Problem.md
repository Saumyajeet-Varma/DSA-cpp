# 100. Same Tree

> Easy

Given the roots of two binary trees `p` and `q`, write a function to **check if they are the same** or not.  
Two binary trees are the same if they are structurally identical and the nodes have the **same values**.

### Example:

![sametree1](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

- Input: `p = [1,2,3], q = [1,2,3]`  
- Output: `true`

![sametree2](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

- Input: `p = [1,2], q = [1,null,2]`  
- Output: `false`

![sametree3](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

- Input: `p = [1,2,1], q = [1,1,2]`  
- Output: `false`

### Constraints:
- The number of nodes in both trees is in the range `[0, 100]`
- `-10⁴ <= Node.val <= 10⁴`

