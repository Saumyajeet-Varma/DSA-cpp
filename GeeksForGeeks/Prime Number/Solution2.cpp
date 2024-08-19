#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrime(int N)
    {
        if (N == 1)
            return 0;
        int count = 0;
        int n = sqrt(N);
        for (int i = 2; i <= n; i++)
        {
            if (N % i == 0)
                return 0;
        }
        return 1;
    }
};