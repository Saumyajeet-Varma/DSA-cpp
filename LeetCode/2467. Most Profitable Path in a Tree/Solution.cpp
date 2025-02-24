#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &adj, int node, int depth, map<int, int> &vis, vector<int> &amount)
    {
        int currVal = amount[node];

        if (vis.count(node))
        {
            if (vis[node] < depth)
                currVal = 0;
            else if (vis[node] == depth)
                currVal /= 2;
        }

        if (adj[node].empty())
            return currVal;

        int result = INT_MIN;

        for (auto adjNode : adj[node])
        {
            result = max(result, dfs(adj, adjNode, depth + 1, vis, amount));
        }

        return result + currVal;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> tree(n, vector<int>());
        vector<int> parent(n, 0);
        vector<int> added(n, 0);
        queue<int> que;
        map<int, int> vis;

        for (int i = 0; i < n - 1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        que.push(0);
        added[0] = 1;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            for (int adjNode : adj[node])
            {
                if (!added[adjNode])
                {
                    added[adjNode]++;
                    tree[node].push_back(adjNode);
                    que.push(adjNode);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto child : tree[i])
            {
                parent[child] = i;
            }
        }

        int node = bob;
        int aliceDepth = 0;

        while (node)
        {
            vis[node] = aliceDepth++;
            node = parent[node];
        }

        return dfs(tree, 0, 0, vis, amount);
    }
};