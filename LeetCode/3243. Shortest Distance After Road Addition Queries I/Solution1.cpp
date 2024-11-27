#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<int> dist(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            dist[i] = i;
            adj[i].push_back(i + 1);
        }
        dist[n - 1] = n - 1;
        for (auto query : queries)
        {
            int src = query[0], des = query[1];
            adj[src].push_back(des);
            if (dist[src] + 1 < dist[des])
            {
                queue<int> que;
                que.push(des);
                dist[des] = dist[src] + 1;
                while (!que.empty())
                {
                    int curr = que.front();
                    que.pop();
                    for (auto it : adj[curr])
                    {
                        if (dist[curr] + 1 < dist[it])
                        {
                            dist[it] = dist[curr] + 1;
                            que.push(it);
                        }
                    }
                }
            }
            ans.push_back(dist.back());
        }
        return ans;
    }
};