#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> inDegree(n, 0);
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            inDegree[v]++;
        }
        int champion = 0;
        int championCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                champion = i;
                championCount++;
                ;
            }
        }
        return championCount == 1 ? champion : -1;
    }
};