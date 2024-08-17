#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> mpp(256, -1);
        int l = 0, r = 0, maxlen = 0;
        while (r < n)
        {
            if (mpp[s[r]] != -1)
            {
                if (mpp[s[r]] >= l)
                {
                    l = mpp[s[r]] + 1;
                }
            }
            maxlen = max(maxlen, r - l + 1);
            mpp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};