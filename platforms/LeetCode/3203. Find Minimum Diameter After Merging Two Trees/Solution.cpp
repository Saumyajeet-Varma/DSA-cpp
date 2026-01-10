#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDiameter(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
                que.push(i);
        }
        int lvl = 0;
        int leftNodes = n;
        while (leftNodes > 2)
        {
            int queSize = que.size();
            leftNodes -= queSize;
            for (int i = 0; i < queSize; i++)
            {
                int node = que.front();
                que.pop();
                for (int adjNode : adj[node])
                {
                    deg[adjNode]--;
                    if (deg[adjNode] == 1)
                        que.push(adjNode);
                }
            }
            lvl++;
        }
        return (leftNodes == 2) ? (2 * lvl) + 1 : (2 * lvl);
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int d1 = findDiameter(edges1);
        int d2 = findDiameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};