#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    void findKthSmallest(Node *node, int &k, int &result)
    {
        if (!node || k == 0)
            return;

        findKthSmallest(node->left, k, result);

        k--;

        if (k == 0)
        {
            result = node->data;
            return;
        }

        findKthSmallest(node->right, k, result);
    }

public:
    int kthSmallest(Node *root, int k)
    {
        int result = -1;

        findKthSmallest(root, k, result);

        return result;
    }
};