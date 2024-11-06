#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int i1 = i;
            int bits = __builtin_popcount(nums[i]);
            while (i < n && bits == __builtin_popcount(nums[i]))
            {
                i++;
            }
            if (i <= n)
            {
                sort(nums.begin() + i1, nums.begin() + i);
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};