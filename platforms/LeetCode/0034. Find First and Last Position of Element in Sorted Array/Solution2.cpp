#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        vector<int> ans;
        int first = -1, last = -1;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};