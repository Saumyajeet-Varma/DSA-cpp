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
    bool checkBST(TreeNode *node, TreeNode *minn, TreeNode *maxx)
    {
        if (!node)
            return true;
        if (minn && node->val <= minn->val)
            return false;
        if (maxx && node->val >= maxx->val)
            return false;
        return checkBST(node->left, minn, node) && checkBST(node->right, node, maxx);
    }

    bool isValidBST(TreeNode *root)
    {
        return checkBST(root, NULL, NULL);
    }
};