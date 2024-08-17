#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int numsSum = 0;
        int nSum = (n * (n + 1)) / 2;
        for (int i = 0; i < n; i++)
        {
            numsSum += nums[i];
        }
        return nSum - numsSum;
    }
};