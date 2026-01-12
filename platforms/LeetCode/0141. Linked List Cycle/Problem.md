# 141. Linked List Cycle

> Easy

Given the `head` of a linked list, return `true` if there is a **cycle** in the list.  
Otherwise, return `false`.

### Example:

![linkedlistcycle1](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

- Input: `head = [3,2,0,-4], pos = 1`  
- Output: `true`  
- Explanation: There is a cycle because the tail connects to the 1st node (0-indexed).

![linkedlistcycle2](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

- Input: `head = [1,2], pos = 0`  
- Output: `true`

![linkedlistcycle3](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

- Input: `head = [1], pos = -1`  
- Output: `false`

### Constraints:
- `0 <= n <= 10⁴`
- `-10⁵ <= Node.val <= 10⁵`
- `pos` is `-1` or a **valid index** in the linked list  
