#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0, sum = 0, minlen = INT_MAX;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum >= target)
            {
                sum -= nums[l];
                minlen = min(minlen, r - l + 1);
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};