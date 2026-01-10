#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();

        int idx = 0;
        vector<int> result(n);

        int i = 0;
        while (i < n - 1)
        {
            if (nums[i] != 0)
            {
                if (nums[i] == nums[i + 1])
                {
                    result[idx] = nums[i] * 2;
                    i++;
                }
                else
                {
                    result[idx] = nums[i];
                }
                idx++;
            }
            i++;
        }

        if (i != n)
            result[idx] = nums[n - 1];

        return result;
    }
};