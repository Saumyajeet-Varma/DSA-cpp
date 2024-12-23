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
    TreeNode *BST(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[i++]);
        node->left = BST(preorder, i, node->val);
        node->right = BST(preorder, i, bound);
        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        TreeNode *node = BST(preorder, i, INT_MAX);
        return node;
    }
};