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
    bool checkBST(TreeNode *node, long minn, long maxx)
    {
        if (!node)
            return true;
        if (node->val <= minn || node->val >= maxx)
            return false;
        return checkBST(node->left, minn, node->val) && checkBST(node->right, node->val, maxx);
    }

    bool isValidBST(TreeNode *root)
    {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};