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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int node = curr.second;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;

                if (dist[adjNode] > d + wt)
                {
                    dist[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }

        return dist;
    }
};