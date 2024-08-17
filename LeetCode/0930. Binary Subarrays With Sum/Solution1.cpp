#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == goal)
                    count++;
                else if (sum > goal)
                    break;
            }
        }
        return count;
    }
};