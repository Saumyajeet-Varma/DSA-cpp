#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        if (m == 0)
            return {-1};

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int d = topp.first;
            int node = topp.second;

            for (auto adjNode : adj[node])
            {
                int v = adjNode.first;
                int w = adjNode.second;

                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    pq.push({d + w, v});
                    parent[v] = node;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;

        int curr = n;

        while (parent[curr] != curr)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        path.push_back(1);
        path.push_back(dist[n]);

        reverse(path.begin(), path.end());

        return path;
    }
};