#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();

        int posNums = 0;
        int negNums = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                posNums++;
            else if (nums[i] < 0)
                negNums++;
        }

        return max(posNums, negNums);
    }
};