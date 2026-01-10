#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPossible(int node, vector<vector<int>> &adj, vector<int> &colors, int color)
    {
        for (int neighbor : adj[node])
        {
            if (colors[neighbor] == color)
                return false;
        }

        return true;
    }

    bool solve(int node, int v, vector<vector<int>> &adj, int m, vector<int> &colors)
    {
        if (node == v)
            return true;

        for (int color = 1; color <= m; color++)
        {
            if (isPossible(node, adj, colors, color))
            {
                colors[node] = color;

                if (solve(node + 1, v, adj, m, colors))
                    return true;

                colors[node] = 0;
            }
        }

        return false;
    }

public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(v);
        vector<int> colors(v, 0);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int w = edge[1];

            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        if (solve(0, v, adj, m, colors))
            return true;

        return false;
    }
};