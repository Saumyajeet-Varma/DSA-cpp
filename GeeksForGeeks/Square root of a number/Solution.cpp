#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        if (x == 0 || x == 1)
            return x;
        long long int ans = 1, low = 1, high = x / 2;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};