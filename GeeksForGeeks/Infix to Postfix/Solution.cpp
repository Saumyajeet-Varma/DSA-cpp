#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int priority(char op)
    {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return -1;
    }

    string infixToPostfix(string S)
    {
        int n = S.size();
        stack<char> stk;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            char el = S[i];
            if ((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z') || (el >= '0' && el <= '9'))
            {
                ans += el;
            }
            else if (el == '(')
            {
                stk.push(el);
            }
            else if (el == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    ans += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                while (!stk.empty() && (priority(el) <= priority(stk.top())))
                {
                    ans += stk.top();
                    stk.pop();
                }
                stk.push(el);
            }
        }
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};