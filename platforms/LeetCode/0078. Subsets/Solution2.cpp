#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recursiveFunc(vector<int> &nums, int i, vector<int> subset, vector<vector<int>> &result)
    {
        if (i == nums.size())
        {
            result.push_back(subset);
            return;
        }

        recursiveFunc(nums, i + 1, subset, result);
        subset.push_back(nums[i]);
        recursiveFunc(nums, i + 1, subset, result);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;

        recursiveFunc(nums, 0, subset, result);

        return result;
    }
};