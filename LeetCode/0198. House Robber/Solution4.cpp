#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        int curr;
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            int notTake = prev1;

            if (i > 1)
                take += prev2;

            curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};