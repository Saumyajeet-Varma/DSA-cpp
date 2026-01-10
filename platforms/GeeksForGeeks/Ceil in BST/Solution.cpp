#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int findCeil(Node *root, int X)
    {
        Node *node = root;
        int ans = -1;
        while (node)
        {
            if (node->data == X)
            {
                ans = node->data;
                return ans;
            }
            if (node->data < X)
            {
                node = node->right;
            }
            else
            {
                ans = node->data;
                node = node->left;
            }
        }
        return ans;
    }
};