#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result(n, 0);

        for (int i = 0; i < n; i++)
        {
            result[i] = nums[nums[i]];
        }

        return result;
    }
};