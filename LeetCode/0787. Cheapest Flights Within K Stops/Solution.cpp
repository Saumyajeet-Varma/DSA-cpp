#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> que;
        vector<int> dist(n, 1e9);

        que.push({0, {src, 0}});
        dist[src] = 0;

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            int stops = curr.first;
            int node = curr.second.first;
            int cost = curr.second.second;

            if (stops > k)
                continue;

            for (auto adjNode : adj[node])
            {
                int v = adjNode.first;
                int w = adjNode.second;

                if (cost + w < dist[v])
                {
                    dist[v] = cost + w;
                    que.push({stops + 1, {v, cost + w}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};