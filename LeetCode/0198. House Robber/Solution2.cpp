#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + recfunc(idx - 2, nums, dp);
        int notTake = recfunc(idx - 1, nums, dp);

        return dp[idx] = max(take, notTake);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = nums[0];

        return recfunc(n - 1, nums, dp);
    }
};