#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mpp;
        while (r < nums.size())
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    // Main Function
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};