#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.length();
        int m = spaces.size();
        string ans;
        int i = 0, j = 0;
        while (j < m)
        {
            if (i == spaces[j])
            {
                ans += ' ';
                j++;
            }
            ans += s[i];
            i++;
        }
        while (i < n)
        {
            ans += s[i];
            i++;
        }
        return ans;
    }
};