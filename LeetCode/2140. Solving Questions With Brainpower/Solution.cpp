#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();

        vector<long long> dp(n, 0);

        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--)
        {
            long long solve = questions[i][0];

            if (i + questions[i][1] + 1 < n)
                solve += dp[i + questions[i][1] + 1];

            dp[i] = max(solve, dp[i + 1]);
        }

        return dp[0];
    }
};