#include <bits/stdc++.h>
using namespace std;

class Solution
{
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

        vector<int> dist(V, 1e9);
        queue<int> que;

        dist[0] = 0;
        que.push(0);

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

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};
