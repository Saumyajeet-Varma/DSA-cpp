#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int minn = nums[0];

        if (minn < k)
            return -1;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > k)
            {
                count++;

                while (i + 1 < n && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }
        }

        return count;
    }
};