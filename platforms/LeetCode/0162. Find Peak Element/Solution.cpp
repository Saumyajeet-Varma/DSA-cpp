#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans = -1;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                ans = i;
        }
        if (ans == -1)
        {
            if (nums[0] > nums[n - 1])
                ans = 0;
            else
                ans = n - 1;
        }
        return ans;
    }
};