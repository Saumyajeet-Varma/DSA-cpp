#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(int start, int end, int n, vector<vector<int>> &adj)
    {
        vector<int> dist(n, INT_MAX);
        queue<int> que;
        dist[start] = 0;
        que.push(start);
        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            for (int it : adj[curr])
            {
                if (dist[it] > dist[curr] + 1)
                {
                    dist[it] = dist[curr] + 1;
                    que.push(it);
                }
            }
        }
        return dist[end];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i + 1);
        }
        for (auto query : queries)
        {
            int src = query[0], des = query[1];
            adj[src].push_back(des);
            ans.push_back(bfs(0, n - 1, n, adj));
        }
        return ans;
    }
};