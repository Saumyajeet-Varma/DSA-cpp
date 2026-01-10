#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++)
        {
            bool flag = true;
            for (int j = i; j < i + k; j++)
            {
                if (j > i && nums[j] - nums[j - 1] != 1)
                {
                    flag = false;
                    break;
                }
            }
            flag ? ans.push_back(nums[i + k - 1]) : ans.push_back(-1);
        }
        return ans;
    }
};