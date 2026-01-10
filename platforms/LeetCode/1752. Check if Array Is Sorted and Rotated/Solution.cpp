#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int rotateIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                rotateIndex++;
            }
        }
        if (nums[0] < nums[n - 1])
        {
            rotateIndex++;
        }
        if (rotateIndex <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};