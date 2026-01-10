#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

    long long factMod(long long n)
    {
        long long result = 1;

        for (long long i = 1; i <= n; i++)
        {
            result = (result * i) % MOD;
        }

        return result;
    }

    long long modInv(long long x)
    {
        long long result = 1;
        long long power = MOD - 2;

        while (power > 0)
        {
            if (power % 2 == 1)
                result = (result * x) % MOD;

            x = (x * x) % MOD;
            power /= 2;
        }

        return result;
    }

    long long combMod(long long n, long long k)
    {
        if (k > n)
            return 0;

        long long num = factMod(n);
        long long denominator = (factMod(k) * factMod(n - k)) % MOD;

        return (num * modInv(denominator)) % MOD;
    }

public:
    int idealArrays(int n, int maxValue)
    {
        int result = 0;

        map<int, int> mpp;

        for (int i = 1; i <= maxValue; i++)
        {
            mpp[i] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            int count = 0;

            for (auto it : mpp)
            {
                count += it.second;
                count %= MOD;
            }

            result = (result + (combMod(n - 1, i - 1) * count) % MOD) % MOD;

            map<int, int> temp;

            for (auto it : mpp)
            {
                int x = it.first;
                int y = it.second;

                int t = x * 2;

                if (t > maxValue)
                    break;

                while (t <= maxValue)
                {
                    temp[t] += y;
                    t += x;
                }
            }

            if (temp.size() == 0)
                break;

            mpp = temp;
        }

        return result;
    }
};