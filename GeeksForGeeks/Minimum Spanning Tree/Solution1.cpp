#include <bits/stdc++.h>
using namespace std;

// Prim's Algorithm
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        int sum = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int wt = topp.first;
            int node = topp.second;

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto adjNode : adj[node])
            {
                int v = adjNode[0];
                int w = adjNode[1];

                if (!vis[v])
                    pq.push({w, v});
            }
        }

        return sum;
    }
};