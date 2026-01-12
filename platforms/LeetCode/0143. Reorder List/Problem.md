# 143. Reorder List

> Medium

You are given the `head` of a singly linked list.  
Reorder the list to follow the pattern:  
`L₀ → Lₙ → L₁ → Lₙ₋₁ → L₂ → Lₙ₋₂ → …`

You may **not modify the values** in the list’s nodes — only the nodes themselves may be changed.

### Example:

![reorderlist1](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)

- Input: `head = [1,2,3,4]`  
- Output: `[1,4,2,3]`

![reorderlist2](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)

- Input: `head = [1,2,3,4,5]`  
- Output: `[1,5,2,4,3]`

### Constraints:
- The number of nodes in the list is in the range `0 <= sz <= 5 * 10⁴`
- `1 <= Node.val <= 1000`
