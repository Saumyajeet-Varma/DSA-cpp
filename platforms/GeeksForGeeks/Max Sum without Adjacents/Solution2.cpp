#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int idx, vector<int> &arr, vector<int> &dp)
    {
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int take = arr[idx] + recfunc(idx - 2, arr, dp);
        int notTake = recfunc(idx - 1, arr, dp);

        return dp[idx] = max(take, notTake);
    }

public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n, -1);
        dp[0] = arr[0];

        return recfunc(n - 1, arr, dp);
    }
};