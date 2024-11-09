#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<Node *> stk1, stk2;
        stk1.push(root);
        while (!stk1.empty())
        {
            Node *node = stk1.top();
            stk1.pop();
            stk2.push(node);
            if (node->left)
                stk1.push(node->left);
            if (node->right)
                stk1.push(node->right);
        }
        while (!stk2.empty())
        {
            Node *node = stk2.top();
            stk2.pop();
            ans.push_back(node->data);
        }
        return ans;
    }
};