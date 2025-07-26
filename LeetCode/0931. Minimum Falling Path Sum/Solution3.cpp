#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int minn = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
                int up = dp[i - 1][j];
                int right = j < n - 1 ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({left, up, right});
            }
        }

        for (int i = 0; i < n; i++)
        {
            minn = min(minn, dp[n - 1][i]);
        }

        return minn;
    }
};