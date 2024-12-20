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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        bool oddLvl = false;
        while (!que.empty())
        {
            int n = que.size();
            vector<TreeNode *> lvlNodes(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (oddLvl)
                {
                    lvlNodes[i] = node;
                    if (i >= n / 2)
                        swap(lvlNodes[i]->val, lvlNodes[n - 1 - i]->val);
                }
            }
            oddLvl = !oddLvl;
        }
        return root;
    }
};