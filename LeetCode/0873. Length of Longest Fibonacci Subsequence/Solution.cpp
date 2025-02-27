#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();

        int maxLen = 0;

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 2; i < n; i++)
        {
            int l = 0;
            int r = i - 1;
            while (l < r)
            {
                int sum = arr[l] + arr[r];

                if (sum < arr[i])
                {
                    l++;
                }
                else if (sum > arr[i])
                {
                    r--;
                }
                else
                {
                    dp[r][i] = 1 + dp[l][r];
                    maxLen = max(maxLen, dp[r][i]);
                    l++;
                    r--;
                }
            }
        }

        return maxLen == 0 ? maxLen : maxLen + 2;
    }
};