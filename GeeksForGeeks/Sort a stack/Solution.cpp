#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void SortedStack ::sort()
{
    if (!s.empty())
    {
        int top1 = s.top();
        s.pop();

        sort();

        if (!s.empty() && top1 < s.top())
        {
            int top2 = s.top();
            s.pop();

            s.push(top1);
            sort();
            s.push(top2);
        }
        else
        {
            s.push(top1);
        }
    }
}