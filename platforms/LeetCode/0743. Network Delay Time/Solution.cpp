#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);

        pq.push({0, k});
        dist[k] = 0;

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
                }
            }
        }

        int maxDist = 0;

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9)
                return -1;

            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};