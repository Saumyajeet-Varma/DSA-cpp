#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();

        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++)
        {
            int prev1 = dp[i - 1] + abs(height[i] - height[i - 1]);
            int prev2 = INT_MAX;

            if (i > 1)
                prev2 = dp[i - 2] + abs(height[i] - height[i - 2]);

            dp[i] = min(prev1, prev2);
        }

        return dp[n - 1];
    }
};