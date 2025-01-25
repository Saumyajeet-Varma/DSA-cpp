#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> val1, vector<int> val2)
             { return val1[1] < val2[1]; });

        int count = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastEnd)
            {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;
    }
};