#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (int adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                dfs(adjNode, vis, adj);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        vector<vector<int>> adj(n);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                components++;
                dfs(i, vis, adj);
            }
        }

        return components;
    }
};
