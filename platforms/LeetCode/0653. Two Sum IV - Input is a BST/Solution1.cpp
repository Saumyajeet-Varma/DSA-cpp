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
    void inorder(TreeNode *node, vector<int> &result)
    {
        if (!node)
            return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nodes = inorderTraversal(root);
        int l = 0, r = nodes.size() - 1;
        while (l < r)
        {
            int sum = nodes[l] + nodes[r];
            if (sum == k)
                return true;
            else if (sum > k)
                r--;
            else
                l++;
        }
        return false;
    }
};