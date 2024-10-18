#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backTrack(vector<int> &nums, int n, int index, int currOR, int maxOR, int &count)
    {
        if (currOR == maxOR)
            count++;
        for (int i = index; i < n; i++)
        {
            backTrack(nums, n, i + 1, currOR | nums[i], maxOR, count);
        }
    }

    // Main Function
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxOR = maxOR | nums[i];
        }
        int count = 0;
        backTrack(nums, n, 0, 0, maxOR, count);
        return count;
    }
};