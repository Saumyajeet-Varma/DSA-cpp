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
    void findKthLargest(Node *node, int &k, int &result)
    {
        if (!node || k == 0)
            return;

        findKthLargest(node->right, k, result);

        k--;

        if (k == 0)
        {
            result = node->data;
            return;
        }

        findKthLargest(node->left, k, result);
    }

public:
    int kthLargest(Node *root, int k)
    {
        int result = -1;
        findKthLargest(root, k, result);
        return result;
    }
};