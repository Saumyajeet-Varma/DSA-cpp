#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> result;

        result.push_back({});

        for (int i = 0; i < n; i++)
        {
            int sz = result.size();

            for (int j = 0; j < sz; j++)
            {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }

        return result;
    }
};