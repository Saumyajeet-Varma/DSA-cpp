#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
private:
    bool areSame(Node *node1, Node *node2)
    {
        if (!node1 && !node2)
            return true;

        if (!node1 || !node2)
            return false;

        if (node1->data != node2->data)
            return false;

        return areSame(node1->left, node2->left) && areSame(node1->right, node2->right);
    }

public:
    bool isIdentical(Node *r1, Node *r2)
    {
        return areSame(r1, r2);
    }
};