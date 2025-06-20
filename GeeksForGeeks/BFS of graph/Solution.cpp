#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int v = adj.size();

        vector<int> bfs;

        queue<int> que;
        vector<int> vis(v, 0);

        que.push(0);
        vis[0] = 1;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            bfs.push_back(node);

            for (auto neighbor : adj[node])
            {
                if (!vis[neighbor])
                {
                    que.push(neighbor);
                    vis[neighbor] = 1;
                }
            }
        }

        return bfs;
    }
};