#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long n = nums.size();

        long long goodPairs = 0;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }

        return ((n * (n - 1)) / 2) - goodPairs;
    }
};