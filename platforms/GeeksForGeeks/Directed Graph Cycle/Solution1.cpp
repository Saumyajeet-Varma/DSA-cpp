#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectCycle(int node, vector<vector<int>> adj, vector<int> vis, vector<int> path)
    {
        vis[node] = 1;
        path[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                if (detectCycle(adjNode, adj, vis, path))
                    return true;
            }
            else if (path[adjNode])
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && detectCycle(i, adj, vis, path))
                return true;
        }

        return false;
    }
};