#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs1(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stk)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
                dfs1(adjNode, vis, adj, stk);
        }

        stk.push(node);
    }

    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
                dfs2(adjNode, vis, adj);
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        int V = adj.size();

        vector<int> vis(V, 0);
        stack<int> stk;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs1(i, vis, adj, stk);
        }

        vector<vector<int>> adjT(V);

        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;

            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;

        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            if (!vis[node])
            {
                dfs2(node, vis, adjT);
                scc++;
            }
        }

        return scc;
    }
};