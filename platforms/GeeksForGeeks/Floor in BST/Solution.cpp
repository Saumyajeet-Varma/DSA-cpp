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
    int floor(Node *root, int x)
    {
        Node *node = root;
        int ans = -1;
        while (node)
        {
            if (node->data == x)
            {
                ans = node->data;
                return ans;
            }
            if (node->data < x)
            {
                ans = node->data;
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        return ans;
    }
};