#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flattenTree(TreeNode *&node, TreeNode *&prev)
    {
        if (!node)
            return;
        flattenTree(node->right, prev);
        flattenTree(node->left, prev);
        node->left = NULL;
        node->right = prev;
        prev = node;
    }

    // MAIN FUNCTION
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *prev = NULL;
        flattenTree(root, prev);
    }
};