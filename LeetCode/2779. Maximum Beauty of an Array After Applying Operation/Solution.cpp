#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (nums[j] - nums[i] > 2 * k)
                i++;
            j++;
        }
        return j - i;
    }
};