#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int result = 0;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= high; i++)
        {
            if (dp[i] > 0)
            {
                if (i + zero <= high)
                    dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
                if (i + one <= high)
                    dp[i + one] = (dp[i + one] + dp[i]) % MOD;
            }
        }
        for (int i = low; i <= high; i++)
        {
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};