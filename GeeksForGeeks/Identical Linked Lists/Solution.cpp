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
    bool areIdentical(struct Node *head1, struct Node *head2)
    {
        if (!head1 && !head2)
            return true;
        if (head1->data != head2->data)
            return false;
        return areIdentical(head1->next, head2->next);
    }
};