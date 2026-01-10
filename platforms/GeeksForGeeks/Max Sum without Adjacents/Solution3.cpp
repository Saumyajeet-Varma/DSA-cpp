#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n, -1);

        dp[0] = arr[0];

        for (int i = 0; i < n; i++)
        {
            int take = arr[i];
            int notTake = dp[i - 1];

            if (i > 1)
                take += dp[i - 2];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};