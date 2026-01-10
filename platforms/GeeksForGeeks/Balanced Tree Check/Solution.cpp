#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    int checkBalance(Node *node)
    {
        if (!node)
            return 0;

        int leftH = checkBalance(node->left);
        int rightH = checkBalance(node->right);

        if (leftH == -1 || rightH == -1)
            return -1;

        if (abs(leftH - rightH) > 1)
            return -1;

        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(Node *root)
    {
        return checkBalance(root) != -1;
    }
};