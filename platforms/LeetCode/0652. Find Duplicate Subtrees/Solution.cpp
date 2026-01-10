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
private:
    string solve(TreeNode *&node, unordered_map<string, int> &mpp, vector<TreeNode *> &result)
    {
        if (!node)
            return "N";

        string left = solve(node->left, mpp, result);
        string right = solve(node->right, mpp, result);

        string curr = to_string(node->val) + "," + left + "," + right;

        if (mpp.find(curr) != mpp.end())
        {
            if (mpp[curr] == 1)
                result.push_back(node);
        }

        mpp[curr]++;

        return curr;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> result;
        unordered_map<string, int> mpp;

        solve(root, mpp, result);

        return result;
    }
};