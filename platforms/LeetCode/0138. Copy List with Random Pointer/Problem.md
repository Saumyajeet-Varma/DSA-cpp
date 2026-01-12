# 138. Copy List with Random Pointer

> Medium

A **linked list** of length `n` is given such that each node contains an additional **random pointer** that could point to **any node** in the list or **null**.  
Construct a **deep copy** of the list and return *the head* of the copied list.

### Example:

![copylistwithrandompointer1](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

- Input: `head = [[7,null],[13,0],[11,4],[10,2],[1,0]]`  
- Output: `[[7,null],[13,0],[11,4],[10,2],[1,0]]`

![copylistwithrandompointer2](https://assets.leetcode.com/uploads/2019/12/18/e2.png)

- Input: `head = [[1,1],[2,1]]`  
- Output: `[[1,1],[2,1]]`

![copylistwithrandompointer3](https://assets.leetcode.com/uploads/2019/12/18/e3.png)

- Input: `head = [[3,null],[3,0],[3,null]]`  
- Output: `[[3,null],[3,0],[3,null]]`

### Constraints:
- `0 <= n <= 1000`
- `-10⁴ <= Node.val <= 10⁴`
- `Node.random` is either `null` or points to **any node** in the list.
