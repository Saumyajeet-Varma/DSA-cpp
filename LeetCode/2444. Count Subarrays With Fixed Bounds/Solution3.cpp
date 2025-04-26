#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();

        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            int minn = INT_MAX;
            int maxx = INT_MIN;

            for (int j = i; j < n; j++)
            {
                minn = min(minn, nums[j]);
                maxx = max(maxx, nums[j]);

                if (minn == minK && maxx == maxK)
                    count++;
            }
        }

        return count;
    }
};