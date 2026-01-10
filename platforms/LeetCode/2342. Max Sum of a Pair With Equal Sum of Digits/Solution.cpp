#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, priority_queue<int>> mpp;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int sum = 0;

            while (num)
            {
                sum += num % 10;
                num /= 10;
            }

            mpp[sum].push(nums[i]);
        }

        int maxSum = -1;

        for (auto it : mpp)
        {
            if (it.second.size() > 1)
            {
                int sum = it.second.top();
                it.second.pop();
                sum += it.second.top();
                maxSum = max(sum, maxSum);
            }
        }

        return maxSum;
    }
};