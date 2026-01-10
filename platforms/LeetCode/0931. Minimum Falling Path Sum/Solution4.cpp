#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int minn = INT_MAX;

        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(n, -1);

            for (int j = 0; j < n; j++)
            {
                int left = j > 0 ? prev[j - 1] : INT_MAX;
                int up = prev[j];
                int right = j < n - 1 ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({left, up, right});
            }

            prev = curr;
        }

        for (int i = 0; i < n; i++)
        {
            minn = min(minn, prev[i]);
        }

        return minn;
    }
};