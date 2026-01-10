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

class FindElements
{
private:
    TreeNode *newRoot;
    unordered_set<int> st;

    void dfs(TreeNode *root, int parentVal, bool isLeft)
    {
        if (!root)
            return;

        root->val = isLeft ? (2 * parentVal + 1) : (2 * parentVal + 2);
        st.insert(root->val);

        dfs(root->left, root->val, true);
        dfs(root->right, root->val, false);
    }

public:
    FindElements(TreeNode *root)
    {
        root->val = 0;
        st.insert(0);

        dfs(root->left, 0, true);
        dfs(root->right, 0, false);
    }

    bool find(int target)
    {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */