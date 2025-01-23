#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowsVec(rows);
        vector<int> colsVec(cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rowsVec[i] += grid[i][j];
                colsVec[j] += grid[i][j];
            }
        }

        int result = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1 && (rowsVec[i] > 1 || colsVec[j] > 1))
                    result++;
            }
        }

        return result;
    }
};