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
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.length();

        vector<pair<int, int>> depthPairs;
        stack<pair<int, TreeNode *>> stk;
        TreeNode *root = nullptr;

        int i = 0;
        while (i < n)
        {
            int depth = 0;
            int val = 0;

            while (i < n && traversal[i] == '-')
            {
                depth++;
                i++;
            }

            while (i < n && traversal[i] != '-')
            {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            depthPairs.push_back({depth, val});
        }

        for (auto it : depthPairs)
        {
            int depth = it.first;
            int val = it.second;

            TreeNode *node = new TreeNode(val);

            while (!stk.empty() && stk.top().first >= depth)
            {
                stk.pop();
            }

            if (!stk.empty())
            {
                TreeNode *parent = stk.top().second;

                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
            }
            else
            {
                root = node;
            }

            stk.push({depth, node});
        }

        return root;
    }
};