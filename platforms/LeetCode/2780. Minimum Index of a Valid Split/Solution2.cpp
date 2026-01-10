#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();

        int candidate = nums[0];
        int votes = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
                votes++;
            else
                votes--;

            if (votes == 0)
            {
                candidate = nums[i];
                votes = 1;
            }
        }

        int maxx = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
                maxx++;
        }

        votes = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
                votes++;

            if (votes * 2 > (i + 1) && (maxx - votes) * 2 > (n - i - 1))
                return i;
        }

        return -1;
    }
};