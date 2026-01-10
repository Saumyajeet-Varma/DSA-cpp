#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                long long currTarget = (long long)target - nums[i] - nums[j];
                while (k < l)
                {
                    long long sum = nums[k] + nums[l];
                    if (sum > currTarget)
                    {
                        l--;
                    }
                    else if (sum < currTarget)
                    {
                        k++;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                        {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l - 1])
                        {
                            l--;
                        }
                        k++;
                        l--;
                    }
                }
            }
        }
        return result;
    }
};