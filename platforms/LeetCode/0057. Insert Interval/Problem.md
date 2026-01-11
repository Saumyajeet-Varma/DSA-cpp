# 57. Insert Interval

> Medium

You are given an array of **non-overlapping intervals** `intervals` where `intervals[i] = [startᵢ, endᵢ]` sorted by ascending `startᵢ`, and a **new interval** `newInterval = [start, end]`.  
Insert `newInterval` into `intervals` such that the result is still sorted and **non-overlapping** (merge if necessary).  
Return *the resulting array of intervals*.

### Example:
- Input: `intervals = [[1,3],[6,9]], newInterval = [2,5]`  
- Output: `[[1,5],[6,9]]`

- Input: `intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]`  
- Output: `[[1,2],[3,10],[12,16]]`

### Constraints:
- `0 <= intervals.length <= 10⁴`
- `intervals[i].length == 2`
- `0 <= startᵢ <= endᵢ <= 10⁵`
- `intervals` is sorted by `startᵢ` in ascending order
- `newInterval.length == 2`
- `0 <= start <= end <= 10⁵`

