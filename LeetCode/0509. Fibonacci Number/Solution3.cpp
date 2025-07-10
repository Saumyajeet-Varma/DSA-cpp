#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int fiboDP(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fiboDP(n - 1, dp) + fiboDP(n - 2, dp);
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fiboDP(n, dp);
    }
};