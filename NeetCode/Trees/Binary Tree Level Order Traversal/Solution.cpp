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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levels;
        queue<TreeNode *> que;

        if (!root)
        {
            return levels;
        }

        que.push(root);

        while (!que.empty())
        {
            int n = que.size();
            vector<int> level;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();

                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }

                level.push_back(node->val);
            }

            levels.push_back(level);
        }

        return levels;
    }
};
