#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        int left = 0, right = 0, maxx = 0;
        while (right < n)
        {
            while (right < n && nums[left] <= rightMax[right])
            {
                right++;
            }
            maxx = max(maxx, right - left - 1);
            left++;
            right = left + maxx + 1;
        }
        return maxx;
    }
};