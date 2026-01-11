# 72. Edit Distance

> Medium

Given two strings `word1` and `word2`, return *the minimum number of operations* required to convert `word1` into `word2`.  
You have the following three operations permitted on a word:
- **Insert** a character,
- **Delete** a character,
- **Replace** a character.

### Example:
- Input: `word1 = "horse", word2 = "ros"`  
- Output: `3`  
- Explanation:  
  `horse → rorse (replace 'h' with 'r') → rose (remove 'r') → ros (remove 'e')`

- Input: `word1 = "intention", word2 = "execution"`  
- Output: `5`

### Constraints:
- `0 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of **lowercase English letters**
