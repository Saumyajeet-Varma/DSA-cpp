#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp[nums[i]] == 1)
                return nums[i];
            mpp[nums[i]]++;
        }
        return -1;
    }
};