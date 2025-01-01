#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.length();
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones++;
        }
        int zeroes = 0, maxx = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                zeroes++;
            else
                ones--;
            maxx = max(maxx, zeroes + ones);
        }
        return maxx;
    }
};