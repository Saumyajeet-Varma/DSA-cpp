#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
            return false;

        int n = s1.length();

        unordered_map<char, int> chars;

        for (int i = 0; i < n; i++)
        {
            chars[s1[i]]++;
            chars[s2[i]]--;
        }

        for (auto it : chars)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};