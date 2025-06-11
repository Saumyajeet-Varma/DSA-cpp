#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int maxProfit = 0;
        int buy = prices[0];

        for (int i = 1; i < n; i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else if (maxProfit < prices[i] - buy)
            {
                maxProfit = prices[i] - buy;
            }
        }

        return maxProfit;
    }
};
