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
        if (head == NULL || head->next == NULL)
            return head;
        DLLNode *curr = head;
        DLLNode *back = NULL;
        while (curr != NULL)
        {
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;
            curr = curr->prev;
        }
        return back->prev;
    }
};