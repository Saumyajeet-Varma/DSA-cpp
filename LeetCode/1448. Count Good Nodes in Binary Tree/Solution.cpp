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
    int dfs(TreeNode *node, int maxVal)
    {
        if (!node)
            return 0;

        int result = node->val >= maxVal ? 1 : 0;

        maxVal = max(maxVal, node->val);

        result += dfs(node->left, maxVal);
        result += dfs(node->right, maxVal);

        return result;
    }

public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, root->val);
    }
};