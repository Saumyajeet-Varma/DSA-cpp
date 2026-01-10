#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> arr, int target, int curr, vector<int> combination, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        if (target < 0 || curr > arr.size())
        {
            return;
        }

        for (int i = curr; i < arr.size(); i++)
        {
            if (i > curr && arr[i] == arr[i - 1])
            {
                continue;
            }

            combination.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, combination, result);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> combination;
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, combination, result);

        return result;
    }
};
