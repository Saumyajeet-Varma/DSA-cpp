#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int rem = sum % p;
        if (rem == 0)
            return 0;
        unordered_map<int, int> prefixModIndex;
        prefixModIndex[0] = -1;
        long long prefixSum = 0;
        int minLength = n;
        for (int i = 0; i < n; i++)
        {
            prefixSum = (prefixSum + nums[i]) % p;
            int targetMod = (prefixSum - rem + p) % p;
            if (prefixModIndex.find(targetMod) != prefixModIndex.end())
                minLength = min(minLength, i - prefixModIndex[targetMod]);
            prefixModIndex[prefixSum] = i;
        }
        return minLength == n ? -1 : minLength;
    }
};