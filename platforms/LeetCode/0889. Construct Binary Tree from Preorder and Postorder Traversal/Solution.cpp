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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        stack<TreeNode *> nodes;

        TreeNode *root = new TreeNode(preorder[0]);
        nodes.push(root);

        int preIndex = 1;
        int postIndex = 0;

        while (!nodes.empty())
        {
            TreeNode *currNode = nodes.top();

            if (currNode->val == postorder[postIndex])
            {
                nodes.pop();
                postIndex++;
            }
            else
            {
                TreeNode *newNode = new TreeNode(preorder[preIndex]);
                preIndex++;

                if (!currNode->left)
                    currNode->left = newNode;
                else
                    currNode->right = newNode;

                nodes.push(newNode);
            }
        }

        return root;
    }
};