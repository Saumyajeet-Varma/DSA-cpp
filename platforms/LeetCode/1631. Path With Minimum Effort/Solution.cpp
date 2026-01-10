#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int effort = topp.first;
            int x = topp.second.first;
            int y = topp.second.second;

            if (x == n - 1 && y == m - 1)
                return effort;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    int newEffort = max(abs(heights[nx][ny] - heights[x][y]), effort);

                    if (newEffort < dist[nx][ny])
                    {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};