#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();

        long long count = 0;

        unordered_map<int, int> mpp;

        for (int i = 0, j = 0; i < n; i++)
        {
            k -= mpp[nums[i]]++;

            while (k <= 0)
            {
                mpp[nums[j]]--;
                k += mpp[nums[j]];
                j++;
            }

            count += j;
        }

        return count;
    }
};