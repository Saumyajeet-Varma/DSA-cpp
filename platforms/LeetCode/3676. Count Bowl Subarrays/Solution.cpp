#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long bowlSubarrays(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 3)
        {
            if (nums[0] > nums[1] && nums[1] < nums[2])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
            {
                stk.pop();
            }

            if (!stk.empty())
            {
                left[i] = stk.top();
            }

            stk.push(i);
        }

        while (!stk.empty())
        {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
            {
                stk.pop();
            }

            if (!stk.empty())
            {
                right[i] = stk.top();
            }

            stk.push(i);
        }

        long long result = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int l = left[i];
            int r = right[i];

            if (l != -1 && r != n)
                result++;
        }

        return result;
    }
};