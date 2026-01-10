# 20. Valid Parentheses

> Easy

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine **if the input string is valid**.

An input string is valid if:
- Open brackets are closed by the **same type** of brackets.
- Open brackets are closed in the **correct order**.

### Example:
- Input: `s = "()"`  
- Output: `true`

- Input: `s = "()[]{}"`  
- Output: `true`

- Input: `s = "(]"`  
- Output: `false`

### Constraints:
- `1 <= s.length <= 10⁴`
- `s` consists of the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'` only.
