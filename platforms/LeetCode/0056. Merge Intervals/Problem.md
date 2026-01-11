# 56. Merge Intervals

> Medium

Given an array of **intervals** where `intervals[i] = [startᵢ, endᵢ]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

### Example:
- Input: `intervals = [[1,3],[2,6],[8,10],[15,18]]`  
- Output: `[[1,6],[8,10],[15,18]]`

- Input: `intervals = [[1,4],[4,5]]`  
- Output: `[[1,5]]`

### Constraints:
- `1 <= intervals.length <= 10⁴`
- `intervals[i].length == 2`
- `0 <= startᵢ <= endᵢ <= 10⁴`
