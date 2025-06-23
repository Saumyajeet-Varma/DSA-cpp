#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        int m = board.size();
        int n = board[0].size();

        vis[x][y] = 1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && board[nx][ny] == 'O')
                dfs(nx, ny, board, vis);
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
                dfs(i, 0, board, vis);

            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board, vis);
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                dfs(0, i, board, vis);

            if (board[m - 1][i] == 'O')
                dfs(m - 1, i, board, vis);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};