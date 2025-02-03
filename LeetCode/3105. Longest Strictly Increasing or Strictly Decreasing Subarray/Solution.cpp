#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0 || n == 1)
            return n;

        int maxLen = 1;
        int inc = 1;
        int dec = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                inc += 1;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                inc = 1;
                dec += 1;
            }
            else
            {
                inc = 1;
                dec = 1;
            }

            maxLen = max(maxLen, max(inc, dec));
        }

        return maxLen;
    }
};