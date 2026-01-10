#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;
        int requiredSum = (target + totalSum) / 2;
        vector<int> dp(requiredSum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int sum = requiredSum; sum >= num; sum--)
            {
                dp[sum] += dp[sum - num];
            }
        }
        return dp[requiredSum];
    }
};