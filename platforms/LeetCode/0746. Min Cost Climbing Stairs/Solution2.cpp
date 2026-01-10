#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int i, vector<int> &cost, vector<int> &dp)
    {
        if (i == 0 || i == 1)
            return cost[i];

        if (dp[i] != -1)
            return dp[i];

        int prev1 = recfunc(i - 1, cost, dp);
        int prev2 = recfunc(i - 2, cost, dp);

        return dp[i] = cost[i] + min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        if (n == 1)
            return cost[0];

        vector<int> dp(n, -1);

        return min(recfunc(n - 1, cost, dp), recfunc(n - 2, cost, dp));
    }
};