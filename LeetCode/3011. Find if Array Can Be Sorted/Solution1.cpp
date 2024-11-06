#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int prevMax = INT_MIN;
        int bits, maxx, minn;
        while (i < n)
        {
            bits = __builtin_popcount(nums[i]);
            maxx = INT_MIN;
            minn = INT_MAX;
            while (i < n && bits == __builtin_popcount(nums[i]))
            {
                maxx = max(maxx, nums[i]);
                minn = min(minn, nums[i]);
                i++;
            }
            if (prevMax > minn)
                return false;
            prevMax = maxx;
        }
        return true;
    }
};