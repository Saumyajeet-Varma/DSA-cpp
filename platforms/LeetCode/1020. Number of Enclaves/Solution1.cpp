#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        vis[x][y] = 1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && grid[nx][ny] == 1)
                dfs(nx, ny, grid, vis);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, vis);

            if (grid[i][n - 1] == 1)
                dfs(i, n - 1, grid, vis);
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid, vis);

            if (grid[m - 1][j] == 1)
                dfs(m - 1, j, grid, vis);
        }

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
    }
};