#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recursion(int i, vector<int> &height)
    {
        if (i == 0)
            return 0;

        int prev1 = recursion(i - 1, height) + abs(height[i] - height[i - 1]);

        if (i == 1)
            return prev1;

        int prev2 = recursion(i - 2, height) + abs(height[i] - height[i - 2]);

        return min(prev1, prev2);
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        return recursion(n - 1, height);
    }
};