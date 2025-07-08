#include <bits/stdc++.h>
using namespace std;

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
        if (parent[node] == node)
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
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int target = (n - 1) * n + (n - 1);

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        DisjointSet ds(n * n);

        vector<int> vis(n * n, 0);
        vector<pair<int, pair<int, int>>> flat;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flat.push_back({grid[i][j], {i, j}});
            }
        }

        sort(flat.begin(), flat.end());

        for (auto it : flat)
        {
            int wt = it.first;
            int x = it.second.first;
            int y = it.second.second;

            int cell = x * n + y;

            vis[cell] = 1;

            for (auto dir : dirs)
            {
                int dx = dir.first;
                int dy = dir.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    int ncell = nx * n + ny;

                    if (vis[ncell])
                        ds.unionBySize(cell, ncell);
                }
            }

            if (ds.findParent(0) == ds.findParent(target))
                return wt;
        }

        return -1;
    }
};