#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int n = matrix.size();

        if (j < 0 || j > n - 1)
            return INT_MAX;

        if (i == 0)
            return dp[i][j] = matrix[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = recfunc(i - 1, j - 1, matrix, dp);
        int up = recfunc(i - 1, j, matrix, dp);
        int right = recfunc(i - 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({left, up, right});
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int minn = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 1; i <= n; i++)
        {
            minn = min(minn, recfunc(n - 1, n - i, matrix, dp));
        }

        return minn;
    }
};