#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0, maxlen = 0;
        unordered_set<char> st;
        while (r < s.length())
        {
            while (st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};