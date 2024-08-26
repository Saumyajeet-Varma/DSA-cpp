#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    DLLNode *reverseDLL(DLLNode *head)
    {
        stack<int> stk;
        DLLNode *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->data = stk.top();
            stk.pop();
            temp = temp->next;
        }
        return head;
    }
};