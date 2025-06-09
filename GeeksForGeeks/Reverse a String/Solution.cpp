#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseString(string &s)
    {
        int n = s.length();

        string str = "";

        for (int i = n - 1; i >= 0; i--)
        {
            str += s[i];
        }

        return str;
    }
};
