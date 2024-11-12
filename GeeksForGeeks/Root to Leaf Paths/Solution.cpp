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
    void findPath(Node *node, vector<int> &path, vector<vector<int>> &result)
    {
        if (!node)
            return;
        path.push_back(node->data);
        if (!node->left && !node->right)
            result.push_back(path);
        else
        {
            findPath(node->left, path, result);
            findPath(node->right, path, result);
        }
        path.pop_back();
    }

    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> result;
        vector<int> path;
        findPath(root, path, result);
        return result;
    }
};