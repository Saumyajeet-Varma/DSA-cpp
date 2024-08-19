#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x)
    {
        long long ans = -1;
        long long low = 0, high = n - 1;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (v[mid] <= x)
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