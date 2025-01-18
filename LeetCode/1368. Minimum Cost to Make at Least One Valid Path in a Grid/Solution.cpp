#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int cost = topp.first;
            int node = topp.second;
            int x = node / m;
            int y = node % m;

            if (cost > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int newCost = cost + (i != grid[x][y] - 1);
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx * m + ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};