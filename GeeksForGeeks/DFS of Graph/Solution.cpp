#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void graphDFS(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &result)
    {
        result.push_back(node);
        vis[node] = 1;

        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor])
                graphDFS(neighbor, adj, vis, result);
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int v = adj.size();

        vector<int> result;
        vector<int> vis(v, 0);

        graphDFS(0, adj, vis, result);

        return result;
    }
};