#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> arr, int i, int sum, vector<int> &result)
    {
        if (i == arr.size())
        {
            result.push_back(sum);
            return;
        }

        backtrack(arr, i + 1, sum, result);
        backtrack(arr, i + 1, sum + arr[i], result);
    }

public:
    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> result;

        backtrack(arr, 0, 0, result);

        return result;
    }
};