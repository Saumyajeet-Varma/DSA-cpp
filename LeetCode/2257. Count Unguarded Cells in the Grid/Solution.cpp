#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for (auto &el : guards)
        {
            grid[el[0]][el[1]] = 2;
        }
        for (auto &el : walls)
        {
            grid[el[0]][el[1]] = 2;
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (auto &el : guards)
        {
            for (int i = 0; i < 4; i++)
            {
                int x = el[0], y = el[1];
                int dx = dirs[i], dy = dirs[i + 1];
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] < 2)
                {
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans += count(grid[i], grid[i] + n, 0);
        }
        return ans;
    }
};