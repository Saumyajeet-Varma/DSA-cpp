#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        vector<int> result;

        if (!root)
            return result;

        map<int, int> mp;
        queue<pair<Node *, int>> que;

        que.push({root, 0});

        while (!que.empty())
        {
            int n = que.size();

            for (int i = 0; i < n; i++)
            {
                auto temp = que.front();
                que.pop();

                Node *node = temp.first;
                int lvl = temp.second;

                if (!mp[lvl])
                    mp[lvl] = node->data;

                if (node->left)
                    que.push({node->left, lvl + 1});
                if (node->right)
                    que.push({node->right, lvl + 1});
            }
        }

        for (auto it : mp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};