#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        if (n == 0 || m == 0 || n < m)
            return "";
        int l = 0, r = 0;
        int count = 0, minlen = INT_MAX, Sindex = -1;
        map<char, int> mpp;
        for (int i = 0; i < m; i++)
            mpp[t[i]]++;
        while (r < n)
        {
            if (mpp[s[r]] > 0)
                count++;
            mpp[s[r]]--;
            while (count == m)
            {
                if (r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    Sindex = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }
        return Sindex == -1 ? "" : s.substr(Sindex, minlen);
    }
};