#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int low = 0, high = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pow(mid, n) == m)
                return mid;
            else if (pow(mid, n) > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};