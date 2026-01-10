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
    int maxPathDown(TreeNode *node, int &maxx)
    {
        if (node == NULL)
            return 0;
        int left = max(0, maxPathDown(node->left, maxx));
        int right = max(0, maxPathDown(node->right, maxx));
        maxx = max(maxx, node->val + left + right);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxx = INT_MIN;
        maxPathDown(root, maxx);
        return maxx;
    }
};