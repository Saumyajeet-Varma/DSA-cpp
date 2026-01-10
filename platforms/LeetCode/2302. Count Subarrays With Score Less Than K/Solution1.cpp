#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();

        long long count = 0;
        long long sum = 0;

        long long left = 0;
        long long right = 0;

        while (right < n)
        {
            sum += nums[right];

            while (sum * (right - left + 1) >= k)
            {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;

            right++;
        }

        return count;
    }
};