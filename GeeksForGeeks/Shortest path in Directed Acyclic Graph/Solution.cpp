#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void toposort(int node, stack<int> &stk, vector<int> &vis, vector<vector<pair<int, int>>> &adj)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            int v = adjNode.first;

            if (!vis[v])
                toposort(v, stk, vis, adj);
        }

        stk.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<int> vis(V, 0);
        stack<int> stk;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                toposort(i, stk, vis, adj);
        }

        vector<int> dist(V, 1e9);

        dist[0] = 0;

        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            for (auto adjNode : adj[node])
            {
                int v = adjNode.first;
                int w = adjNode.second;

                dist[v] = min(dist[v], dist[node] + w);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};
