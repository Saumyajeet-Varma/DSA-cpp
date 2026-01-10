#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();

        int minn = 0;
        int maxx = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                minn++;
                maxx++;
            }
            else if (s[i] == ')')
            {
                minn--;
                maxx--;
            }
            else
            {
                minn--;
                maxx++;
            }

            if (minn < 0)
                minn = 0;

            if (maxx < 0)
                return false;
        }

        return minn == 0;
    }
};