#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int height(Node *node)
    {
        if (!node)
            return -1;

        int leftH = height(node->left);
        int rightH = height(node->right);

        return 1 + max(leftH, rightH);
    }
};