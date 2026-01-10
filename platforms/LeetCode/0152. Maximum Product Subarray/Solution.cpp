#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        double max = INT_MIN;
        double prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod *= nums[i];
            if (prod > max)
                max = prod;
            if (prod == 0)
                prod = 1;
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prod *= nums[i];
            if (prod > max)
                max = prod;
            if (prod == 0)
                prod = 1;
        }
        return (int)max;
    }
};