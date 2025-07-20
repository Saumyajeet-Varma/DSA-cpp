#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;

            prev[i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            vector<int> curr(n, 0);

            if (obstacleGrid[i][0] == 0)
                curr[0] = prev[0];

            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else
                    curr[j] = prev[j] + curr[j - 1];
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};
