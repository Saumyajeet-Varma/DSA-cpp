#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        string result;

        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9')
            {
                if (result.length())
                {
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(ch);
            }
        }

        return result;
    }
};