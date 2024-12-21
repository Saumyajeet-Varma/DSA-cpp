#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, int parent, vector<int> &values, int k, unordered_map<int, vector<int>> &adj, int &ans)
    {
        int sum = values[node];
        for (int adjNode : adj[node])
        {
            if (adjNode != parent)
                sum += dfs(adjNode, node, values, k, adj, ans);
        }
        if (sum % k == 0)
        {
            ans++;
            return 0;
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        unordered_map<int, vector<int>> adj;
        int ans = 0;
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, values, k, adj, ans);
        return ans;
    }
};