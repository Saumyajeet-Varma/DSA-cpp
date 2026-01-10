#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        if (n == 0 || n == 1)
        {
            return intervals;
        }

        vector<vector<int>> mergedIntervals;

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        for (vector<int> interval : intervals)
        {
            if (interval[0] <= curr[1])
            {
                curr[1] = max(curr[1], interval[1]);
            }
            else
            {
                mergedIntervals.push_back(curr);
                curr = interval;
            }
        }

        mergedIntervals.push_back(curr);

        return mergedIntervals;
    }
};
