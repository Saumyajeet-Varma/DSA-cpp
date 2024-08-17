#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int l = 0, r = 0, count = 0, odd = 0;
        while (r < nums.size())
        {
            if (nums[r] % 2 == 1)
                odd++;
            while (odd > k)
            {
                if (nums[l] % 2 == 1)
                    odd--;
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    // Main Function
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};
