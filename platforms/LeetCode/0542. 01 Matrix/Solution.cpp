#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> que;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    que.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int dist = curr.second;

            result[x][y] = dist;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && vis[nx][ny] == 0)
                {
                    que.push({{nx, ny}, dist + 1});
                    vis[nx][ny] = 1;
                }
            }
        }

        return result;
    }
};