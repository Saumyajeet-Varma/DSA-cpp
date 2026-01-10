#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

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

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;

        for (auto stone : stones)
        {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_map<int, bool> stoneNodes;

        for (auto stone : stones)
        {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            ds.unionByRank(rowNode, colNode);

            stoneNodes[rowNode] = true;
            stoneNodes[colNode] = true;
        }

        int components = 0;

        for (auto node : stoneNodes)
        {
            int stone = node.first;

            if (ds.findParent(stone) == stone)
                components++;
        }

        return n - components;
    }
};