#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int n = nums.size();
        int left = 1;
        int right = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (right < nums[i])
                right = nums[i];
        }
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long long count = 0;
            for (int i = 0; i < n && count <= maxOperations; i++)
            {
                count += (nums[i] - 1) / mid;
            }
            if (count <= maxOperations)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};