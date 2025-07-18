#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            int notTake = dp[i - 1];

            if (i > 1)
                take += dp[i - 2];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};