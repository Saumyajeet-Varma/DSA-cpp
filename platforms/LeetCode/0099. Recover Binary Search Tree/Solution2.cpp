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
    vector<int> inorder;
    int pointer;

    void inorderTraversal(TreeNode *node)
    {
        if (!node)
            return;
        inorderTraversal(node->left);
        inorder.push_back(node->val);
        inorderTraversal(node->right);
    }

    void inorderTraverse(TreeNode *node)
    {
        if (!node)
            return;
        inorderTraverse(node->left);
        if (node->val != inorder[pointer])
            node->val = inorder[pointer];
        pointer++;
        inorderTraverse(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorderTraversal(root);
        sort(inorder.begin(), inorder.end());
        pointer = 0;
        inorderTraverse(root);
    }
};