#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int maxx = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxx = max(maxx, nums[i]);
        }
        int ans = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxx)
            {
                count++;
                ans = max(ans, count);
            }
            else
            {
                count = 0;
            }
        }
        return ans;
    }
};