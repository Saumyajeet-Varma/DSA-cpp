#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0)
            return 0;

        int currFish = grid[row][col];
        grid[row][col] = 0;

        currFish += dfs(row + 1, col, grid);
        currFish += dfs(row - 1, col, grid);
        currFish += dfs(row, col + 1, grid);
        currFish += dfs(row, col - 1, grid);

        return currFish;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxFish = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] != 0)
                    maxFish = max(maxFish, dfs(i, j, grid));
            }
        }

        return maxFish;
    }
};