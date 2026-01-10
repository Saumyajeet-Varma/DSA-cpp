#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;

                for (int i = 0; i < 3; i++)
                {
                    if (i != last)
                    {
                        int points = arr[day][i] + dp[day - 1][i];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};