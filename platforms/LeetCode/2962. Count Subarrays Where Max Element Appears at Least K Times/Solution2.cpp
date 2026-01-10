#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long maxx = *max_element(nums.begin(), nums.end());

        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            long long maxCount = 0;

            for (int j = i; j < n; j++)
            {
                if (nums[j] == maxx)
                    maxCount++;

                if (maxCount >= k)
                    count++;
            }
        }

        return count;
    }
};