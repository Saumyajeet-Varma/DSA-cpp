#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;

        for (int num : nums)
        {
            if (num < k)
                return -1;
            else if (num > k)
                mpp[num]++;
        }

        return mpp.size();
    }
};