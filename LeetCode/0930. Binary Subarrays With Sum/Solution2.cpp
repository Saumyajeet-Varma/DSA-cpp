#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int l = 0, r = 0, count = 0, sum = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    // Main function
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return countSubarrays(nums, goal) - countSubarrays(nums, goal - 1);
    }
};