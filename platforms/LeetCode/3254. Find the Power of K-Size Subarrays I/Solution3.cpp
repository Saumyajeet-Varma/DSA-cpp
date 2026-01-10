#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        vector<int> temp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == 1)
                temp[i] = temp[i - 1] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (temp[i] >= k)
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};