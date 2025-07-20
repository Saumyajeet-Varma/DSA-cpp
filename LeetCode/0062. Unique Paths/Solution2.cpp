#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &dp)
    {
        int m = dp.size();
        int n = dp[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = recfunc(i - 1, j, dp);
        int left = recfunc(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;

        return recfunc(m - 1, n - 1, dp);
    }
};