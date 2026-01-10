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

        for (int num : nums)
        {
            if (num == 0)
            {
                count0++;
            }
            else
            {
                arrProd *= num;
            }
        }

        if (count0 > 1)
        {
            vector<int> result(n, 0);
            return result;
        }

        vector<int> result;

        for (int num : nums)
        {
            if (num == 0)
            {
                result.push_back(arrProd);
            }
            else if (count0 > 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(arrProd / num);
            }
        }

        return result;
    }
};
