#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v1(n, 1);
        vector<int> v2(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    v1[i] = max(v1[i], 1 + v1[j]);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] > nums[j])
                    v2[i] = max(v2[i], 1 + v2[j]);
            }
        }
        int resultEl = 0;
        for (int i = 1; i < n; i++)
        {
            if (v1[i] != 1 && v2[i] != 1)
                resultEl = max(resultEl, v1[i] + v2[i]);
        }
        return n - resultEl + 1;
    }
};