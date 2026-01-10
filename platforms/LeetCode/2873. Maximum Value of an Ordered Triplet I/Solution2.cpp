#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();

        vector<long long> suffix(n, 0);

        long long maxx = 0;
        long long result = 0;

        for (int i = n - 1; i >= 2; i--)
        {
            maxx = max(maxx, (long long)nums[i]);
            suffix[i - 1] = maxx;
        }

        maxx = nums[0];

        for (int i = 1; i < n - 1; i++)
        {
            long long tripletVal = (maxx - nums[i]) * suffix[i];
            result = max(result, tripletVal);
            maxx = max(maxx, (long long)nums[i]);
        }

        return result;
    }
};