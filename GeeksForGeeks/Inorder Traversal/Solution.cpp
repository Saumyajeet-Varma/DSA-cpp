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
    void traverse(Node *node, vector<int> &result)
    {
        if (!node)
            return;

        traverse(node->left, result);
        result.push_back(node->data);
        traverse(node->right, result);
    }

public:
    vector<int> inOrder(Node *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};