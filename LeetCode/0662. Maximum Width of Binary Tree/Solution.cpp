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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxWidth = 0;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        while (!que.empty())
        {
            int n = que.size();
            int minn = que.front().second;
            int leftMost, rightMost;
            for (int i = 0; i < n; i++)
            {
                int curr = que.front().second - minn;
                TreeNode *node = que.front().first;
                que.pop();
                if (i == 0)
                    leftMost = curr;
                if (i == n - 1)
                    rightMost = curr;
                if (node->left)
                    que.push({node->left, (long long)curr * 2 + 1});
                if (node->right)
                    que.push({node->right, (long long)curr * 2 + 2});
            }
            maxWidth = max(maxWidth, rightMost - leftMost + 1);
        }
        return maxWidth;
    }
};