#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        vector<int> prime(n + 1, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 3; i <= n; i++)
        {
            if (prime[i])
                count++;
        }
        return count;
    }
};