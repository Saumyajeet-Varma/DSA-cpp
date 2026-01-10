#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();

        int srcColor = image[sr][sc];

        queue<pair<int, int>> que;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        que.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        while (!que.empty())
        {
            auto pixel = que.front();
            que.pop();

            int x = pixel.first;
            int y = pixel.second;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && image[nx][ny] == srcColor)
                {
                    image[nx][ny] = color;
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }

        return image;
    }
};