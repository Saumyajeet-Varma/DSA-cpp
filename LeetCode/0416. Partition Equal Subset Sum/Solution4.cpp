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

        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        prev[0] = true;
        curr[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool take = nums[i] <= j ? prev[j - nums[i]] : false;
                bool notTake = prev[j];

                curr[j] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};