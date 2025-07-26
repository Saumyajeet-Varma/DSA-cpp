#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool subsetWithSum(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (i == 0)
            return nums[0] == target;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool take = nums[i] <= target ? subsetWithSum(i - 1, target - nums[i], nums, dp) : false;
        bool notTake = subsetWithSum(i - 1, target, nums, dp);

        return dp[i][target] = take || notTake;
    }

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

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        return subsetWithSum(n - 1, sum / 2, nums, dp);
    }
};