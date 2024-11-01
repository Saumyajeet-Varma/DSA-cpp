#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string result = "";
        int n = s.length();
        int count = 1;
        result.push_back(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (result.back() == s[i])
            {
                count++;
                if (count < 3)
                    result.push_back(s[i]);
            }
            else
            {
                count = 1;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};