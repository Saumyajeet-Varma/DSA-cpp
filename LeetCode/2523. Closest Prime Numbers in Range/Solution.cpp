#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> sieve(right + 1, true);
        vector<int> primes;
        vector<int> result = {-1, -1};

        sieve[0] = false;
        sieve[1] = false;
        int minGap = INT_MAX;

        for (int i = 2; i * i <= right; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= right; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        for (int i = left; i <= right; i++)
        {
            if (sieve[i])
            {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2)
        {
            return result;
        }

        for (int i = 1; i < primes.size(); i++)
        {
            int gap = primes[i] - primes[i - 1];

            if (gap < minGap)
            {
                minGap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};