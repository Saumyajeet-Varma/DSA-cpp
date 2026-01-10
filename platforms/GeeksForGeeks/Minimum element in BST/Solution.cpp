#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
public:
    int minValue(Node *root)
    {
        Node *node = root;
        while (node->left)
        {
            node = node->left;
        }
        return node->data;
    }
};