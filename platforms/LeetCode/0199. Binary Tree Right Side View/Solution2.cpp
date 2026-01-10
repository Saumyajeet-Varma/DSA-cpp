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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> que;
        vector<vector<int>> levelOrder;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                level.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            levelOrder.push_back(level);
        }
        for (vector<int> vec : levelOrder)
        {
            int v = vec.size();
            ans.push_back(vec[v - 1]);
        }
        return ans;
    }
};