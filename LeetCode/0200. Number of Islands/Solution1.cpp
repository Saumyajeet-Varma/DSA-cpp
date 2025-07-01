#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid)
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

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1' && !vis[nx][ny])
                dfs(nx, ny, vis, grid);
        }
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