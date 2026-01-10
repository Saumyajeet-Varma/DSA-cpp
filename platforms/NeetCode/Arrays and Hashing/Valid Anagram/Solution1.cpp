#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> chars;

        for (char c : s)
        {
            chars[c]++;
        }

        for (char c : t)
        {
            if (!chars[c])
            {
                return false;
            }

            chars[c]--;
        }

        for (auto it : chars)
        {
            if (it.second)
            {
                return false;
            }
        }

        return true;
    }
};
