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
    // MORRIS TRAVERSAL
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->right)
            {
                postorder.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                TreeNode *prev = curr->right;
                while (prev->left && prev->left != curr)
                {
                    prev = prev->left;
                }
                if (!prev->left)
                {
                    prev->left = curr;
                    postorder.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    prev->left = nullptr;
                    curr = curr->left;
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};