#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vis[x][y] = 1;

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O' && !vis[nx][ny])
            {
                dfs(nx, ny, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        if (m <= 2 || n <= 2)
            return;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(i, 0, vis, board);
            }

            if (board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, vis, board);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(0, i, vis, board);
            }

            if (board[m - 1][i] == 'O')
            {
                dfs(m - 1, i, vis, board);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
