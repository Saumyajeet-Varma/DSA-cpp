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
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *node = que.front();
            que.pop();
            int leftData = 0, rightData = 0;
            if (node->left)
            {
                leftData = node->left->data;
                que.push(node->left);
            }
            if (node->right)
            {
                rightData = node->right->data;
                que.push(node->right);
            }
            if ((leftData || rightData) && (leftData + rightData != node->data))
                return 0;
        }
        return 1;
    }
};