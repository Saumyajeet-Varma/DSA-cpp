#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int node, vector<vector<int>> &adj, vector<int> &comp, vector<bool> &vis)
    {
        queue<int> que;

        que.push(node);
        vis[node] = true;

        while (!que.empty())
        {
            int curr = que.front();
            que.pop();

            comp.push_back(curr);

            for (auto it : adj[curr])
            {
                if (!vis[it])
                {
                    que.push(it);
                    vis[it] = true;
                }
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int result = 0;

        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> comp;
                bfs(i, adj, comp, vis);
                bool isComp = true;

                for (auto it : comp)
                {
                    if (adj[it].size() != comp.size() - 1)
                    {
                        isComp = false;
                        break;
                    }
                }

                if (isComp)
                    result++;
            }
        }

        return result;
    }
};