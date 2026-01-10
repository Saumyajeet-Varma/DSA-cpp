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
    int countNodes(TreeNode *root)
    {
        int count = 0;
        if (!root)
            return count;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                count++;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return count;
    }
};