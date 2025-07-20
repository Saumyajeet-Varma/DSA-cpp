#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (grid[i][j] == 1)
            return 0;

        int up = recfunc(i - 1, j, grid);
        int left = recfunc(i, j - 1, grid);

        return up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        return recfunc(m - 1, n - 1, obstacleGrid);
    }
};