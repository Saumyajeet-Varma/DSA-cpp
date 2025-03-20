#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findRoot(int node, vector<int> &parent)
    {
        if (parent[node] != node)
        {
            parent[node] = findRoot(parent[node], parent);
        }
        return parent[node];
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        vector<int> parent(n);
        vector<int> minPathCost(n, -1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (auto &edge : edges)
        {
            int source = edge[0];
            int target = edge[1];
            int weight = edge[2];

            int sourceRoot = findRoot(source, parent);
            int targetRoot = findRoot(target, parent);

            minPathCost[targetRoot] &= weight;

            if (sourceRoot != targetRoot)
            {
                minPathCost[targetRoot] &= minPathCost[sourceRoot];
                parent[sourceRoot] = targetRoot;
            }
        }

        vector<int> result;

        for (auto &q : query)
        {
            int start = q[0];
            int end = q[1];

            if (start == end)
                result.push_back(0);
            else if (findRoot(start, parent) != findRoot(end, parent))
                result.push_back(-1);
            else
                result.push_back(minPathCost[findRoot(start, parent)]);
        }

        return result;
    }
};