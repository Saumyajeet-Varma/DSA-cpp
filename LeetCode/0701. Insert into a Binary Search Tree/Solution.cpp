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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (!root)
            return newNode;
        TreeNode *node = root;
        while (true)
        {
            if (node->val <= val)
            {
                if (node->right)
                    node = node->right;
                else
                {
                    node->right = newNode;
                    break;
                }
            }
            else
            {
                if (node->left)
                    node = node->left;
                else
                {
                    node->left = newNode;
                    break;
                }
            }
        }
        return root;
    }
};