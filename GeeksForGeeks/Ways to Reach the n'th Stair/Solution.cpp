#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n)
    {
        if (n == 1 || n == 2)
            return n;

        int prevPrev = 1;
        int prev = 2;

        int curr;

        for (int i = 3; i <= n; i++)
        {
            curr = prev + prevPrev;
            prevPrev = prev;
            prev = curr;
        }

        return curr;
    }
};
