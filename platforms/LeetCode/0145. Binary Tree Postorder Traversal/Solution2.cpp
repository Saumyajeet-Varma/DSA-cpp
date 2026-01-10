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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node || !stk.empty())
        {
            if (node)
            {
                stk.push(node);
                node = node->left;
            }
            else
            {
                TreeNode *temp = stk.top()->right;
                if (temp)
                    node = temp;
                else
                {
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->val);
                    while (!stk.empty() && temp == stk.top()->right)
                    {
                        temp = stk.top();
                        stk.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};