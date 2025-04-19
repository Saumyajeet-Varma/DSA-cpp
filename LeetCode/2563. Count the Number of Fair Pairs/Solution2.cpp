#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long countAtMost(vector<int> &nums, long long comp)
    {
        int n = nums.size();

        long long result = 0;

        int j = n - 1;
        for (int i = 0; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > comp)
            {
                j--;
            }

            result += j - i;
        }

        return result;
    }

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return countAtMost(nums, upper) - countAtMost(nums, lower - 1);
    }
};