#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        while (!dq.empty())
        {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            for (auto d : dir)
            {
                int dx = d.first;
                int dy = d.second;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny])
                    {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0)
                            dq.push_front({nx, ny});
                        else
                            dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};