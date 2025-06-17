#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int i, int j, vector<vector<int>> &maze, int n, string path, vector<vector<int>> &vis, vector<string> &result)
    {
        if (i == n - 1 && j == n - 1)
        {
            result.push_back(path);
            return;
        }

        if (i + 1 < n && maze[i + 1][j] == 1 && !vis[i + 1][j])
        {
            vis[i + 1][j] = 1;
            solve(i + 1, j, maze, n, path + 'D', vis, result);
            vis[i + 1][j] = 0;
        }

        if (j - 1 >= 0 && maze[i][j - 1] == 1 && !vis[i][j - 1])
        {
            vis[i][j - 1] = 1;
            solve(i, j - 1, maze, n, path + 'L', vis, result);
            vis[i][j - 1] = 0;
        }

        if (j + 1 < n && maze[i][j + 1] == 1 && !vis[i][j + 1])
        {
            vis[i][j + 1] = 1;
            solve(i, j + 1, maze, n, path + 'R', vis, result);
            vis[i][j + 1] = 0;
        }

        if (i - 1 >= 0 && maze[i - 1][j] == 1 && !vis[i - 1][j])
        {
            vis[i - 1][j] = 1;
            solve(i - 1, j, maze, n, path + 'U', vis, result);
            vis[i - 1][j] = 0;
        }
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<string> result;

        if (maze[0][0] == 0)
            return result;

        int n = maze.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        vis[0][0] = 1;

        solve(0, 0, maze, n, "", vis, result);

        return result;
    }
};