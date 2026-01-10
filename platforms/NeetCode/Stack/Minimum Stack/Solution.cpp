#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {}

    void push(int val)
    {
        stk.push(val);

        if (minStk.empty())
        {
            minStk.push(val);
        }
        else
        {
            int minVal = minStk.top();
            minStk.push(min(minVal, val));
        }
    }

    void pop()
    {
        stk.pop();
        minStk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};
