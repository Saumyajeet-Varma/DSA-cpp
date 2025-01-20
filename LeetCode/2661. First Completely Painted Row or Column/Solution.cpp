#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = arr.size();
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> rowCount(rows, cols);
        vector<int> colCount(cols, rows);
        unordered_map<int, pair<int, int>> position;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                position[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < n; i++)
        {
            auto it = position[arr[i]];
            int row = it.first;
            int col = it.second;
            if (--rowCount[row] == 0 || --colCount[col] == 0)
                return i;
        }

        return -1;
    }
};