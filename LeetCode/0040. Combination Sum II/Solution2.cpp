#include <bits/stdc++.h>
using namespace std;

// ! Memory Limit Exceed
class Solution
{
private:
    void backtrack(vector<int> arr, int target, int i, vector<int> combination, set<vector<int>> &result)
    {
        if (i == arr.size())
        {
            if (target == 0)
                result.insert(combination);

            return;
        }

        if (arr[i] <= target)
        {
            combination.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, combination, result);
            combination.pop_back();
        }

        backtrack(arr, target, i + 1, combination, result);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        set<vector<int>> resSet;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, combination, resSet);

        for (vector<int> resEl : resSet)
        {
            result.push_back(resEl);
        }

        return result;
    }
};