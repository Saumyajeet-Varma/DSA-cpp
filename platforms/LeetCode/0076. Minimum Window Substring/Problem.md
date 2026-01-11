# 76. Minimum Window Substring

> Hard

Given two strings `s` and `t`, return *the minimum window substring* of `s` such that **every character in `t` (including duplicates)** is included in the window.  
If there is **no such substring**, return an empty string `""`.  
If there are multiple valid windows of the same **minimum length**, you may return *any one* of them.

### Example:
- Input: `s = "ADOBECODEBANC", t = "ABC"`  
- Output: `"BANC"`

- Input: `s = "a", t = "a"`  
- Output: `"a"`

- Input: `s = "a", t = "aa"`  
- Output: `""`

### Constraints:
- `1 <= s.length, t.length <= 10⁵`
- `s` and `t` consist of **uppercase and lowercase English letters**
