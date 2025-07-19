#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxx = 0;

            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                    maxx = max(maxx, arr[0][i]);
            }

            return maxx;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxx = 0;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int points = arr[day][i] + recfunc(day - 1, i, arr, dp);
                maxx = max(maxx, points);
            }
        }

        return dp[day][last] = maxx;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return recfunc(n - 1, 3, arr, dp);
    }
};