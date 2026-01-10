#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        int validSplits = 0;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        long long sum = prefix[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            if (prefix[i] >= sum - prefix[i])
                validSplits++;
        }
        return validSplits;
    }
};