#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int n = nums.size();

        int maxSum = 0;
        int minSum = 0;

        for (int i = 0; i < n; i++)
        {
            maxSum = max(0, maxSum + nums[i]);
            minSum = min(0, minSum + nums[i]);
        }

        return maxSum - minSum;
    }
};