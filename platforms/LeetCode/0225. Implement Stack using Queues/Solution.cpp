#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> main;
    queue<int> temp;

    MyStack()
    {
        // we don't need it here
    }

    void push(int x)
    {
        while (!main.empty())
        {
            temp.push(main.front());
            main.pop();
        }
        main.push(x);
        while (!temp.empty())
        {
            main.push(temp.front());
            temp.pop();
        }
    }

    int pop()
    {
        int el = main.front();
        main.pop();
        return el;
    }

    int top()
    {
        return main.front();
    }

    bool empty()
    {
        return main.empty();
    }
};
