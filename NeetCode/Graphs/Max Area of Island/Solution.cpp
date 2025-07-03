#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1 || vis[x][y])
        {
            return 0;
        }

        vis[x][y] = 1;

        int area = 1;

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            area += dfs(nx, ny, vis, grid);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int area = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    area = max(area, dfs(i, j, vis, grid));
                }
            }
        }

        return area;
    }
};
