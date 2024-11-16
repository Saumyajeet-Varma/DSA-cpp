#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int i = 0, j = 0;
        while (j < n)
        {
            if (j > 0 && nums[j] - nums[j - 1] != 1)
                i = j;
            while (i < j && j - i + 1 > k)
            {
                i++;
            }
            if (j - i + 1 == k)
                ans[j - k + 1] = nums[j];
            j++;
        }
        return ans;
    }
};