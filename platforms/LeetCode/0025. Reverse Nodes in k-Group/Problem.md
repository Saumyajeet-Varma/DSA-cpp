# 25. Reverse Nodes in k-Group

> Hard

Given the `head` of a linked list and a positive integer `k`, reverse the nodes of the list **k at a time** and return *the modified list*.  
If the number of nodes is not a multiple of `k`, the remaining nodes at the end should **remain in their original order**.  
You **may not** change the node values—only the nodes themselves may be changed.

### Example:

![reversenodesinkgroup1](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

- Input: `head = [1,2,3,4,5], k = 2`  
- Output: `[2,1,4,3,5]`

![reversenodesinkgroup2](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

- Input: `head = [1,2,3,4,5], k = 3`  
- Output: `[3,2,1,4,5]`

### Constraints:
- `1 <= k <= n <= 5000`
- `0 <= Node.val <= 1000`
