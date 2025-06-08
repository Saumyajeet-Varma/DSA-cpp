#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        int arrProd = 1;
        int count0 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                count0++;
            else
                arrProd *= nums[i];
        }

        if (count0 > 1)
        {
            vector<int> result(n, 0);
            return result;
        }

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                result.push_back(arrProd);
            else if (count0 > 0)
                result.push_back(0);
            else
                result.push_back(arrProd / nums[i]);
        }

        return result;
    }
};