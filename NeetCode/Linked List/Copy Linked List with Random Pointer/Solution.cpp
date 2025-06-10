#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *mover = head;

        while (mover)
        {
            Node *newNode = new Node(mover->val);

            newNode->next = mover->next;
            mover->next = newNode;

            mover = mover->next->next;
        }

        mover = head;

        while (mover)
        {
            Node *copyNode = mover->next;

            if (mover->random)
            {
                copyNode->random = mover->random->next;
            }
            else
            {
                copyNode->random = nullptr;
            }

            mover = mover->next->next;
        }

        Node *dummyHead = new Node(0);
        Node *copyMover = dummyHead;
        mover = head;

        while (mover)
        {
            copyMover->next = mover->next;
            mover->next = mover->next->next;

            copyMover = copyMover->next;
            mover = mover->next;
        }

        return dummyHead->next;
    }
};
