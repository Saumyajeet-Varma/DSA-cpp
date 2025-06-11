#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> nums, int i, vector<int> subset, set<vector<int>> &resSet)
    {
        if (i == nums.size())
        {
            resSet.insert(subset);
            return;
        }

        backtrack(nums, i + 1, subset, resSet);
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, resSet);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> subset;
        set<vector<int>> resSet;

        sort(nums.begin(), nums.end());

        backtrack(nums, 0, subset, resSet);

        vector<vector<int>> result;

        for (vector<int> resEl : resSet)
        {
            result.push_back(resEl);
        }

        return result;
    }
};
