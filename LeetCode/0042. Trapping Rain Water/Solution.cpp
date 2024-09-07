#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int water = 0;
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (lmax > height[l])
                    water += lmax - height[l];
                else
                    lmax = height[l];
                l++;
            }
            else
            {
                if (rmax > height[r])
                    water += rmax - height[r];
                else
                    rmax = height[r];
                r--;
            }
        }
        return water;
    }
};