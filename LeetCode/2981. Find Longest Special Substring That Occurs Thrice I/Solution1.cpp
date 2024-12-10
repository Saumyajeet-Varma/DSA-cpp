#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSpecialStr(string s)
    {
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[0])
                return false;
        }
        return true;
    }

    int maximumLength(string s)
    {
        int n = s.length();
        int maxLen = -1;
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                freq[s.substr(i, j - i + 1)]++;
            }
        }
        for (auto it : freq)
        {
            if (it.second >= 3 && isSpecialStr(it.first))
            {
                int len = it.first.length();
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};