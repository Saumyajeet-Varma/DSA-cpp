#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }

                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                }
            }
        }

        if (fresh == 0)
        {
            return 0;
        }

        if (que.empty())
        {
            return -1;
        }

        int minutes = -1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!que.empty())
        {
            int q = que.size();

            while (q)
            {
                auto xy = que.front();
                que.pop();

                int x = xy.first;
                int y = xy.second;

                for (auto dir : dirs)
                {
                    int dx = dir.first;
                    int dy = dir.second;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && vis[nx][ny] == 1)
                    {
                        vis[nx][ny] = 2;
                        que.push({nx, ny});
                        fresh--;
                    }
                }

                q--;
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
