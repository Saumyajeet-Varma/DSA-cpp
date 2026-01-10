#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
        }

        for (int i = 0; i < m; i++)
        {
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[n - 1][i], {n - 1, i}});
        }

        int ans = 0;
        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int height = topp.first;
            int row = topp.second.first;
            int col = topp.second.second;

            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol])
                {
                    ans += max(0, height - heightMap[newRow][newCol]);
                    pq.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
                    vis[newRow][newCol] = 1;
                }
            }
        }

        return ans;
    }
};