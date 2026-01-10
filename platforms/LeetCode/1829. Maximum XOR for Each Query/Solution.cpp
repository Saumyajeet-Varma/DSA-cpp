#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        int xorr = nums[0];
        int maxXorr = pow(2, maximumBit) - 1;
        for (int i = 1; i < n; i++)
        {
            xorr ^= nums[i];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = xorr ^ maxXorr;
            xorr ^= nums[n - 1 - i];
        }
        return result;
    }
};