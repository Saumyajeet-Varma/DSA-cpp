#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        if (all_of(nums.begin(), nums.end(), [](int x)
                   { return x == 0; }))
            return 0;

        int n = nums.size();
        int q = queries.size();

        int result = -1;

        int left = 0;
        int right = q - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            vector<int> prefix(n + 1, 0);

            for (int i = 0; i <= mid; i++)
            {
                prefix[queries[i][0]] += queries[i][2];
                prefix[queries[i][1] + 1] -= queries[i][2];
            }

            for (int i = 1; i < n; i++)
            {
                prefix[i] += prefix[i - 1];
            }

            bool canZero = true;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] > prefix[i])
                {
                    canZero = false;
                    break;
                }
            }

            if (canZero)
            {
                result = mid + 1;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};