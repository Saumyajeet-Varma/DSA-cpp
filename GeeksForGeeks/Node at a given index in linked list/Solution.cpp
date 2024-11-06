#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int GetNth(Node *head, int index)
    {
        if (index == 1)
            return head->data;
        int count = 1;
        Node *mover = head;
        while (mover && count < index)
        {
            mover = mover->next;
            count++;
        }
        if (mover)
            return mover->data;
        return -1;
    }
};