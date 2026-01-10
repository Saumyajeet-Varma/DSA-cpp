#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<int> nodeDist(n);

        for (auto edge : edges)
        {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        for (int i = 0; i < n; i++)
        {
            queue<int> que;
            vector<int> dist(n);

            que.push(i);
            dist[i] = 1;

            int maxDist = 1;
            int node = i;

            while (!que.empty())
            {
                int currNode = que.front();
                que.pop();

                node = min(node, currNode);

                for (int adjNode : adjList[currNode])
                {
                    if (dist[adjNode] == 0)
                    {
                        dist[adjNode] = dist[currNode] + 1;
                        maxDist = max(maxDist, dist[adjNode]);
                        que.push(adjNode);
                    }
                    else if (abs(dist[adjNode] - dist[currNode]) != 1)
                    {
                        return -1;
                    }
                }
            }

            nodeDist[node] = max(nodeDist[node], maxDist);
        }

        int maxGroups = 0;
        for (int i = 0; i < n; i++)
        {
            maxGroups += nodeDist[i];
        }

        return maxGroups;
    }
};