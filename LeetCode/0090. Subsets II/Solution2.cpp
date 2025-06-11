#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recursiveFunc(vector<int> nums, int start, vector<int> subset, vector<vector<int>> &result)
    {
        result.push_back(subset);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            recursiveFunc(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        recursiveFunc(nums, 0, subset, result);

        return result;
    }
};