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
    void swapChildNodes(TreeNode *node)
    {
        if (node->left)
        {
            swapChildNodes(node->left);
        }
        if (node->right)
        {
            swapChildNodes(node->right);
        }

        TreeNode *leftNode = node->left;
        TreeNode *rightNode = node->right;

        node->left = rightNode;
        node->right = leftNode;
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        swapChildNodes(root);

        return root;
    }
};
