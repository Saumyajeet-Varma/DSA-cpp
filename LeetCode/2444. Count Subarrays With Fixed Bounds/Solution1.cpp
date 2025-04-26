#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();

        long long count = 0;
        long long start = -1;
        long long minn = -1;
        long long maxx = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                start = i;

            if (nums[i] == maxK)
                maxx = i;

            if (nums[i] == minK)
                minn = i;

            int valid = max(0LL, min(minn, maxx) - start);
            count += valid;
        }

        return count;
    }
};