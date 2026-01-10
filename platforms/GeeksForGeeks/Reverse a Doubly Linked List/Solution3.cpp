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
        queue<int> que;
        DLLNode *temp = head;
        while (temp->next != NULL)
        {
            que.push(temp->data);
            temp = temp->next;
        }
        que.push(temp->data);
        while (temp != NULL)
        {
            temp->data = que.front();
            que.pop();
            temp = temp->prev;
        }
        return head;
    }
};