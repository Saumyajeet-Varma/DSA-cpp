#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> stk;
        for (char c : expression)
        {
            if (c != ')' && c != ',')
                stk.push(c);
            else if (c == ')')
            {
                vector<bool> exp;
                while (!stk.empty() && stk.top() != '(')
                {
                    char topp = stk.top();
                    stk.pop();
                    if (topp == 't')
                        exp.push_back(true);
                    else
                        exp.push_back(false);
                }
                stk.pop();
                if (!stk.empty())
                {
                    char topp = stk.top();
                    stk.pop();
                    bool v = exp[0];
                    if (topp == '&')
                    {
                        for (bool b : exp)
                        {
                            v &= b;
                        }
                    }
                    else if (topp == '|')
                    {
                        for (bool b : exp)
                        {
                            v |= b;
                        }
                    }
                    else
                        v = !v;

                    if (v)
                        stk.push('t');
                    else
                        stk.push('f');
                }
            }
        }
        return stk.top() == 't';
    }
};