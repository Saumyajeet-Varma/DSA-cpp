#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] >= target)
            return 0;
        if (nums[right] < target)
            return nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
            else
                return mid;
        }
        return left;
    }
};