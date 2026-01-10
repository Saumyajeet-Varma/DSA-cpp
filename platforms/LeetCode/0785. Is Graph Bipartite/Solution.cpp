#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int color, vector<int> &colors, vector<vector<int>> &graph)
    {
        colors[node] = color;

        for (auto adjNode : graph[node])
        {
            if (colors[adjNode] == -1)
            {
                if (!dfs(adjNode, !color, colors, graph))
                    return false;
            }
            else if (colors[adjNode] == color)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        if (n < 3)
            return true;

        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1 && !dfs(i, 0, colors, graph))
                return false;
        }

        return true;
    }
};