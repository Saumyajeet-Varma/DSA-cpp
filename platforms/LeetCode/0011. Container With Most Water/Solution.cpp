#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int water = 0, waterMax = 0;
        while (l < r)
        {
            if (height[l] > height[r])
            {
                water = height[r] * (r - l);
                waterMax = max(waterMax, water);
                r--;
            }
            else
            {
                water = height[l] * (r - l);
                waterMax = max(waterMax, water);
                l++;
            }
        }
        return waterMax;
    }
};