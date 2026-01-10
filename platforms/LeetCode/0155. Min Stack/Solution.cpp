#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> stk;
    stack<int> minstk;

    MinStack()
    {
        // we don't need it here
    }

    void push(int val)
    {
        stk.push(val);
        if (minstk.empty())
            minstk.push(val);
        else
            minstk.push(min(val, minstk.top()));
    }

    void pop()
    {
        stk.pop();
        minstk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minstk.top();
    }
};