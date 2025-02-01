#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int bfs(vector<vector<pair<int, int>>> &gridMap, vector<vector<bool>> &vis, int i, int j, int num)
    {
        int n = gridMap.size();

        queue<pair<int, int>> que;
        vector<pair<int, int>> collect;

        que.push({i, j});

        while (!que.empty())
        {
            auto queFront = que.front();
            que.pop();

            int r = queFront.first;
            int c = queFront.second;

            if (vis[r][c])
                continue;

            vis[r][c] = true;
            collect.push_back({r, c});

            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : dirs)
            {
                int dr = dir.first;
                int dc = dir.second;

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && gridMap[nr][nc].first)
                    que.push({nr, nc});
            }
        }

        for (auto it : collect)
        {
            int r = it.first;
            int c = it.second;

            gridMap[r][c] = {collect.size(), num};
        }

        return collect.size();
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int largestIsland = 0;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<pair<int, int>>> islandMap(n, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                islandMap[i][j] = {grid[i][j], 0};
            }
        }

        int islandNum = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    largestIsland = max(largestIsland, bfs(islandMap, vis, i, j, islandNum));
                    islandNum++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    unordered_map<int, int> islandSizes;

                    if (i - 1 >= 0 && islandMap[i - 1][j].first)
                        islandSizes[islandMap[i - 1][j].second] = islandMap[i - 1][j].first;
                    if (i + 1 < n && islandMap[i + 1][j].first)
                        islandSizes[islandMap[i + 1][j].second] = islandMap[i + 1][j].first;
                    if (j - 1 >= 0 && islandMap[i][j - 1].first)
                        islandSizes[islandMap[i][j - 1].second] = islandMap[i][j - 1].first;
                    if (j + 1 < n && islandMap[i][j + 1].first)
                        islandSizes[islandMap[i][j + 1].second] = islandMap[i][j + 1].first;

                    int island = 1;
                    for (auto islandSize : islandSizes)
                    {
                        island += islandSize.second;
                    }

                    largestIsland = max(largestIsland, island);
                }
            }
        }

        return largestIsland;
    }
};