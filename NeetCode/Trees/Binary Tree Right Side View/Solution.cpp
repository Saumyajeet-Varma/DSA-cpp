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
        vector<int> result;

        if (!root)
        {
            return result;
        }

        map<int, int> mpp;
        queue<pair<TreeNode *, int>> que;

        que.push({root, 0});

        while (!que.empty())
        {
            int n = que.size();

            for (int i = 0; i < n; i++)
            {
                auto temp = que.front();
                que.pop();

                TreeNode *node = temp.first;
                int lvl = temp.second;

                mpp[lvl] = node->val;

                if (node->left)
                {
                    que.push({node->left, lvl + 1});
                }
                if (node->right)
                {
                    que.push({node->right, lvl + 1});
                }
            }
        }

        for (auto it : mpp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};
