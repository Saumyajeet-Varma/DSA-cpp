#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isFeasible(int n, vector<int> &quantities, int item)
    {
        if (item == 0)
            return false;
        int store = 0;
        for (auto quantity : quantities)
        {
            store += (quantity - 1) / item + 1;
            if (store > n)
                return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isFeasible(n, quantities, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};