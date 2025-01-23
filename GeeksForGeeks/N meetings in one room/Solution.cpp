#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();

        vector<vector<int>> meetTime(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            meetTime[i][0] = start[i];
            meetTime[i][1] = end[i];
        }

        sort(meetTime.begin(), meetTime.end(), [](vector<int> &val1, vector<int> &val2)
             { return val1[1] < val2[1]; });

        int count = 1;
        int freeTime = meetTime[0][1];

        for (int i = 1; i < n; i++)
        {
            if (meetTime[i][0] > freeTime)
            {
                count++;
                freeTime = meetTime[i][1];
            }
        }

        return count;
    }
};