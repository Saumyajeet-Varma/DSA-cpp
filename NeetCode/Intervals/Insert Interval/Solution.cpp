#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();

        vector<vector<int>> result;

        int i = 0;

        while (i < n && newInterval[0] > intervals[i][1])
        {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        result.push_back(newInterval);

        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
