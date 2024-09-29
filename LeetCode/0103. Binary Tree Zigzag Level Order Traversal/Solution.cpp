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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        bool LtoR = true;
        while (!que.empty())
        {
            int n = que.size();
            vector<int> ansEl(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                int index = LtoR ? i : n - 1 - i;
                ansEl[index] = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            LtoR = !LtoR;
            ans.push_back(ansEl);
        }
        return ans;
    }
};