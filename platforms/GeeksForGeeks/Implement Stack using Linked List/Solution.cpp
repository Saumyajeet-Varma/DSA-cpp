#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
            return -1;
        StackNode *delNode = top;
        int el = top->data;
        top = top->next;
        delete delNode;
        return el;
    }

    MyStack() { top = NULL; }
};