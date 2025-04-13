#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        long long result = 1;

        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;

            exp /= 2;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long result = (power(5, even) * power(4, odd)) % MOD;

        return result;
    }
};