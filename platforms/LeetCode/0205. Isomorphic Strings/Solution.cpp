#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int n = s.length();

        unordered_map<char, int> sChars;
        unordered_map<char, int> tChars;

        for (int i = 0; i < n; i++)
        {
            if (sChars.find(s[i]) == sChars.end())
                sChars[s[i]] = i;

            if (tChars.find(t[i]) == tChars.end())
                tChars[t[i]] = i;

            if (sChars[s[i]] != tChars[t[i]])
                return false;
        }

        return true;
    }
};