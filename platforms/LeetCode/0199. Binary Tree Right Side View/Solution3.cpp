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
    void recursiveFunction(TreeNode *node, int level, vector<int> &ans)
    {
        if (!node)
            return;
        if (ans.size() == level)
            ans.push_back(node->val);
        recursiveFunction(node->right, level + 1, ans);
        recursiveFunction(node->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        recursiveFunction(root, 0, ans);
        return ans;
    }
};