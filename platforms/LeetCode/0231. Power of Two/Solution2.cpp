#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        if (ceil(log2(n)) == floor(log2(n)))
            return true;
        else
            return false;
    }
};