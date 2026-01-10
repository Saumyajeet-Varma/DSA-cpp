#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();
            for (auto d : dir)
            {
                int x = topp.second.first + d.first;
                int y = topp.second.second + d.second;
                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                int time = -topp.first + 1;
                if (time < grid[x][y])
                    time = grid[x][y] + ((grid[x][y] - time) & 1);
                if (time < ans[x][y])
                {
                    ans[x][y] = time;
                    pq.push({-time, {x, y}});
                }
            }
        }
        return ans[m - 1][n - 1];
    }
};