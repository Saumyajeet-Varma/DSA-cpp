#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        if (n == 1)
            return x;
        long long result = x;
        vector<long long> vec;
        for (long long i = 0; i < 64; i++)
        {
            if (!(((long long)x >> i) & (long long)1))
            {
                vec.push_back((long long)1 << i);
            }
        }
        long long num = n - 1;
        for (long long i = 0; i < 64; i++)
        {
            if ((num >> i) & (long long)1)
            {
                result += vec[i];
            }
        }
        return result;
    }
};