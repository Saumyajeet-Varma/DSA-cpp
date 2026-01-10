#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int srcX = source.first;
        int srcY = source.second;
        int destX = destination.first;
        int destY = destination.second;

        if (grid[srcX][srcY] == 0 || grid[destX][destY] == 0)
            return -1;

        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        queue<pair<pair<int, int>, int>> que;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        que.push({{srcX, srcY}, 0});
        vis[srcX][srcY] = 1;

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int dist = curr.second;

            if (x == destX && y == destY)
                return dist;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !vis[nx][ny])
                {
                    que.push({{nx, ny}, dist + 1});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};
