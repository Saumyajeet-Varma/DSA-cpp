#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(vector<string> &board, int n, int row, int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(int n, int row, vector<string> &board, vector<vector<string>> &result)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, n, row, col))
            {
                board[row][col] = 'Q';
                backtrack(n, row + 1, board, result);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        backtrack(n, 0, board, result);

        return result;
    }
};