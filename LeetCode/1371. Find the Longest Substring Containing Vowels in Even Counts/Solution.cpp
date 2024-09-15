#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.length();
        for (int i = n; i > 0; i--)
        {
            for (int j = 0; j <= n - i; j++)
            {
                string l = s.substr(j, i);
                bool odd = false;
                unordered_map<char, int> vowel;
                for (auto k : l)
                {
                    if (k == 'a' || k == 'e' || k == 'i' || k == 'o' ||
                        k == 'u')
                        vowel[k]++;
                }
                for (auto k : vowel)
                {
                    if (k.second % 2 != 0)
                    {
                        odd = true;
                        break;
                    }
                }
                if (!odd)
                    return i;
            }
        }
        return 0;
    }
};