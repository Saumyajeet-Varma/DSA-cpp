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
    int checkHeight(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        int leftH = checkHeight(node->left);
        int rightH = checkHeight(node->right);

        if (leftH == -1 || rightH == -1)
        {
            return -1;
        }

        if (abs(leftH - rightH) > 1)
        {
            return -1;
        }

        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int balancedVar = checkHeight(root);
        return balancedVar != -1;
    }
};
