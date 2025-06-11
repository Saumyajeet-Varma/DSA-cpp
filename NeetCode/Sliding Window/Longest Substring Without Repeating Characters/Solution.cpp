#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();

        if (n == 0 || n == 1)
        {
            return n;
        }

        unordered_set<int> chars;

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < n)
        {
            while (chars.find(s[r]) != chars.end())
            {
                chars.erase(s[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            chars.insert(s[r]);
            r++;
        }

        return maxlen;
    }
};
