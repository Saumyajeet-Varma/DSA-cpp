
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
    bool areSame(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2)
            return true;

        if (node1 && node2 && node1->val == node2->val)
            return areSame(node1->left, node2->left) && areSame(node1->right, node2->right);

        return false;
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
            return true;

        if (!root)
            return false;

        if (areSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};