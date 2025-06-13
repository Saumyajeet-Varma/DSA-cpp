#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> lvls;

        if (!root)
            return lvls;

        queue<Node *> que;

        que.push(root);

        while (!que.empty())
        {
            int n = que.size();
            vector<int> lvl;

            for (int i = 0; i < n; i++)
            {
                Node *node = que.front();
                que.pop();

                lvl.push_back(node->data);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }

            lvls.push_back(lvl);
        }

        return lvls;
    }
};