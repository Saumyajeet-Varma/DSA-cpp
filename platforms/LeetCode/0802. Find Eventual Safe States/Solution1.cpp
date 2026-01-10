#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<vector<int>> adjRev(V);
        vector<int> outdegree(V, 0);

        for (int node = 0; node < V; node++)
        {
            for (int adjNode : graph[node])
            {
                adjRev[adjNode].push_back(node);
                outdegree[node]++;
            }
        }

        queue<int> que;

        for (int node = 0; node < V; node++)
        {
            if (outdegree[node] == 0)
                que.push(node);
        }

        vector<int> result;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            result.push_back(node);

            for (int adjNode : adjRev[node])
            {
                outdegree[adjNode]--;

                if (outdegree[adjNode] == 0)
                    que.push(adjNode);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};