#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *l1, Node *l2)
    {
        Node *dummyNode = new Node(0);
        Node *temp = dummyNode;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->data < l2->data)
            {
                temp->bottom = l1;
                temp = l1;
                l1 = l1->bottom;
            }
            else
            {
                temp->bottom = l2;
                temp = l2;
                l2 = l2->bottom;
            }
            temp->next = nullptr;
        }
        if (l1)
            temp->bottom = l1;
        else
            temp->bottom = l2;
        return dummyNode->bottom;
    }

    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == nullptr)
            return root;
        Node *mergedHead = flatten(root->next);
        return merge(root, mergedHead);
    }
};