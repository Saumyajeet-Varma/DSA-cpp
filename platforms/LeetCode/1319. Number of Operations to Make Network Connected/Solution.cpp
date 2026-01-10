#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findParent(int node, vector<int> &parent)
    {
        if (node == parent[node])
            return node;

        parent[node] = findParent(parent[node], parent);

        return parent[node];
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (auto conn : connections)
        {
            int u = findParent(conn[0], parent);
            int v = findParent(conn[1], parent);

            if (u != v)
                parent[v] = u;
        }

        int components = 0;

        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                components++;
        }

        return components - 1;
    }
};