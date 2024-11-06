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
    int intersectPoint(Node *head1, Node *head2)
    {
        unordered_map<Node *, int> mpp;
        Node *mover = head1;
        while (mover)
        {
            mpp[mover]++;
            mover = mover->next;
        }
        mover = head2;
        while (mover)
        {
            if (mpp[mover])
                return mover->data;
            mover = mover->next;
        }
        return -1;
    }
};