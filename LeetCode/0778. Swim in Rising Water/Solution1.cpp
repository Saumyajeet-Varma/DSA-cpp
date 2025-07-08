#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int elevate = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n - 1 && y == n - 1)
                return elevate;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    pq.push({max(elevate, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return 0;
    }
};