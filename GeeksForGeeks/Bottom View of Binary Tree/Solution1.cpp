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
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pair<Node *, int>> que;
        map<int, int> mp;
        que.push({root, 0});
        while (!que.empty())
        {
            auto temp = que.front();
            que.pop();
            Node *node = temp.first;
            int x = temp.second;
            mp[x] = node->data;
            if (node->left)
                que.push({node->left, x - 1});
            if (node->right)
                que.push({node->right, x + 1});
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};