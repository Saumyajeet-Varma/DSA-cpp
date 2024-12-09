#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0))
                prefix[i]++;
        }
        vector<bool> result;
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int count = prefix[end] - (start > 0 ? prefix[start] : 0);
            result.push_back(count == 0);
        }
        return result;
    }
};