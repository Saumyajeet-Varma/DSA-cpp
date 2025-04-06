#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();

        int result = 0;

        for (int i = 0; i < (1 << n); i++)
        {
            int val = 0;

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    val ^= nums[j];
            }

            result += val;
        }

        return result;
    }
};