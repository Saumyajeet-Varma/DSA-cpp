#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> result;
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        queue<int> que;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            for (auto adjNode : adj[i])
            {
                indegree[adjNode]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                que.push(i);
        }

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            result.push_back(node);

            for (auto adjNode : adj[node])
            {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                    que.push(adjNode);
            }
        }

        return result;
    }
};