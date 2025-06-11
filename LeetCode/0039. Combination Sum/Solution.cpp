#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> arr, int target, int i, vector<int> combination, vector<vector<int>> &result)
    {
        if (i == arr.size())
        {
            if (target == 0)
                result.push_back(combination);

            return;
        }

        if (arr[i] <= target)
        {
            combination.push_back(arr[i]);
            backtrack(arr, target - arr[i], i, combination, result);
            combination.pop_back();
        }

        backtrack(arr, target, i + 1, combination, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;

        backtrack(candidates, target, 0, combination, result);

        return result;
    }
};