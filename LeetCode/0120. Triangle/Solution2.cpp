#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return dp[i][j] = triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = triangle[i][j] + recfunc(i + 1, j, n, triangle, dp);
        int right = triangle[i][j] + recfunc(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(left, right);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recfunc(0, 0, n, triangle, dp);
    }
};