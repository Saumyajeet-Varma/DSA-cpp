#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int max = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            nums[i] ? count++ : count = 0;
            if (count > max)
                max = count;
        }
        return max;
    }
};