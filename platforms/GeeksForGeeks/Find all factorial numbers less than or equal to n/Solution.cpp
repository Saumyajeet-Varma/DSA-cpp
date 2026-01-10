#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> factorialNumbers(long long n)
    {
        vector<long long> ans;
        long long fact = 1;
        long long i = 1;
        while (fact <= n)
        {
            ans.push_back(fact);
            i++;
            fact *= i;
        }
        return ans;
    }
};