#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int minn = INT_MAX;
        long long sum = 0;
        int negativeCount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] < 0)
                    negativeCount++;
                int absVal = abs(matrix[i][j]);
                minn = min(minn, absVal);
                sum += absVal;
            }
        }
        return negativeCount % 2 == 0 ? sum : sum - 2 * minn;
    }
};