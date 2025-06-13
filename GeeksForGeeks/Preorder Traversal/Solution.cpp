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
    void traverse(Node *node, vector<int> &result)
    {
        if (!node)
            return;

        result.push_back(node->data);
        traverse(node->left, result);
        traverse(node->right, result);
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};