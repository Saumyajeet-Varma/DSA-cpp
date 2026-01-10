#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        if (j < 0 || j > n - 1)
            return INT_MAX;

        if (i == 0)
            return matrix[i][j];

        int left = recfunc(i - 1, j - 1, matrix);
        int up = recfunc(i - 1, j, matrix);
        int right = recfunc(i - 1, j + 1, matrix);

        return matrix[i][j] + min({left, up, right});
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int minn = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            minn = min(minn, recfunc(n - 1, n - i, matrix));
        }

        return minn;
    }
};