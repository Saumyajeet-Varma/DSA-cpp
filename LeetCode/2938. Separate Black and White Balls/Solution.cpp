#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        int n = s.length();
        long long white = 0;
        long long step = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                step += white;
            else
                white++;
        }
        return step;
    }
};