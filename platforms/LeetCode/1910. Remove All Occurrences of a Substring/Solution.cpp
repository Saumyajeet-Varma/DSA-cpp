#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int len = part.size();

        string result;

        for (char ch : s)
        {
            result.push_back(ch);

            if (result.size() >= len && result.substr(result.size() - len) == part)
                result.erase(result.size() - len, len);
        }

        return result;
    }
};