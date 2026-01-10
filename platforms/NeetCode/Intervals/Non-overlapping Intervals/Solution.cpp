#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        if (n == 0 || n == 1)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2)
             { return v1[1] < v2[1]; });

        int count = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (lastEnd <= intervals[i][0])
            {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;
    }
};
