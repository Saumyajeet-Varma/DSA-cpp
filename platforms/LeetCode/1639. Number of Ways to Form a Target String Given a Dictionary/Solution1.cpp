#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int numWays(vector<string> &words, string target)
    {
        int n = target.length();
        int row = words[0].size();
        vector<vector<long long>> freq(26, vector<long long>(row));
        for (int col = 0; col < row; col++)
        {
            for (string &word : words)
            {
                freq[word[col] - 'a'][col]++;
            }
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(row + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= row; j++)
            {
                if (j < row)
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                if (i < n && j < row)
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target[i] - 'a'][j] * dp[i][j]) % MOD;
            }
        }
        return dp[n][row];
    }
};