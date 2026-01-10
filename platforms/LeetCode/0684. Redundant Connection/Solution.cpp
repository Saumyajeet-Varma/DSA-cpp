#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isConnected(int u, int v, unordered_map<int, vector<int>> &graph)
    {
        unordered_set<int> vis;
        stack<int> stk;

        stk.push(u);

        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            if (vis.count(node))
                continue;
                
            vis.insert(node);

            if (node == v)
                return true;

            for (int adjNode : graph[node])
            {
                stk.push(adjNode);
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (graph.count(u) && graph.count(v) && isConnected(u, v, graph))
                return edge;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};