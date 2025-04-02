#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();

        long long maxx = 0;
        long long diff = 0;
        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            result = max(result, diff * nums[i]);
            diff = max(diff, maxx - nums[i]);
            maxx = max(maxx, (long long)nums[i]);
        }

        return result;
    }
};