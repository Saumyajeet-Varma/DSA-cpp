#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void increasePointer(vector<int> &bits, int num)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
                bits[i] += 1;
        }
    }

    void decreasePointer(vector<int> &bits, int num)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
                bits[i] -= 1;
        }
    }

    int orValue(vector<int> &bits)
    {
        int val = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] >= 1)
                val |= 1 << i;
        }
        return val;
    }

    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int minLen = INT_MAX;
        int n = nums.size();
        int l = 0, r = 0;
        vector<int> bits(32, 0);
        while (r < n)
        {
            increasePointer(bits, nums[r]);
            while (l <= r && orValue(bits) >= k)
            {
                minLen = min(minLen, r - l + 1);
                decreasePointer(bits, nums[l]);
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};