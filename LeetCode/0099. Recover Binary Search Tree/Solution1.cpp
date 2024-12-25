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
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;

    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        if (prev && (node->val < prev->val))
        {
            if (!first)
            {
                first = prev;
                middle = node;
            }
            else
            {
                last = node;
            }
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = prev = NULL;
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};