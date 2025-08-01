#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, vector<int> &cost)
    {
        if (i == 0 || i == 1)
            return cost[i];

        int prev1 = recfunc(i - 1, cost);
        int prev2 = recfunc(i - 2, cost);

        return cost[i] + min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        if (n == 1)
            return cost[0];

        return min(recfunc(n - 1, cost), recfunc(n - 2, cost));
    }
};