#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(string &str)
    {
        int n = str.size();
        stack<int> stk;
        stk.push(-1);
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    int len = i - stk.top();
                    maxx = max(maxx, len);
                }
            }
        }
        return maxx;
    }
};