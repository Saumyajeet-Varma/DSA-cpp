#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxSum = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for (auto num : accounts[i])
            {
                sum += num;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};