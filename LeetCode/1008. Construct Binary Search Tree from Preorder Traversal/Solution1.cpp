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
    TreeNode *BST(vector<int> &preorder, int preStart, int preEnd)
    {
        TreeNode *node = new TreeNode(preorder[preStart]);
        int i = preStart + 1;
        while (i <= preEnd)
        {
            if (node->val < preorder[i])
                break;
            i++;
        }
        if (i <= preEnd)
        {
            node->right = BST(preorder, i, preEnd);
            node->left = i == preStart + 1 ? nullptr : BST(preorder, preStart + 1, i - 1);
        }
        else
        {
            node->right = nullptr;
            node->left = i == preStart + 1 ? nullptr : BST(preorder, preStart + 1, i - 1);
        }
        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        TreeNode *node = BST(preorder, 0, n - 1);
        return node;
    }
};