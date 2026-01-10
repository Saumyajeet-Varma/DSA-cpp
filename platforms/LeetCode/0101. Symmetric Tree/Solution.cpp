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
    bool checkSymmetry(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (!leftNode && !rightNode)
            return true;
        if (!leftNode || !rightNode)
            return false;
        if (leftNode->val == rightNode->val && checkSymmetry(leftNode->left, rightNode->right) && checkSymmetry(leftNode->right, rightNode->left))
            return true;
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return checkSymmetry(root->left, root->right);
    }
};