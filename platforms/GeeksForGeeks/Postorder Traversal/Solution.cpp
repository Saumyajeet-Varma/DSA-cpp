#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
private:
    void traverse(Node *node, vector<int> &result)
    {
        if (!node)
            return;

        traverse(node->left, result);
        traverse(node->right, result);
        result.push_back(node->data);
    }

public:
    vector<int> postOrder(Node *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};