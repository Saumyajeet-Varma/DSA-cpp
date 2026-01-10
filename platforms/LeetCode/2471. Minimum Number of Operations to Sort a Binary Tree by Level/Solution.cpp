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
    int minimumOperations(TreeNode *root)
    {
        int ans = 0;
        if (!root || (!root->left && !root->right))
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> lvl(n, 0);
            vector<int> index(n, 0);
            for (int i = 0; i < n; i++)
            {
                index[i] = i;
                TreeNode *node = que.front();
                que.pop();
                lvl[i] = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            sort(index.begin(), index.end(), [&](int i, int j)
                 { return lvl[i] < lvl[j]; });
            int i = 0;
            while (i < n)
            {
                int j = index[i];
                if (i == j)
                    i++;
                else
                {
                    ans++;
                    swap(index[i], index[j]);
                }
            }
        }
        return ans;
    }
};