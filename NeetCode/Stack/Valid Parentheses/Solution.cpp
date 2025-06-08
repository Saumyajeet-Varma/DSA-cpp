#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> stk;

        for (char ch : s)
        {
            if (ch == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    return false;
                }

                stk.pop();
            }
            else if (ch == '}')
            {
                if (stk.empty() || stk.top() != '{')
                {
                    return false;
                }

                stk.pop();
            }
            else if (ch == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    return false;
                }

                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }

        return stk.empty();
    }
};
