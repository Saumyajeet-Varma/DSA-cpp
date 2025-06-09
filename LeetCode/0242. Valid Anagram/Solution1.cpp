#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> chars;

        for (char ch : s)
        {
            chars[ch]++;
        }

        for (char ch : t)
        {
            if (!chars[ch])
                return false;

            chars[ch]--;
        }

        for (auto it : chars)
        {
            if (it.second)
                return false;
        }

        return true;
    }
};