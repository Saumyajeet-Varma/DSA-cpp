#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int n = s.length();

        unordered_map<char, int> chars;

        for (int i = 0; i < n; i++)
        {
            chars[s[i]]++;
            chars[t[i]]--;
        }

        for (auto it : chars)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};