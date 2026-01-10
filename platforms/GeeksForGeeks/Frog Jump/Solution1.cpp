#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recursion(int i, vector<int> &height, vector<int> &dp)
    {
        if (dp[i] != -1)
            return dp[i];

        int prev1 = recursion(i - 1, height, dp) + abs(height[i] - height[i - 1]);

        if (i == 1)
            return dp[i] = prev1;

        int prev2 = recursion(i - 2, height, dp) + abs(height[i] - height[i - 2]);

        return dp[i] = min(prev1, prev2);
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        return recursion(n - 1, height, dp);
    }
};