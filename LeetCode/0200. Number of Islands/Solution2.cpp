#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1' || vis[x][y])
            return;

        vis[x][y] = 1;

        dfs(x + 1, y, vis, grid);
        dfs(x - 1, y, vis, grid);
        dfs(x, y + 1, vis, grid);
        dfs(x, y - 1, vis, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, vis, grid);
                    result++;
                }
            }
        }

        return result;
    }
};