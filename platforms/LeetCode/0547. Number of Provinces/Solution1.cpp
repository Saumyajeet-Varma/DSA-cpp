#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, int n, vector<vector<int>> &adjMat, vector<int> &vis)
    {
        vis[node] = 1;

        for (int nbr = 0; nbr < n; nbr++)
        {
            if (adjMat[node][nbr] && !vis[nbr])
                dfs(nbr, n, adjMat, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        if (n == 1)
            return 1;

        int count = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, n, isConnected, vis);
                count++;
            }
        }

        return count;
    }
};