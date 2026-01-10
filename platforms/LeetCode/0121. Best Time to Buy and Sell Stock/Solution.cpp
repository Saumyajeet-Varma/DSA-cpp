#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        int buy = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else if (prices[i] - buy > max)
            {
                max = prices[i] - buy;
            }
        }
        return max;
    }
};