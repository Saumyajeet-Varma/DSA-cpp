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
    Node *deleteNode(Node *head, int x)
    {
        if (head == NULL)
            return head;
        if (x == 1)
        {
            head = head->next;
            return head;
        }
        int count = 2;
        Node *mover = head;
        while (count < x)
        {
            mover = mover->next;
            count++;
        }
        mover->next = mover->next->next;
        return head;
    }
};