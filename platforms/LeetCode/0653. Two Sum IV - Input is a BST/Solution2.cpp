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

class BSTIterator
{
    stack<TreeNode *> stk;
    bool reverse;

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            stk.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = stk.top();
        stk.pop();
        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root || (!root->left && !root->right))
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next(), j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};