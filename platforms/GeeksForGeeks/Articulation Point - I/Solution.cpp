#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &insertTime, vector<int> &lowTime, vector<int> &mark)
    {
        vis[node] = 1;

        insertTime[node] = timer;
        lowTime[node] = timer;

        timer++;

        int child = 0;

        for (auto adjNode : adj[node])
        {
            if (adjNode == parent)
                continue;

            if (!vis[adjNode])
            {
                dfs(adjNode, node, vis, adj, insertTime, lowTime, mark);

                lowTime[node] = min(lowTime[node], lowTime[adjNode]);

                if (lowTime[adjNode] >= insertTime[node] && parent != -1)
                    mark[node] = 1;

                child++;
            }
            else
            {
                lowTime[node] = min(lowTime[node], insertTime[adjNode]);
            }
        }

        if (parent == -1 && child > 1)
            mark[node] = 1;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> insertTime(V, -1);
        vector<int> lowTime(V, -1);
        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, vis, adj, insertTime, lowTime, mark);
        }

        vector<int> result;

        for (int i = 0; i < V; i++)
        {
            if (mark[i])
                result.push_back(i);
        }

        return result.size() == 0 ? vector<int>{-1} : result;
    }
};