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
public:
    int isSumProperty(Node *root)
    {
        int sum = 0;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;
        if (root->data != sum && sum > 0)
            return 0;
        if (root->left)
            return isSumProperty(root->left);
        if (root->right)
            return isSumProperty(root->right);
        return 1;
    }
};