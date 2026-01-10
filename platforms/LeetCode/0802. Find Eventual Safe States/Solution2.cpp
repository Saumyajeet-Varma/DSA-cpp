#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &inStack)
    {
        if (inStack[node])
            return true;

        if (vis[node])
            return false;

        vis[node] = true;
        inStack[node] = true;

        for (auto adjNodes : adj[node])
        {
            if (dfs(adjNodes, adj, vis, inStack))
                return true;
        }

        inStack[node] = false;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<bool> vis(n);
        vector<bool> inStack(n);

        for (int i = 0; i < n; i++)
        {
            dfs(i, graph, vis, inStack);
        }

        vector<int> safeNodes;

        for (int i = 0; i < n; i++)
        {
            if (!inStack[i])
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};