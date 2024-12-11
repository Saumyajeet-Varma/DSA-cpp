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
    TreeNode *findLastRight(TreeNode *node)
    {
        while (node->right)
        {
            node = node->right;
        }
        return node;
    }

    TreeNode *helper(TreeNode *node)
    {
        if (!node->left)
            return node->right;
        else if (!node->right)
            return node->left;
        TreeNode *rightChild = node->right;
        TreeNode *lastRight = findLastRight(node->left);
        lastRight->right = rightChild;
        return node->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;
        if (root->val == key)
            return helper(root);
        TreeNode *node = root;
        while (node)
        {
            if (node->val > key)
            {
                if (node->left && node->left->val == key)
                {
                    node->left = helper(node->left);
                    break;
                }
                else
                    node = node->left;
            }
            else
            {
                if (node->right && node->right->val == key)
                {
                    node->right = helper(node->right);
                    break;
                }
                else
                    node = node->right;
            }
        }
        return root;
    }
};