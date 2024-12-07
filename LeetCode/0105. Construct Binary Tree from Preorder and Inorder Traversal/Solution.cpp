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
    TreeNode *buildSubTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || preStart > preEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int leftNodes = inRoot - inStart;
        root->left = buildSubTree(inorder, inStart, inRoot - 1, preorder, preStart + 1, preStart + leftNodes, inMap);
        root->right = buildSubTree(inorder, inRoot + 1, inEnd, preorder, preStart + leftNodes + 1, preEnd, inMap);
        return root;
    }

    // Main Function
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int inSize = inorder.size();
        int preSize = preorder.size();
        if (inSize != preSize)
            return NULL;
        unordered_map<int, int> inMap;
        for (int i = 0; i < inSize; i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildSubTree(inorder, 0, inSize - 1, preorder, 0, preSize - 1, inMap);
        return root;
    }
};