#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();

        int sign = 1;
        int val = 0;

        int i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if (val > (INT_MAX - digit) / 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            val = (val * 10) + digit;
            i++;
        }

        return sign * val;
    }
};