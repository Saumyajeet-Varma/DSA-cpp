#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();

        int water = 0;
        int maxWater = 0;

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            if (heights[l] < heights[r])
            {
                water = heights[l] * (r - l);
                maxWater = max(maxWater, water);
                l++;
            }
            else
            {
                water = heights[r] * (r - l);
                maxWater = max(maxWater, water);
                r--;
            }
        }

        return maxWater;
    }
};
