#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();

        int result = 0;

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int prod = nums[i] * nums[j];
                result += 8 * mpp[prod];
                mpp[prod]++;
            }
        }

        return result;
    }
};