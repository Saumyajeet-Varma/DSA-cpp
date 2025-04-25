#include <bits/stdc++.h>
using namespace std;

// Time limit exceeded
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();

        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            long long count = 0;

            for (int j = i; j < n; j++)
            {
                if (nums[j] % modulo == k)
                    count++;

                if (count % modulo == k)
                    result++;
            }
        }

        return result;
    }
};