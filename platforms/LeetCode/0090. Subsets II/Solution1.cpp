#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recursiveFunc(vector<int> nums, int i, vector<int> subset, set<vector<int>> &result)
    {
        if (i == nums.size())
        {
            result.insert(subset);
            return;
        }

        recursiveFunc(nums, i + 1, subset, result);
        subset.push_back(nums[i]);
        recursiveFunc(nums, i + 1, subset, result);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<vector<int>> resultSet;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        recursiveFunc(nums, 0, subset, resultSet);

        for (auto uniqueSubset : resultSet)
        {
            result.push_back(uniqueSubset);
        }

        return result;
    }
};