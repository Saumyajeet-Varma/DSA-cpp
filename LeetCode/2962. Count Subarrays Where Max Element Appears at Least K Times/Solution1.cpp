#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long maxx = *max_element(nums.begin(), nums.end());

        long long count = 0;
        long long maxCount = 0;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            if (nums[right] == maxx)
                maxCount++;

            while (maxCount >= k)
            {
                if (nums[left] == maxx)
                    maxCount--;

                left++;
            }

            count += left;
            right++;
        }

        return count;
    }
};