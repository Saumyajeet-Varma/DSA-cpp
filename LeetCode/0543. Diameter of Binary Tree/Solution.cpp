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
    int diameterFromNode(TreeNode *node, int &diameter)
    {
        if (node == NULL)
            return 0;
        int lh = diameterFromNode(node->left, diameter);
        int rh = diameterFromNode(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        diameterFromNode(root, diameter);
        return diameter;
    }
};