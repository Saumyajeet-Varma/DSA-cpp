#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num || board[i][col] == num)
                return false;

            int sqRow = 3 * (row / 3) + i / 3;
            int sqCol = 3 * (col / 3) + i % 3;

            if (board[sqRow][sqCol] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (isValid(board, i, j, num))
                        {
                            board[i][j] = num;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};