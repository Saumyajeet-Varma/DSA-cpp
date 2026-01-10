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
    map<int, int> mpp;
    map<int, int> path;
    map<int, priority_queue<int>> level;

    int dfs1(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int l = 0, r = 0;
        if (node->left)
            l = dfs1(node->left);
        if (node->right)
            r = dfs1(node->right);
        return mpp[node->val] = 1 + max(l, r);
    }

    void dfs2(TreeNode *node)
    {
        if (node == NULL)
            return;
        path[node->val]++;
        if (node->left && node->right)
        {
            if (mpp[node->left->val] > mpp[node->right->val])
                dfs2(node->left);
            else
                dfs2(node->right);
        }
        else if (node->left == NULL)
            dfs2(node->right);
        else if (node->right == NULL)
            dfs2(node->left);
    }

    void bfs(TreeNode *node)
    {
        queue<TreeNode *> que;
        que.push(node);
        int lvl = 0;
        while (!que.empty())
        {
            int n = que.size();
            lvl++;
            while (n--)
            {
                auto it = que.front();
                que.pop();
                level[lvl].push(mpp[it->val]);
                if (it->right)
                    que.push(it->right);
                if (it->left)
                    que.push(it->left);
            }
        }
    }

    // Main Function
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        dfs1(root);
        dfs2(root);
        vector<int> result;
        int h = mpp[root->val];
        bfs(root);
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            int nh = h;
            if (path.find(queries[i]) != path.end())
            {
                int lvl = h - mpp[queries[i]] + 1;
                if (level[lvl].size() <= 1)
                    result.push_back(h - mpp[queries[i]] - 1);
                else
                {
                    int topp = level[lvl].top();
                    level[lvl].pop();
                    result.push_back(lvl + level[lvl].top() - 2);
                    level[lvl].push(topp);
                }
            }
            else
                result.push_back(nh - 1);
        }
        return result;
    }
};