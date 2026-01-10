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
    vector<int> depthSum;

    void dfs1(TreeNode *node, int depth)
    {
        if (node == NULL)
            return;

        if (depth >= depthSum.size())
            depthSum.push_back(node->val);
        else
            depthSum[depth] += node->val;

        dfs1(node->left, depth + 1);
        dfs1(node->right, depth + 1);
    }

    void dfs2(TreeNode *node, int value, int depth)
    {
        if (node == NULL)
            return;

        node->val = value;

        int nextDepth = depth + 1 < depthSum.size() ? depthSum[depth + 1] : 0;

        nextDepth -= (node->left != nullptr ? node->left->val : 0);
        nextDepth -= (node->right != nullptr ? node->right->val : 0);

        if (node->left)
            dfs2(node->left, nextDepth, depth + 1);
        if (node->right)
            dfs2(node->right, nextDepth, depth + 1);
    }

    TreeNode *replaceValueInTree(TreeNode *root)
    {
        dfs1(root, 0);
        dfs2(root, 0, 0);
        return root;
    }
};