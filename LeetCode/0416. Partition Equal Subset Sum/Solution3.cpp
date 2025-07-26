#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if (sum % 2 == 1)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool take = nums[i] <= j ? dp[i - 1][j - nums[i]] : false;
                bool notTake = dp[i - 1][j];

                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};