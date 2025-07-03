#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int V = adj.size();

        vector<int> dist(V, 1e9);
        queue<int> que;

        dist[src] = 0;
        que.push(src);

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            for (int adjNode : adj[node])
            {
                if (dist[node] + 1 < dist[adjNode])
                {
                    dist[adjNode] = dist[node] + 1;
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