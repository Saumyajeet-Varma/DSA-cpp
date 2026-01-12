# 127. Word Ladder

> Hard

A **transformation sequence** from word `beginWord` to word `endWord` is a sequence of words where:  
- Each adjacent pair of words **differs by exactly one character**, and  
- Every word in the sequence (except `beginWord`) must exist in the list `wordList`.

Given two strings `beginWord` and `endWord`, and a string array `wordList`, return *the number of words in the shortest transformation sequence from `beginWord` to `endWord`*.  
If no such sequence exists, return `0`.

### Example:
- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]`  
- Output: `5`  
- Explanation: One shortest transformation is `"hit" → "hot" → "dot" → "dog" → "cog"`.

- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]`  
- Output: `0`  
- Explanation: `endWord` is not in `wordList`, so no possible transformation.

### Constraints:
- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters
- `beginWord != endWord`
- All the words in `wordList` are unique

