#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0))
                vec.push_back(i);
        }
        vector<bool> result;
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            bool flag = false;
            for (auto v : vec)
            {
                if (v >= end)
                {
                    result.push_back(true);
                    flag = true;
                    break;
                }
                if (v < end && v >= start)
                {
                    result.push_back(false);
                    flag = true;
                    break;
                }
            }
            if (!flag)
                result.push_back(true);
        }
        return result;
    }
};