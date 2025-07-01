#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, stack<int> &stk, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
                dfs(adjNode, stk, vis, adj);
        }

        stk.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> result;
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        stack<int> stk;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, stk, vis, adj);
        }

        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }

        return result;
    }
};