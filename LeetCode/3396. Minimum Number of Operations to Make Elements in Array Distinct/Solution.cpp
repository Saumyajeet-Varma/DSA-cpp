#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (mpp.count(nums[i]) && mpp[nums[i]] >= 3 * result)
                result = (mpp[nums[i]] + 3) / 3;

            mpp[nums[i]] = i;
        }

        return result;
    }
};