#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorr(int N)
    {
        if (N % 4 == 1)
            return 1;
        else if (N % 4 == 2)
            return N + 1;
        else if (N % 4 == 3)
            return 0;
        else
            return N;
    }

    int findXOR(int l, int r)
    {
        int L = xorr(l - 1);
        int R = xorr(r);
        return L ^ R;
    }
};