#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &insertTime, vector<int> &lowTime, vector<vector<int>> &result)
    {
        vis[node] = 1;

        insertTime[node] = timer;
        lowTime[node] = timer;

        timer++;

        for (auto adjNode : adj[node])
        {
            if (adjNode == parent)
                continue;

            if (!vis[adjNode])
            {
                dfs(adjNode, node, vis, adj, insertTime, lowTime, result);

                lowTime[node] = min(lowTime[node], lowTime[adjNode]);

                if (lowTime[adjNode] > insertTime[node])
                    result.push_back({node, adjNode});
            }
            else
            {
                lowTime[node] = min(lowTime[node], insertTime[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];

        for (auto conn : connections)
        {
            int u = conn[0];
            int v = conn[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> insertTime(n, -1);
        vector<int> lowTime(n, -1);
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, -1, vis, adj, insertTime, lowTime, result);
        }

        return result;
    }
};