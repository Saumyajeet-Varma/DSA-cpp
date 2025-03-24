#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceed
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int n = meetings.size();

        vector<bool> meetDays(days, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = meetings[i][0]; j <= meetings[i][1]; j++)
            {
                meetDays[j - 1] = true;
            }
        }

        int count = 0;

        for (int i = 0; i < days; i++)
        {
            if (!meetDays[i])
            {
                count++;
            }
        }

        return count;
    }
};