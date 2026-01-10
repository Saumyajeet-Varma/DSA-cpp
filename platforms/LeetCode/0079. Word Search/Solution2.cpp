#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool searchNext(vector<vector<char>> &board, int row, int col, string word, int idx)
    {
        if (idx == word.size())
            return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx] || board[row][col] == '$')
            return false;

        char ch = board[row][col];
        board[row][col] = '$';

        bool found = searchNext(board, row - 1, col, word, idx + 1) || searchNext(board, row + 1, col, word, idx + 1) || searchNext(board, row, col - 1, word, idx + 1) || searchNext(board, row, col + 1, word, idx + 1);

        board[row][col] = ch;

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (searchNext(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};