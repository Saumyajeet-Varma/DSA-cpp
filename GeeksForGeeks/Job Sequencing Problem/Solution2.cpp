#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed
class Solution
{
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
    {
        int n = id.size();

        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = id[i];
            jobs[i][1] = deadline[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end(), [](vector<int> val1, vector<int> val2)
             { return val1[2] > val2[2]; });

        int totalProfit = 0;
        int count = 0;
        int maxDeadline = 0;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, jobs[i][1]);
        }

        vector<int> daysArr(maxDeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i][1]; j >= 1; j--)
            {
                if (daysArr[j] == -1)
                {
                    count++;
                    daysArr[j] = jobs[i][0];
                    totalProfit += jobs[i][2];

                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};