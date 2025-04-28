#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();

        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (sum * (j - i + 1) < k)
                    count++;
            }
        }

        return count;
    }
};