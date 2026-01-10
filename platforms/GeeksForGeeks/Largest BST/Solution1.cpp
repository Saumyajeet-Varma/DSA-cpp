#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
private:
    bool isValidBST(Node *node, int minn, int maxx)
    {
        if (!node)
            return true;
        if (node->data <= minn || node->data >= maxx)
            return false;
        bool leftBST = isValidBST(node->left, minn, node->data);
        bool rightBST = isValidBST(node->right, node->data, maxx);
        return (leftBST && rightBST);
    }

    int countNodes(Node *node)
    {
        if (!node)
            return 0;
        return countNodes(node->left) + countNodes(node->right) + 1;
    }

public:
    int largestBst(Node *root)
    {
        queue<Node *> que;
        que.push(root);
        int maxNodes = 0;
        while (!que.empty())
        {
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                Node *node = que.front();
                que.pop();
                if (isValidBST(node, INT_MIN, INT_MAX))
                {
                    int nodes = countNodes(node);
                    maxNodes = max(maxNodes, nodes);
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return maxNodes;
    }
};