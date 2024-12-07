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
    TreeNode *buildSubTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int leftNodes = inRoot - inStart;
        root->left = buildSubTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + leftNodes - 1, inMap);
        root->right = buildSubTree(inorder, inRoot + 1, inEnd, postorder, postStart + leftNodes, postEnd - 1, inMap);
        return root;
    }

    // Main Function
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int inSize = inorder.size();
        int postSize = postorder.size();
        if (inSize != postSize)
            return NULL;
        unordered_map<int, int> inMap;
        for (int i = 0; i < inSize; i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildSubTree(inorder, 0, inSize - 1, postorder, 0, postSize - 1, inMap);
        return root;
    }
};