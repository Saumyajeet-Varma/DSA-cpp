#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> result;
        set<vector<int>> uniqueResults;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    uniqueResults.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        for (auto it : uniqueResults)
        {
            result.push_back(it);
        }

        return result;
    }
};
