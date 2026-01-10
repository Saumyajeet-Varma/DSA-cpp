#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        queue<pair<pair<int, int>, int>> que;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        que.push({{0, 0}, 1});
        vis[0][0] = 1;

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int len = curr.second;

            if (x == n - 1 && y == n - 1)
                return len;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && !vis[nx][ny])
                {
                    que.push({{nx, ny}, len + 1});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};