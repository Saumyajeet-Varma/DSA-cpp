#include <bits/stdc++.h>
using namespace std;

class CustomStack
{
public:
    int size;
    deque<int> dq;

    CustomStack(int maxSize)
    {
        size = maxSize;
    }

    void push(int x)
    {
        if (dq.size() < size)
            dq.push_back(x);
    }

    int pop()
    {
        int el = -1;
        if (dq.size())
        {
            el = dq.back();
            dq.pop_back();
        }
        return el;
    }

    void increment(int k, int val)
    {
        k = min(k, int(dq.size()));
        for (int i = 0; i < k; i++)
            dq[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */