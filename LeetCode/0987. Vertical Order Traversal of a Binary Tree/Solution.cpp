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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<pair<TreeNode *, pair<int, int>>> que;
        map<int, map<int, vector<int>>> mp;
        que.push({root, {0, 0}});
        while (!que.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = que.front();
            que.pop();
            TreeNode *node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            mp[x][y].push_back(node->val);
            if (node->left)
                que.push({node->left, {x - 1, y + 1}});
            if (node->right)
                que.push({node->right, {x + 1, y + 1}});
        }
        for (auto i : mp)
        {
            vector<int> ansEl;
            for (auto j : i.second)
            {
                vector<int> vertical = j.second;
                sort(vertical.begin(), vertical.end());
                ansEl.insert(ansEl.end(), vertical.begin(), vertical.end());
            }
            ans.push_back(ansEl);
        }
        return ans;
    }
};