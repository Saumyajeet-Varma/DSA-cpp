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
        queue<pair<TreeNode *, int>> que;
        map<int, int> mp;
        que.push({root, 0});
        while (!que.empty())
        {
            auto temp = que.front();
            que.pop();
            TreeNode *node = temp.first;
            int y = temp.second;
            mp[y] = node->val;
            if (node->left)
                que.push({node->left, y + 1});
            if (node->right)
                que.push({node->right, y + 1});
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};