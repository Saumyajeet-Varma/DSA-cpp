# 148. Sort List

> Medium

Given the `head` of a linked list, sort the list in **ascending order** and return *the sorted list’s head*.  
You must sort the list in **O(n log n)** time and use **constant extra space** (excluding recursion stack).

### Example:

![sortlist1](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)

- Input: `head = [4,2,1,3]`  
- Output: `[1,2,3,4]`

![sortlist2](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)

- Input: `head = [-1,5,3,4,0]`  
- Output: `[-1,0,3,4,5]`

- Input: `head = []`  
- Output: `[]`

### Constraints:
- The number of nodes in the list is in the range `0 <= sz <= 5 * 10⁴`
- `-10⁵ <= Node.val <= 10⁵`
