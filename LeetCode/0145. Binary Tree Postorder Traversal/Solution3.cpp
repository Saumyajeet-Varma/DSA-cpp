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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> stk1, stk2;
        stk1.push(root);
        while (!stk1.empty())
        {
            TreeNode *node = stk1.top();
            stk1.pop();
            stk2.push(node);
            if (node->left)
                stk1.push(node->left);
            if (node->right)
                stk1.push(node->right);
        }
        while (!stk2.empty())
        {
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        return ans;
    }
};