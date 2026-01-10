#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    void display(Node *head)
    {
        if (!head)
            return;
        Node *mover = head;
        while (mover)
        {
            cout << mover->data << " ";
            mover = mover->next;
        }
    }
};