#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool recfunc(vector<int> &arr, int i, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (i == 0)
            return arr[0] == target;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = recfunc(arr, i - 1, target, dp);
        bool take = false;

        if (arr[i] <= target)
            take = recfunc(arr, i - 1, target - arr[i], dp);

        return dp[i][target] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return recfunc(arr, n - 1, sum, dp);
    }
};