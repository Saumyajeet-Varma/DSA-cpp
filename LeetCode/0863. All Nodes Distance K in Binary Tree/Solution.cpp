#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left)
            {
                parent[node->left] = node;
                que.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                que.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        markParents(root, parent);
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> que;
        que.push(target);
        vis[target] = true;
        int curr_lvl = 0;
        while (!que.empty())
        {
            if (curr_lvl == k)
                break;
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left && !vis[node->left])
                {
                    que.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right])
                {
                    que.push(node->right);
                    vis[node->right] = true;
                }
                if (parent[node] && !vis[parent[node]])
                {
                    que.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            curr_lvl++;
        }
        vector<int> result;
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            result.push_back(node->val);
        }
        return result;
    }
};