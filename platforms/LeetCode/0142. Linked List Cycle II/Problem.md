# 142. Linked List Cycle II

> Medium

Given the `head` of a linked list, return *the node where the cycle begins*.  
If there is **no cycle**, return `null`.

### Example:

![linkedlistcycleii1](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

- Input: `head = [3,2,0,-4], pos = 1`  
- Output: *Reference to node with value* `2`

![linkedlistcycleii2](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

- Input: `head = [1,2], pos = 0`  
- Output: *Reference to node with value* `1`

![linkedlistcycleii3](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

- Input: `head = [1], pos = -1`  
- Output: `null`

### Constraints:
- `0 <= n <= 10⁴`
- `-10⁵ <= Node.val <= 10⁵`
- `pos` is `-1` or a **valid index** in the linked list
