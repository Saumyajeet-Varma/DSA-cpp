#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        vector<string> strvec;
        unordered_map<string, int> mpp;
        for (int it : arr1)
        {
            string temp = to_string(it);
            int n = temp.length();
            string s;
            for (int i = 0; i < n; i++)
            {
                s.push_back(temp[i]);
                strvec.push_back(s);
            }
        }
        for (int it : arr2)
        {
            string temp = to_string(it);
            int n = temp.length();
            string s;
            for (int i = 0; i < n; i++)
            {
                s.push_back(temp[i]);
                mpp[s]++;
            }
        }
        sort(strvec.begin(), strvec.end(), [&](string &s1, string &s2)
             { return s1.length() > s2.length(); });

        int maxx = 0;
        for (int i = 0; i < strvec.size(); i++)
        {
            if (mpp.find(strvec[i]) != mpp.end())
            {
                maxx = max(maxx, (int)strvec[i].length());
                break;
            }
        }
        return maxx;
    }
};