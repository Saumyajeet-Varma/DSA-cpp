#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestAbsent(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mpp[nums[i]]++;
        }

        int avg = sum / n;
        int num = avg + 1;

        while (true)
        {
            if (num > 0)
            {
                if (mpp.find(num) == mpp.end())
                {
                    return num;
                }
            }

            num++;
        }

        return 1;
    }
};