#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return INT_MAX;

        if (i == 0 && j == 0)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = recfunc(i - 1, j, grid, dp);
        int left = recfunc(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return recfunc(m - 1, n - 1, grid, dp);
    }
};