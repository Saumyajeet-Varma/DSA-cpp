#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;
        unordered_map<int, int> left;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        for (int i = 0; i < n - 1; i++)
        {
            left[nums[i]]++;
            mpp[nums[i]]--;

            if (left[nums[i]] * 2 > (i + 1) && mpp[nums[i]] * 2 > n - i - 1)
                return i;
        }

        return -1;
    }
};