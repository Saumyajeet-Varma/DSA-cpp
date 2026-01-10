#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = coins.size();

        vector<int> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            while (N >= coins[i])
            {
                N -= coins[i];
                ans.push_back(coins[i]);
            }
        }

        return ans;
    }
};