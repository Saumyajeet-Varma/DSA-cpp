#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *LCA(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (p->val < node->val && q->val < node->val)
            return LCA(node->left, p, q);
        if (p->val > node->val && q->val > node->val)
            return LCA(node->right, p, q);
        return node;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return LCA(root, p, q);
    }
};