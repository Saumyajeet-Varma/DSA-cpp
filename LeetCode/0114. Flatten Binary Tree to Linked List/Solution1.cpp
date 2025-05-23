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
    void morrisTraversal(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }

    // MAIN FUNCTION
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        morrisTraversal(root);
    }
};