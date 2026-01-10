#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToInfix(string S)
    {
        int n = S.size();
        stack<string> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            char el = S[i];
            if ((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z') || (el >= '0' && el <= '9'))
            {
                stk.push(string(1, el));
            }
            else
            {
                string top1 = stk.top();
                stk.pop();
                string top2 = stk.top();
                stk.pop();
                stk.push("(" + top1 + el + top2 + ")");
            }
        }
        return stk.top();
    }
};