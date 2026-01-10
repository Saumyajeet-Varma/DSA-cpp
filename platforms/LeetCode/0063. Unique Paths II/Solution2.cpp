#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if (i == 0 && j == 0)
            return dp[0][0] = 1;

        if (grid[i][j] == 1)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = recfunc(i - 1, j, grid, dp);
        int left = recfunc(i, j - 1, grid, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return recfunc(m - 1, n - 1, obstacleGrid, dp);
    }
};