#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = len + i - 1;

                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return n - dp[0][n - 1];
    }
};