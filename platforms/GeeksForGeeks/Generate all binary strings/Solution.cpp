#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(int n, string str, vector<string> &result)
    {
        if (str.length() == n)
        {
            result.push_back(str);
            return;
        }

        backtrack(n, str + '0', result);

        if (str[str.length() - 1] != '1' || str == "")
            backtrack(n, str + '1', result);
    }

public:
    vector<string> generateBinaryStrings(int num)
    {
        vector<string> result;
        string binStr;
        backtrack(num, binStr, result);
        return result;
    }
};