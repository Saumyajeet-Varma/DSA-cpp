#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][m - 1] = 1;
        }

        for (int j = m - 2; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                int x = grid[i][j];
                int maxMove = (x < grid[i][j + 1]) * dp[i][j + 1];

                if (i > 0 && x < grid[i - 1][j + 1])
                    maxMove = max(maxMove, dp[i - 1][j + 1]);
                if (i < n - 1 && x < grid[i + 1][j + 1])
                    maxMove = max(maxMove, dp[i + 1][j + 1]);

                dp[i][j] = 1 + maxMove;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, dp[i][0]);
        }

        return result - 1;
    }
};