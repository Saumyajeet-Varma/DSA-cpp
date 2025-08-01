#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int n = columnTitle.length();

        long long result = 0;
        long long multiplier = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int val = columnTitle[i] - 'A' + 1;
            result += val * multiplier;
            multiplier *= 26;
        }

        return (int)result;
    }
};