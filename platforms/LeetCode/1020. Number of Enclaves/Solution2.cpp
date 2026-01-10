#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        queue<pair<int, int>> que;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                {
                    que.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int x = curr.first;
            int y = curr.second;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && grid[nx][ny] == 1)
                {
                    que.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
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