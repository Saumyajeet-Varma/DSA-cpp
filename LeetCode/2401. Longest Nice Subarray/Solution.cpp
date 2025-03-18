#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int maxLen = 1;
        int mask = nums[0];

        int l = 0;
        int r = 1;

        while (r < n)
        {
            while ((mask & nums[r]) != 0)
            {
                mask ^= nums[l];
                l++;
            }

            mask |= nums[r];
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};