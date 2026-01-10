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
private:
    bool validBST(TreeNode *node, TreeNode *minn, TreeNode *maxx)
    {
        if (!node)
        {
            return true;
        }

        if (minn && minn->val >= node->val)
        {
            return false;
        }

        if (maxx && maxx->val <= node->val)
        {
            return false;
        }

        return validBST(node->left, minn, node) && validBST(node->right, node, maxx);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validBST(root, NULL, NULL);
    }
};
