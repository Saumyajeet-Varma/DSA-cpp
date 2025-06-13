#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areIsomorphic(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
            return false;

        int n = s1.length();

        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for (int i = 0; i < n; i++)
        {
            if (mpp1.find(s1[i]) == mpp1.end())
                mpp1[s1[i]] = i;

            if (mpp2.find(s2[i]) == mpp2.end())
                mpp2[s2[i]] = i;

            if (mpp1[s1[i]] != mpp2[s2[i]])
                return false;
        }

        return true;
    }
};