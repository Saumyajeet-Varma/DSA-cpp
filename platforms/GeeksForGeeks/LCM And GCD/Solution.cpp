#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> lcmAndGcd(long long A, long long B)
    {
        long long a = A;
        long long b = B;
        long gcd = 1;
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
            if (a == 0)
            {
                gcd = b;
            }
            else
            {
                gcd = a;
            }
        }
        long lcm = (A * B) / gcd;
        return {lcm, gcd};
    }
};