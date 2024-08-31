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
        Node *temp = head;
        while (temp)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        temp = head;
        while (temp)
        {
            Node *copyNode = temp->next;
            if (temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;
            temp = temp->next->next;
        }
        Node *dummyNode = new Node(0);
        Node *res = dummyNode;
        temp = head;
        while (temp)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};