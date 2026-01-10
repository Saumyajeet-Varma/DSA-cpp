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
        stack<Node *> stk;
        Node *node = root;
        while (node || !stk.empty())
        {
            if (node)
            {
                stk.push(node);
                node = node->left;
            }
            else
            {
                Node *temp = stk.top()->right;
                if (temp)
                    node = temp;
                else
                {
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->data);
                    while (!stk.empty() && temp == stk.top()->right)
                    {
                        temp = stk.top();
                        stk.pop();
                        ans.push_back(temp->data);
                    }
                }
            }
        }
        return ans;
    }
};