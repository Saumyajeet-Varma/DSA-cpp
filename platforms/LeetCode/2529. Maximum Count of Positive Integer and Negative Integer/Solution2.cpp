#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();

        int firstPos = n;
        int firstNeg = n;

        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > 0)
            {
                firstPos = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        left = 0;
        right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= 0)
            {
                firstNeg = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return max(firstNeg, n - firstPos);
    }
};