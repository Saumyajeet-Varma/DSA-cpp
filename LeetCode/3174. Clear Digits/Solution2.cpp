#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        string result;
        stack<char> stk;

        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9' && !stk.empty())
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }

        while (!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};