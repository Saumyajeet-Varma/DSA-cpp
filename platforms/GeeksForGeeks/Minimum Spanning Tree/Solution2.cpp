#include <bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        parent[node] = findParent(parent[node]);

        return parent[node];
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        for (int node = 0; node < V; node++)
        {
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int sum = 0;

        for (auto edge : edges)
        {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                sum += w;
                ds.unionBySize(u, v);
            }
        }

        return sum;
    }
};