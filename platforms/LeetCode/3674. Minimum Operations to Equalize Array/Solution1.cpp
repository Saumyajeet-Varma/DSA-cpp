#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        int andNum = nums[0];

        for (int i = 1; i < n; i++)
        {
            andNum &= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != andNum)
                return 1;
        }

        return 0;
    }
};