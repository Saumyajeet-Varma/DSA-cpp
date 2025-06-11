#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> nums, int target, int i, vector<int> combination, vector<vector<int>> &result)
    {
        if (i == nums.size())
        {
            if (target == 0)
            {
                result.push_back(combination);
            }
            return;
        }

        if (nums[i] <= target)
        {
            combination.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, combination, result);
            combination.pop_back();
        }

        backtrack(nums, target, i + 1, combination, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> combination;
        vector<vector<int>> result;

        backtrack(nums, target, 0, combination, result);

        return result;
    }
};
