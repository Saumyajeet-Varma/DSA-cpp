#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int inSequence(int a, int b, int c)
    {
        if (a == b && c == 0)
            return 1;

        if (a != b && c == 0)
            return 0;

        if (a == b && c != 0)
            return 0;

        if (a > b && c > 0)
            return 0;

        if (a < b && c < 0)
            return 0;

        if (a < b && c > 0)
            return (b - a) % c == 0 ? 1 : 0;

        if (a > b && c < 0)
            return (a - b) % abs(c) == 0 ? 1 : 0;

        return -1;
    }
};