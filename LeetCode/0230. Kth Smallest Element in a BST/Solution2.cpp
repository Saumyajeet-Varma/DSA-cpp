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
    void solve(TreeNode *node, int &count, int &ans, int k)
    {
        if (!node)
            return;
        solve(node->left, count, ans, k);
        count++;
        if (count == k)
        {
            ans = node->val;
            return;
        }
        solve(node->right, count, ans, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans;
        solve(root, count, ans, k);
        return ans;
    }
};