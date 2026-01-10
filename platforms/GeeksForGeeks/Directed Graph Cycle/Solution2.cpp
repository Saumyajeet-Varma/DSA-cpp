#include <bits/stdc++.h>
using namespace std;

class Solution
{
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

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto adjNode : adj[i])
            {
                indegree[adjNode]++;
            }
        }

        queue<int> que;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                que.push(i);
        }

        vector<int> topo;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            topo.push_back(node);

            for (auto adjNode : adj[node])
            {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                    que.push(adjNode);
            }
        }

        return topo.size() != V;
    }
};