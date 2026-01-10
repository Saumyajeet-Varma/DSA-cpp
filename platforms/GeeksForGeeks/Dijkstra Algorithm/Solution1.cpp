#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, 1e9);
        queue<int> que;

        dist[src] = 0;
        que.push(src);

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;

                if (dist[adjNode] > dist[node] + wt)
                {
                    dist[adjNode] = dist[node] + wt;
                    que.push(adjNode);
                }
            }
        }

        return dist;
    }
};