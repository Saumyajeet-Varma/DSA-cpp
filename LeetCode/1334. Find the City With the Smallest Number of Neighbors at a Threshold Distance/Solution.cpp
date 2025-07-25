#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int city = -1;
        int count = n;

        for (int i = 0; i < n; i++)
        {
            int temp = 0;

            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                    temp++;
            }

            if (temp <= count)
            {
                count = temp;
                city = i;
            }
        }

        return city;
    }
};