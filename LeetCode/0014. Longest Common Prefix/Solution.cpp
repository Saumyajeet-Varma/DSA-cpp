#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = strs[0];
        for (string str : strs)
        {
            if (str == "")
                return "";
            while (str.find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
            }
        }
        return prefix;
    }
};