# 21. Merge Two Sorted Lists

> Easy

You are given the heads of two sorted linked lists `list1` and `list2`.  
Merge the two lists in a **sorted** manner and return *the merged list’s head*.

### Example:

![mergetwosortedlists](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

- Input: `list1 = [1,2,4], list2 = [1,3,4]`  
- Output: `[1,1,2,3,4,4]`

- Input: `list1 = [], list2 = []`  
- Output: `[]`

- Input: `list1 = [], list2 = [0]`  
- Output: `[0]`

### Constraints:
- The number of nodes in both lists is in the range `0 <= sz <= 50`
- `-100 <= Node.val <= 100`
