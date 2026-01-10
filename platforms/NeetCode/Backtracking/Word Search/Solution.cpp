#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool searchNext(int row, int col, int idx, vector<vector<char>> &board, string &word)
    {
        if (idx == word.size())
        {
            return true;
        }

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#' || board[row][col] != word[idx])
        {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool found = searchNext(row - 1, col, idx + 1, board, word) || searchNext(row + 1, col, idx + 1, board, word) || searchNext(row, col - 1, idx + 1, board, word) || searchNext(row, col + 1, idx + 1, board, word);

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
                if (searchNext(i, j, 0, board, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
