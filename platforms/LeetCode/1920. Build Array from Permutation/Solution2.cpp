#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int changedVal = nums[nums[i]] % 1000;
            nums[i] = nums[i] + (1000 * changedVal);
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] /= 1000;
        }

        return nums;
    }
};