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
        queue<pair<Node *, pair<int, int>>> que;
        map<int, map<int, vector<int>>> mp;
        que.push({root, {0, 0}});
        while (!que.empty())
        {
            pair<Node *, pair<int, int>> temp = que.front();
            que.pop();
            Node *node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            mp[x][y].push_back(node->data);
            if (node->left)
                que.push({node->left, {x - 1, y + 1}});
            if (node->right)
                que.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> verticalOrder;
        for (auto i : mp)
        {
            vector<int> ansEl;
            for (auto j : i.second)
            {
                vector<int> vertical = j.second;
                ansEl.insert(ansEl.end(), vertical.begin(), vertical.end());
            }
            verticalOrder.push_back(ansEl);
        }
        int n = verticalOrder.size();
        for (int i = 0; i < n; i++)
        {
            int v = verticalOrder[i].size();
            ans.push_back(verticalOrder[i][v - 1]);
        }
        return ans;
    }
};