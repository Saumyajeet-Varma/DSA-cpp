#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
            return grid[i][j];

        if (i < 0 || j < 0)
            return INT_MAX;

        int up = recfunc(i - 1, j, grid);
        int left = recfunc(i, j - 1, grid);

        return grid[i][j] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return recfunc(m - 1, n - 1, grid);
    }
};