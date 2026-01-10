#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();

        int water = 0;

        int lmax = 0;
        int rmax = 0;

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            if (arr[l] < arr[r])
            {
                if (lmax > arr[l])
                    water += lmax - arr[l];
                else
                    lmax = arr[l];

                l++;
            }
            else
            {
                if (rmax > arr[r])
                    water += rmax - arr[r];
                else
                    rmax = arr[r];

                r--;
            }
        }

        return water;
    }
};