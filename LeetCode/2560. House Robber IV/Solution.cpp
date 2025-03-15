#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canRob(vector<int> &nums, int mid, int k)
    {
        int n = nums.size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                count++;
                i++;
            }
        }

        return count >= k;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canRob(nums, mid, k))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};