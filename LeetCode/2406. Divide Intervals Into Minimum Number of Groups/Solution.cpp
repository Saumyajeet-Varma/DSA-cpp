#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if (!pq.empty() && pq.top() < start)
                pq.pop();
            pq.push(end);
        }
        return pq.size();
    }
};