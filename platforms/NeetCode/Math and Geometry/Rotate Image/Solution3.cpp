#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> rotatedMatrix(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rotatedMatrix[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = rotatedMatrix;
    }
};
