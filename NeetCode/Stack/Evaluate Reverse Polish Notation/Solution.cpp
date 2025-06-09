#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isOperator(string s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            return true;
        }

        return false;
    }

    int solve(int a, int b, string op)
    {
        if (op == "+")
        {
            return a + b;
        }

        if (op == "-")
        {
            return a - b;
        }

        if (op == "*")
        {
            return a * b;
        }

        if (op == "/")
        {
            return a / b;
        }

        return -1;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (string token : tokens)
        {
            if (!isOperator(token))
            {
                int num = stoi(token);
                stk.push(num);
            }
            else
            {
                int num2 = stk.top();
                stk.pop();

                int num1 = stk.top();
                stk.pop();

                int res = solve(num1, num2, token);

                stk.push(res);
            }
        }

        return stk.top();
    }
};
