#include <bits/stdc++.h>
using namespace std;

// ! Memory Limit Exceed
class Solution
{
private:
    bool searchNext(vector<vector<char>> board, string word, int row, int col, int idx, int m, int n)
    {
        if (idx == word.length())
            return true;

        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[idx] || board[row][col] == '$')
            return false;

        char ch = board[row][col];
        board[row][col] = '$';

        bool top = searchNext(board, word, row - 1, col, idx + 1, m, n);
        bool bottom = searchNext(board, word, row + 1, col, idx + 1, m, n);
        bool left = searchNext(board, word, row, col - 1, idx + 1, m, n);
        bool right = searchNext(board, word, row, col + 1, idx + 1, m, n);

        board[row][col] = ch;

        return top || bottom || left || right;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        int idx = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[idx] && searchNext(board, word, i, j, idx, m, n))
                    return true;
            }
        }

        return false;
    }
};