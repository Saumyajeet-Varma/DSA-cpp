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
    bool isCircular(Node *head)
    {
        if (!head)
            return true;
        Node *mover = head;
        while (mover)
        {
            mover = mover->next;
            if (mover == head)
            {
                return true;
            }
        }
        return false;
    }
};