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
    void findKth(TreeNode *node, int k, int &count, int &result)
    {
        if (!node)
        {
            return;
        }

        findKth(node->left, k, count, result);

        count++;

        if (count == k)
        {
            result = node->val;
            return;
        }

        findKth(node->right, k, count, result);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int result;
        int count = 0;

        findKth(root, k, count, result);

        return result;
    }
};
