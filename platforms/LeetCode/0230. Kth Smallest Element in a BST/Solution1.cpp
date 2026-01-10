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
    void inorder(TreeNode *node, vector<int> &result)
    {
        if (!node)
            return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorderRes;
        inorder(root, inorderRes);
        return inorderRes[k - 1];
    }
};