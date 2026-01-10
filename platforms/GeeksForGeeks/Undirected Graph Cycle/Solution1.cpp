#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> que;

        vis[src] = 1;
        que.push({src, -1});

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int node = curr.first;
            int parent = curr.second;

            for (auto adjNode : adj[node])
            {
                if (!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    que.push({adjNode, node});
                }
                else if (adjNode != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        if (V == 0 || V == 1 || V == 2)
            return false;

        int e = edges.size();

        if (e == 0 || e == 1 || e == 2)
            return false;

        vector<int> adj[V];
        vector<int> vis(V, 0);

        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && detectCycle(i, adj, vis))
                return true;
        }

        return false;
    }
};