#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        vector<vector<int>> mergedIntervals;

        if (n == 0)
            return mergedIntervals;

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for (auto interval : intervals)
        {
            if (interval[0] <= tempInterval[1])
            {
                tempInterval[1] = max(tempInterval[1], interval[1]);
            }
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = interval;
            }
        }

        mergedIntervals.push_back(tempInterval);

        return mergedIntervals;
    }
};