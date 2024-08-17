#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int minsum = INT_MAX / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(minsum - target))
                {
                    minsum = sum;
                }
                if (sum > target)
                {
                    k--;
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    return sum;
                }
            }
        }
        return minsum;
    }
};