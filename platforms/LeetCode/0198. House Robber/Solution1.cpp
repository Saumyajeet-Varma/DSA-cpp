#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int idx, vector<int> &nums)
    {
        if (idx == 0)
            return nums[0];

        if (idx < 0)
            return 0;

        int take = nums[idx] + recfunc(idx - 2, nums);
        int notTake = recfunc(idx - 1, nums);

        return max(take, notTake);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return recfunc(n - 1, nums);
    }
};