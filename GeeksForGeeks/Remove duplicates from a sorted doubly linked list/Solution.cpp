#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        if (head == NULL || head->next == nullptr)
            return head;
        Node *tail = head;
        Node *mover = head;
        while (mover != NULL)
        {
            if (tail->data != mover->data)
            {
                tail->next = mover;
                mover->prev = tail;
                tail = mover;
            }
            mover = mover->next;
        }
        tail->next = mover;
        return head;
    }
};