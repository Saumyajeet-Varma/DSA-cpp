#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    bool subsetWithSum(int i, int target, vector<int> &nums)
    {
        if (target == 0)
            return true;

        if (i == 0)
            return nums[0] == target;

        bool take = nums[i] <= target ? subsetWithSum(i - 1, target - nums[i], nums) : false;
        bool notTake = subsetWithSum(i - 1, target, nums);

        return take || notTake;
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

        return subsetWithSum(n - 1, sum / 2, nums);
    }
};