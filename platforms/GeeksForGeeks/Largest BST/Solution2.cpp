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

struct BSTNode
{
    int maxSize;
    int minVal;
    int maxVal;

    BSTNode(int maxSize, int minVal, int maxVal)
    {
        this->maxSize = maxSize;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

class Solution
{
private:
    BSTNode largestBSTSubtree(Node *node)
    {
        if (!node)
            return BSTNode(0, INT_MAX, INT_MIN);
        BSTNode leftNode = largestBSTSubtree(node->left);
        BSTNode rightNode = largestBSTSubtree(node->right);
        if (leftNode.maxVal < node->data && node->data < rightNode.minVal)
        {
            int newSize = leftNode.maxSize + rightNode.maxSize + 1;
            int newMin = min(node->data, leftNode.minVal);
            int newMax = max(node->data, rightNode.maxVal);
            return BSTNode(newSize, newMin, newMax);
        }
        return BSTNode(max(leftNode.maxSize, rightNode.maxSize), INT_MIN, INT_MAX);
    }

public:
    int largestBst(Node *root)
    {
        return largestBSTSubtree(root).maxSize;
    }
};